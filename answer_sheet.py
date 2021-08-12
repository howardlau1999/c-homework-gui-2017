# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'answer_sheet.ui'
#
# Created by: PyQt5 UI code generator 5.9
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_AnswerSheet(object):
    def setupUi(self, AnswerSheet):
        AnswerSheet.setObjectName("AnswerSheet")
        AnswerSheet.setWindowModality(QtCore.Qt.NonModal)
        AnswerSheet.resize(750, 1000)
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        AnswerSheet.setFont(font)
        self.gridLayout = QtWidgets.QGridLayout(AnswerSheet)
        self.gridLayout.setObjectName("gridLayout")
        self.verticalLayout = QtWidgets.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.label = QtWidgets.QLabel(AnswerSheet)
        self.label.setMaximumSize(QtCore.QSize(16777215, 30))
        self.label.setObjectName("label")
        self.verticalLayout.addWidget(self.label)
        self.txtCode = Qsci.QsciScintilla(AnswerSheet)
        self.txtCode.setToolTip("")
        self.txtCode.setWhatsThis("")
        self.txtCode.setStyleSheet("font: 14pt \"Source Code Pro, Consolas\";")
        self.txtCode.setSizeAdjustPolicy(QtWidgets.QAbstractScrollArea.AdjustToContents)
        self.txtCode.setObjectName("txtCode")
        self.verticalLayout.addWidget(self.txtCode)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.btnLoadC = QtWidgets.QPushButton(AnswerSheet)
        self.btnLoadC.setObjectName("btnLoadC")
        self.horizontalLayout.addWidget(self.btnLoadC)
        self.btnLoadCPP = QtWidgets.QPushButton(AnswerSheet)
        self.btnLoadCPP.setObjectName("btnLoadCPP")
        self.horizontalLayout.addWidget(self.btnLoadCPP)
        self.btnLoadLocal = QtWidgets.QPushButton(AnswerSheet)
        self.btnLoadLocal.setObjectName("btnLoadLocal")
        self.horizontalLayout.addWidget(self.btnLoadLocal)
        self.verticalLayout.addLayout(self.horizontalLayout)
        self.label_3 = QtWidgets.QLabel(AnswerSheet)
        self.label_3.setMaximumSize(QtCore.QSize(16777215, 30))
        self.label_3.setObjectName("label_3")
        self.verticalLayout.addWidget(self.label_3)
        self.txtInputData = QtWidgets.QTextEdit(AnswerSheet)
        self.txtInputData.setMaximumSize(QtCore.QSize(16777215, 163))
        font = QtGui.QFont()
        font.setFamily("Source Code Pro, Consolas")
        font.setPointSize(9)
        font.setBold(False)
        font.setItalic(False)
        font.setWeight(50)
        self.txtInputData.setFont(font)
        self.txtInputData.setStyleSheet("font: 9pt \"Source Code Pro, Consolas\";")
        self.txtInputData.setObjectName("txtInputData")
        self.verticalLayout.addWidget(self.txtInputData)
        self.btnSubmit = QtWidgets.QPushButton(AnswerSheet)
        self.btnSubmit.setEnabled(False)
        self.btnSubmit.setObjectName("btnSubmit")
        self.verticalLayout.addWidget(self.btnSubmit)
        self.label_4 = QtWidgets.QLabel(AnswerSheet)
        self.label_4.setMaximumSize(QtCore.QSize(16777215, 30))
        self.label_4.setObjectName("label_4")
        self.verticalLayout.addWidget(self.label_4)
        self.txtServerOutput = QtWidgets.QTextEdit(AnswerSheet)
        self.txtServerOutput.setMaximumSize(QtCore.QSize(16777215, 173))
        self.txtServerOutput.setStyleSheet("font: 9pt \"Source Code Pro, Consolas\";")
        self.txtServerOutput.setObjectName("txtServerOutput")
        self.verticalLayout.addWidget(self.txtServerOutput)
        self.gridLayout.addLayout(self.verticalLayout, 0, 0, 1, 1)

        self.retranslateUi(AnswerSheet)
        QtCore.QMetaObject.connectSlotsByName(AnswerSheet)

    def retranslateUi(self, AnswerSheet):
        _translate = QtCore.QCoreApplication.translate
        AnswerSheet.setWindowTitle(_translate("AnswerSheet", "答案提交"))
        self.label.setText(_translate("AnswerSheet", "代码编辑区："))
        self.btnLoadC.setText(_translate("AnswerSheet", "加载 C 主程序模板"))
        self.btnLoadCPP.setText(_translate("AnswerSheet", "加载 C++ 主程序模板"))
        self.btnLoadLocal.setText(_translate("AnswerSheet", "加载本地作业文件"))
        self.label_3.setText(_translate("AnswerSheet", "测试数据："))
        self.btnSubmit.setText(_translate("AnswerSheet", "保存并测试"))
        self.label_4.setText(_translate("AnswerSheet", "服务器返回结果："))

from PyQt5 import Qsci
