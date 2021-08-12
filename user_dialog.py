# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'user_dialog.ui'
#
# Created by: PyQt5 UI code generator 5.9
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_UserDialog(object):
    def setupUi(self, UserDialog):
        UserDialog.setObjectName("UserDialog")
        UserDialog.setWindowModality(QtCore.Qt.ApplicationModal)
        UserDialog.resize(554, 236)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(UserDialog.sizePolicy().hasHeightForWidth())
        UserDialog.setSizePolicy(sizePolicy)
        UserDialog.setMinimumSize(QtCore.QSize(554, 236))
        UserDialog.setMaximumSize(QtCore.QSize(554, 236))
        font = QtGui.QFont()
        font.setFamily("微软雅黑")
        font.setPointSize(9)
        UserDialog.setFont(font)
        UserDialog.setModal(False)
        self.formLayoutWidget = QtWidgets.QWidget(UserDialog)
        self.formLayoutWidget.setGeometry(QtCore.QRect(80, 40, 401, 96))
        self.formLayoutWidget.setObjectName("formLayoutWidget")
        self.formLayout = QtWidgets.QFormLayout(self.formLayoutWidget)
        self.formLayout.setContentsMargins(0, 0, 0, 0)
        self.formLayout.setHorizontalSpacing(15)
        self.formLayout.setVerticalSpacing(20)
        self.formLayout.setObjectName("formLayout")
        self.label = QtWidgets.QLabel(self.formLayoutWidget)
        self.label.setObjectName("label")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.label)
        self.txtUsername = QtWidgets.QLineEdit(self.formLayoutWidget)
        self.txtUsername.setInputMethodHints(QtCore.Qt.ImhLatinOnly)
        self.txtUsername.setObjectName("txtUsername")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.txtUsername)
        self.label_2 = QtWidgets.QLabel(self.formLayoutWidget)
        self.label_2.setObjectName("label_2")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.label_2)
        self.txtPassword = QtWidgets.QLineEdit(self.formLayoutWidget)
        self.txtPassword.setInputMask("")
        self.txtPassword.setEchoMode(QtWidgets.QLineEdit.Password)
        self.txtPassword.setClearButtonEnabled(False)
        self.txtPassword.setObjectName("txtPassword")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.txtPassword)
        self.horizontalLayoutWidget = QtWidgets.QWidget(UserDialog)
        self.horizontalLayoutWidget.setGeometry(QtCore.QRect(80, 140, 401, 51))
        self.horizontalLayoutWidget.setObjectName("horizontalLayoutWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.horizontalLayoutWidget)
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.btnOK = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.btnOK.setObjectName("btnOK")
        self.horizontalLayout.addWidget(self.btnOK)
        self.btnCancel = QtWidgets.QPushButton(self.horizontalLayoutWidget)
        self.btnCancel.setObjectName("btnCancel")
        self.horizontalLayout.addWidget(self.btnCancel)

        self.retranslateUi(UserDialog)
        QtCore.QMetaObject.connectSlotsByName(UserDialog)

    def retranslateUi(self, UserDialog):
        _translate = QtCore.QCoreApplication.translate
        UserDialog.setWindowTitle(_translate("UserDialog", "配置用户"))
        self.label.setText(_translate("UserDialog", "用户名："))
        self.label_2.setText(_translate("UserDialog", "密码："))
        self.btnOK.setText(_translate("UserDialog", "保存"))
        self.btnCancel.setText(_translate("UserDialog", "取消"))

