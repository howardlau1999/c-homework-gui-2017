# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'main.ui'
#
# Created by: PyQt5 UI code generator 5.9
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(750, 1000)
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        MainWindow.setFont(font)
        MainWindow.setLocale(QtCore.QLocale(QtCore.QLocale.English, QtCore.QLocale.UnitedStates))
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setMinimumSize(QtCore.QSize(0, 645))
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout = QtWidgets.QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName("gridLayout")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setMaximumSize(QtCore.QSize(16777215, 30))
        self.label_2.setObjectName("label_2")
        self.gridLayout.addWidget(self.label_2, 0, 0, 1, 1)
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setObjectName("label_6")
        self.gridLayout.addWidget(self.label_6, 3, 0, 1, 1)
        self.txtDesc = QtWidgets.QTextBrowser(self.centralwidget)
        self.txtDesc.setObjectName("txtDesc")
        self.gridLayout.addWidget(self.txtDesc, 4, 0, 1, 1)
        self.treeView = QtWidgets.QTreeView(self.centralwidget)
        self.treeView.setMinimumSize(QtCore.QSize(271, 0))
        self.treeView.setMaximumSize(QtCore.QSize(16777215, 16777215))
        self.treeView.setEditTriggers(QtWidgets.QAbstractItemView.NoEditTriggers)
        self.treeView.setObjectName("treeView")
        self.gridLayout.addWidget(self.treeView, 1, 0, 1, 1)
        self.txtMainCode = Qsci.QsciScintilla(self.centralwidget)
        self.txtMainCode.setToolTip("")
        self.txtMainCode.setWhatsThis("")
        self.txtMainCode.setObjectName("txtMainCode")
        self.gridLayout.addWidget(self.txtMainCode, 8, 0, 1, 1)
        self.btnGetHomework = QtWidgets.QPushButton(self.centralwidget)
        self.btnGetHomework.setObjectName("btnGetHomework")
        self.gridLayout.addWidget(self.btnGetHomework, 2, 0, 1, 1)
        self.label_5 = QtWidgets.QLabel(self.centralwidget)
        self.label_5.setObjectName("label_5")
        self.gridLayout.addWidget(self.label_5, 7, 0, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 750, 30))
        self.menubar.setObjectName("menubar")
        self.menu = QtWidgets.QMenu(self.menubar)
        self.menu.setObjectName("menu")
        self.menu_2 = QtWidgets.QMenu(self.menubar)
        self.menu_2.setObjectName("menu_2")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setEnabled(True)
        self.statusbar.setStatusTip("")
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionUser = QtWidgets.QAction(MainWindow)
        self.actionUser.setObjectName("actionUser")
        self.actionDownload = QtWidgets.QAction(MainWindow)
        self.actionDownload.setObjectName("actionDownload")
        self.action_2 = QtWidgets.QAction(MainWindow)
        self.action_2.setObjectName("action_2")
        self.menu.addAction(self.actionUser)
        self.menu_2.addAction(self.actionDownload)
        self.menubar.addAction(self.menu.menuAction())
        self.menubar.addAction(self.menu_2.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "中山大学程序设计课作业"))
        self.label_2.setText(_translate("MainWindow", "作业列表："))
        self.label_6.setText(_translate("MainWindow", "题目描述"))
        self.btnGetHomework.setText(_translate("MainWindow", "刷新作业列表"))
        self.label_5.setText(_translate("MainWindow", "主程序代码："))
        self.menu.setTitle(_translate("MainWindow", "配置"))
        self.menu_2.setTitle(_translate("MainWindow", "功能"))
        self.actionUser.setText(_translate("MainWindow", "用户配置"))
        self.actionDownload.setText(_translate("MainWindow", "下载格式评分"))
        self.action_2.setText(_translate("MainWindow", "下载格式评分"))

from PyQt5 import Qsci
