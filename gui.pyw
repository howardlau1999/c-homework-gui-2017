#! python3
# -*- coding: utf-8 -*-

"""
written by howard lau on 2017/10/3

tested on Windows 10 with Python 3.5.2

install requirement first!

please write changelog if you have modified the code.

changelog:

2017/10/3 initial release | howard lau
2017/10/10 fixed some bugs | howard lau
2017/10/12 add templates function | howard lau
2017/10/12 add local homework saver | howard lau
2017/10/19 add updater | howard lau
2017/10/20 optimize display of desc | howard lau
2017/10/22 automatically copy input data | howard lau 
2017/10/27 add download html from server | howard lau
2017/12/14 minor bug fix
"""
import sys, math, cli, re
import os, sys, argparse, json, time, socket
import config_manager, local_homework
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.Qsci import *
from threading import *


from main import Ui_MainWindow
from user_dialog import Ui_UserDialog
from answer_sheet import Ui_AnswerSheet
from updater import Updater

def prepareCodeEditor(codeEditor):
    codeEditor.setUtf8(True) # enable UTF-8 to avoid coding problems
    codeEditor.setTabWidth(4)
    
    codeFont = QFont()
    codeFont.setFamily("Consolas, 'Source Code Pro', 'Ubuntu Mono Regular'")
    codeFont.setPointSize(11)

    lexer = QsciLexerCPP()
    lexer.setAutoIndentStyle(QsciScintilla.AiMaintain)
    lexer.setFont(codeFont)
    codeEditor.setLexer(lexer)

    codeEditor.setMarginWidth(0, codeFont.pointSize() * (int(math.log10(codeEditor.lines())) + 1) + 8)
    codeEditor.linesChanged.connect(lambda : codeEditor.setMarginWidth(0, (codeFont.pointSize() + codeFont.letterSpacing() + 2) * (int(math.log10(codeEditor.lines())) + 1) + 8))
    codeEditor.setMarginsFont(codeFont)
    codeEditor.setMarginLineNumbers(0, True)

def initTreeView(view):
    view.setSelectionBehavior(QAbstractItemView.SelectRows)
    model = QStandardItemModel()
    if view.model() is not None:
        model = view.model()
        model.clear()
    model.setHorizontalHeaderLabels(['作业名称', '状态', '评分', '评语'])
    view.setModel(model)
    view.setUniformRowHeights(True)


def updateHomeworkDetail(ui, hwname):
    def extractExampleInput(desc):
        exp = re.compile(r'<[biu]><[biu]>EXAMPLE INPUT[ 1-9]*?</[biu]></[biu]>\n*<pre>\n(.*?)</pre>', re.DOTALL)
        result = re.search(exp, desc)
        print(result)
        if result is not None:
            return result.group(1)
        else:
            return ''

    def extractExampleOutput(desc):
        pass

    if hasattr(ui, "currentHWID"):
        ui.homeworkData[ui.currentHWID]['answer'] = ui.answerSheet.txtCode.text()

    hwid = hwname.split(' ')[0]
    hw = ui.homeworkData[hwid]

    html = re.sub(r"\n\n+", "<br>", hw['description'])
    html = re.sub(r"\<([^a-zA-Z]){1}\>", r"&lt;\1&gt;", html)
    ui.txtDesc.setText('')
    ui.txtDesc.insertHtml(html)
    ui.txtMainCode.setText(hw['main'])
    ui.txtMainCode.setReadOnly(True)
    ui.currentHWID = hwid
    
    if 'answer' in hw:
        ui.answerSheet.txtCode.setText(hw['answer'])
    else:
        ui.answerSheet.txtCode.setText('')

    ui.answerSheet.btnSubmit.setEnabled(True)
    ui.answerSheet.txtServerOutput.setText(hw.get('output', ''))
    ui.answerSheet.txtInputData.setText(hw.get('input', extractExampleInput(hw['description'])))
    ui.answerSheet.txtCode.setReadOnly(hw['deadline'])
    ui.answerSheet.btnLoadC.setEnabled(not hw['deadline'])
    ui.answerSheet.btnLoadCPP.setEnabled(not hw['deadline'])
    ui.answerSheet.btnLoadLocal.setEnabled(not hw['deadline'])
    ui.sheet_widget.show()
    pass

def updateHomeworkList(ui, reply):
    btn = ui.btnGetHomework
    view = ui.treeView
    
    def doubleClickItem(index):
        p = model.itemFromIndex(index).parent()

        if p is None:
            return
        ui.currentHWIndexRow = index.row();
        ui.currentHWParent = p;
        updateHomeworkDetail(ui, p.child(index.row()).text())

    try:
        view.doubleClicked.disconnect()
    except:
        pass

    view.doubleClicked.connect(doubleClickItem)
    
    if 'error' not in reply:
        del reply['reply']
        ui.homeworkData = reply

        initTreeView(view)
        model = view.model()
        normalParent = QStandardItem('进行中')
        endedParent = QStandardItem('已截止')
    

        problem_ids = list(reply.keys())
        def get_id(problem_id):
            problem_id = problem_id.split('.')
            return 1000 * int(problem_id[0]) + int(problem_id[1])
        problem_ids.sort(key = lambda id : get_id(id))
        
        for hwid in problem_ids:
            hw = reply[hwid]
            if hw['canceled']: continue
            name = QStandardItem(hw['id'] + ' ' + hw['title'])
            status = ''
            score = QStandardItem("")
            comment = QStandardItem(hw.get("comment", ""))
            if hw['deadline']:
                status = "待评分"
                if 'score' in hw:
                    status = "已评分"
                    score = QStandardItem(str(hw['score']))

                status = QStandardItem(status)
                
                endedParent.appendRow([name, status, score, comment])
            else:
                if 'answer' in hw:
                    status = "已提交"
                else:
                    status = "未提交"

                status = QStandardItem(status)
                normalParent.appendRow([name, status, score, comment])
        model.appendRow(normalParent)
        model.appendRow(endedParent)
        view.setModel(model)

        
        view.header().setSectionResizeMode(0, QHeaderView.ResizeToContents)
        view.header().setSectionResizeMode(3, QHeaderView.ResizeToContents)
        ui.statusbar.showMessage("刷新完成")
    else:
        ui.statusbar.showMessage(reply['error'], 5000)
    btn.setEnabled(True)


def prepareButtonsMain(ui):
    ui.actionUser.triggered.connect(lambda : showUserDialog(ui))
    ui.actionDownload.triggered.connect(lambda : downloadFormatScore(ui))

    def confirmLoad(template):
        if ui.answerSheet.txtCode.text() != "":
            msgbox = QMessageBox()
            msgbox.setIcon(QMessageBox.Question)
            msgbox.setText("当前代码将丢失，确认加载吗？此操作无法撤回。")
            msgbox.setWindowTitle("确认加载内容")
            msgbox.setStandardButtons(QMessageBox.Yes | QMessageBox.Cancel)
            retval = msgbox.exec_()
            if retval != QMessageBox.Yes:
                return
        ui.answerSheet.txtCode.setText(template)

    def loadLocal(hwid):
        ans = loadLocalHomework(hwid)
        if ans == -1:
            msgbox = QMessageBox()
            msgbox.setIcon(QMessageBox.Critical)
            msgbox.setText("没有找到文件，确认 homework/%s.txt 存在吗？" % hwid)
            msgbox.setWindowTitle("加载失败")
            msgbox.setStandardButtons(QMessageBox.Ok)
            retval = msgbox.exec_()
            return
        confirmLoad(ans)

    def loadTemplate(template_name):
        confirmLoad(ui.templates[template_name])

    def refreshHomework():
        ui.hwThread = HomeworkThread(ui.config['user'])
        ui.hwThread.finish.connect(lambda reply: updateHomeworkList(ui, reply))

        def errorHomework():
            ui.btnGetHomework.setEnabled(True)
            ui.statusbar.showMessage("发生网络错误。用户名和密码是否正确？", 5000)

        ui.hwThread.error.connect(errorHomework)

        ui.statusbar.showMessage("正在刷新作业列表...")
        btn = ui.btnGetHomework
        btn.setEnabled(False)

        ui.hwThread.start()

    def submitHomework():
        code = ui.answerSheet.txtCode.text()
        input = ui.answerSheet.txtInputData.toPlainText()
        id = ui.currentHWID
        ui.submitThread = SubmitThread(ui.config['user'], code, input, id)
        ui.homeworkData[id]['answer'] = code
        ui.homeworkData[id]['input'] = input

        ui.answerSheet.btnSubmit.setEnabled(False)
        ui.submitThread.start()
        ui.answerSheet.txtServerOutput.setPlainText("正在提交作业...等待服务器返回结果...")

        def okSubmit(reply):
            ui.answerSheet.btnSubmit.setEnabled(True)
            ui.answerSheet.txtServerOutput.setPlainText(reply)
            ui.homeworkData[id]['output'] = reply

            if ui.homeworkData[ui.currentHWID]['deadline']:
                return
            else:
                saveHomeworkToLocal(ui, ui.currentHWID)
                ui.currentHWParent.setChild(ui.currentHWIndexRow, 1, QStandardItem('已提交'))
        def errSubmit():
            ui.answerSheet.btnSubmit.setEnabled(True)
            ui.answerSheet.txtServerOutput.setPlainText("发生了网络错误。")

        ui.submitThread.finish.connect(okSubmit)
        ui.submitThread.error.connect(errSubmit)
        ui.submitThread.start()

    ui.btnGetHomework.clicked.connect(refreshHomework)

    ui.answerSheet.btnSubmit.clicked.connect(submitHomework)
    ui.answerSheet.btnLoadC.clicked.connect(lambda : loadTemplate("C Main"))
    ui.answerSheet.btnLoadCPP.clicked.connect(lambda : loadTemplate("C++ Main"))
    ui.answerSheet.btnLoadLocal.clicked.connect(lambda : loadLocal(ui.currentHWID))

    ui.user.btnCancel.clicked.connect(lambda : ui.user_dialog.done(0))
    ui.user.btnOK.clicked.connect(lambda : saveUserConfig(ui))
    pass

def showAutoSubmit(ui):
    pass

def showMessageBox(title, message, icon):
    msgbox = QMessageBox()
    msgbox.setIcon(icon)
    msgbox.setText(message)
    msgbox.setWindowTitle(title)
    msgbox.setStandardButtons(QMessageBox.Ok)
    return msgbox.exec_()

def downloadFormatScore(ui):
    ui.downloadThread = DownloadThread(ui.config['user'])
    ui.downloadThread.start()

def saveHomeworkToLocal(ui, hwid = None):
    if not hasattr(ui, 'homeworkData'):
        return
    local_homework.saveHomeworkData(ui.homeworkData, hwid)

def loadLocalHomework(hwid):
    return local_homework.loadSingleHomework(hwid)

def showUserDialog(ui):
    prepareUserConfig(ui)
    dialog = ui.user
    dialog.txtUsername.setText(ui.config["user"]["user"])
    dialog.txtPassword.setText(ui.config["user"]["password"])
    ui.user_dialog.open()
    
def saveUserConfig(ui):
    dialog = ui.user
    user = {}
    user["user"] = dialog.txtUsername.text()
    user['password'] = dialog.txtPassword.text()
    
    ui.config = {"user" : user}
    config_manager.saveConfig(ui.config)
    ui.user_dialog.done(0)

def prepareUserConfig(ui):
    user = {}
    user['user'] = ""
    user['password'] = ""

    ui.config = {"user" : user}
    localConfig = config_manager.loadConfig()

    if localConfig is None:
        config_manager.saveConfig(ui.config)
    else:
        ui.config = localConfig

def prepareTemplates(ui):
    templates_fn = "templates.json"
    templates = open(templates_fn, "r")
    ui.templates = json.loads(templates.read())
    templates.close()

def updateProgram(ui):
    ui.updateThread = UpdaterThread()
    ui.updateThread.begin.connect(lambda : ui.statusbar.showMessage("开始检查更新...", 5000))
    ui.updateThread.finish.connect(lambda x : ui.statusbar.showMessage("检查更新完成。共更新了 %d 个文件。" % x, 5000))
    ui.updateThread.error.connect(lambda : ui.statusbar.showMessage("更新出错，即将重试...", 5000))
    ui.updateThread.fail.connect(lambda : ui.statusbar.showMessage("更新失败。",  10000))
    ui.updateThread.start()

def main():
    app = QApplication(sys.argv)
    QApplication.setStyle(QStyleFactory.create('Fusion'))
    
    window = QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(window)

    sheet = Ui_AnswerSheet()
    ui.sheet_widget = QWidget()
    ui.sheet_widget.setWindowFlags(Qt.Sheet)
    sheet.setupUi(ui.sheet_widget)

    ui.answerSheet = sheet
    ui.user = Ui_UserDialog()
    ui.user_dialog = QDialog(window)
    ui.user.setupUi(ui.user_dialog)
    
    initTreeView(ui.treeView)

    prepareCodeEditor(sheet.txtCode)
    prepareCodeEditor(ui.txtMainCode)
    prepareTemplates(ui)
    prepareButtonsMain(ui)
    prepareUserConfig(ui)
    updateProgram(ui)
    
    ui.sheet_widget.move(1000, 100)
    window.move(100, 100)
    window.show()

    app.exec_()

    saveHomeworkToLocal(ui)

class UpdaterThread(QThread):
    begin = pyqtSignal()
    error = pyqtSignal()
    finish = pyqtSignal(int)
    fail = pyqtSignal()
    times = 3

    def __init__(self):
        super(UpdaterThread, self).__init__()

    def run(self):
        time.sleep(3)
        self.update()

    def update(self):
        try:
            u = Updater()
            self.begin.emit()
            count = u.update()
            self.finish.emit(count)
        except:
            self.error.emit()
            self.times = self.times - 1
            if self.times == 0:
                self.fail.emit()
                return
            self.retry()

    def retry(self):
        time.sleep(5)
        self.update()

class DownloadThread(QThread):
    finish = pyqtSignal(dict)
    error = pyqtSignal()

    def __init__(self, user):
        super(DownloadThread, self).__init__()
        self.user = user

    def run(self):
        args = self.user
        try:
            result = cli.download(self.user)
            filename = result.get('filename')
            if filename:
                # convert encodings
                try:
                    f = open(filename, "rb+")
                    content = f.read().decode("gb2312").encode("utf-8")
                    f.seek(0)
                    f.write(content)
                    f.close()
                except:
                    showMessageBox("发生错误", "转换编码时发生了错误。但文件已保存为 %s" % filename, QMessageBox.Critical)
                    return
                QDesktopServices.openUrl(QUrl('file:///' + os.getcwd() + '/%s' % filename));
            else:
                showMessageBox("发生错误", result.get('error'), QMessageBox.Critical)
        except:
            self.error.emit()
            return

class HomeworkThread(QThread):
    finish = pyqtSignal(dict)
    error = pyqtSignal()

    def __init__(self, user):
        super(HomeworkThread, self).__init__()
        self.user = user

    def run(self):
        args = self.user
        args["info"] = True
        try:
            reply = cli.homework_info(args)
            self.finish.emit(reply)
        except:
            self.error.emit()
            return

class SubmitThread(QThread):
    finish = pyqtSignal(str)
    error = pyqtSignal()

    def __init__(self, user, code, input, problem_id):
        super(SubmitThread, self).__init__()
        self.user = user
        self.code = code
        self.input = input
        self.problem_id = problem_id

    def run(self):
        args = self.user
        args['file'] = self.code
        args['input'] = self.input
        args['problem_id'] = self.problem_id

        
        try:
            reply = cli.save_homework(args)
            self.finish.emit(reply)
        except:
            self.error.emit()
            return


if __name__ == '__main__':
    main()