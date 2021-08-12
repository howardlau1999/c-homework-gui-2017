# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'auto_submit.ui'
#
# Created by: PyQt5 UI code generator 5.9
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_AutoSubmit(object):
    def setupUi(self, AutoSubmit):
        AutoSubmit.setObjectName("AutoSubmit")
        AutoSubmit.resize(621, 526)
        self.gridLayout = QtWidgets.QGridLayout(AutoSubmit)
        self.gridLayout.setObjectName("gridLayout")
        self.label = QtWidgets.QLabel(AutoSubmit)
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 0, 0, 1, 1)
        self.lstSubmit = QtWidgets.QListWidget(AutoSubmit)
        self.lstSubmit.setObjectName("lstSubmit")
        self.gridLayout.addWidget(self.lstSubmit, 1, 0, 1, 1)
        self.btnSubmit = QtWidgets.QPushButton(AutoSubmit)
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        self.btnSubmit.setFont(font)
        self.btnSubmit.setFocusPolicy(QtCore.Qt.NoFocus)
        self.btnSubmit.setObjectName("btnSubmit")
        self.gridLayout.addWidget(self.btnSubmit, 2, 0, 1, 1)

        self.retranslateUi(AutoSubmit)
        QtCore.QMetaObject.connectSlotsByName(AutoSubmit)

    def retranslateUi(self, AutoSubmit):
        _translate = QtCore.QCoreApplication.translate
        AutoSubmit.setWindowTitle(_translate("AutoSubmit", "自动提交"))
        self.label.setText(_translate("AutoSubmit", "自动提交与服务器不同的本地作业："))
        self.btnSubmit.setText(_translate("AutoSubmit", "开始提交"))

