# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'display.ui'
##
## Created by: Qt User Interface Compiler version 6.2.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide6.QtCore import (QCoreApplication, QDate, QDateTime, QLocale,
    QMetaObject, QObject, QPoint, QRect,
    QSize, QTime, QUrl, Qt)
from PySide6.QtGui import (QBrush, QColor, QConicalGradient, QCursor,
    QFont, QFontDatabase, QGradient, QIcon,
    QImage, QKeySequence, QLinearGradient, QPainter,
    QPalette, QPixmap, QRadialGradient, QTransform)
from PySide6.QtWidgets import (QApplication, QGridLayout, QHBoxLayout, QLabel,
    QLineEdit, QMainWindow, QMenuBar, QPlainTextEdit,
    QPushButton, QScrollArea, QSizePolicy, QStatusBar,
    QTabWidget, QTextEdit, QVBoxLayout, QWidget)

class Ui_Display(object):
    def setupUi(self, Display):
        if not Display.objectName():
            Display.setObjectName(u"Display")
        Display.resize(777, 601)
        self.centralwidget = QWidget(Display)
        self.centralwidget.setObjectName(u"centralwidget")
        self.layoutWidget = QWidget(self.centralwidget)
        self.layoutWidget.setObjectName(u"layoutWidget")
        self.layoutWidget.setGeometry(QRect(10, 0, 726, 323))
        self.gridLayout = QGridLayout(self.layoutWidget)
        self.gridLayout.setSpacing(0)
        self.gridLayout.setObjectName(u"gridLayout")
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout = QHBoxLayout()
        self.horizontalLayout.setSpacing(0)
        self.horizontalLayout.setObjectName(u"horizontalLayout")
        self.mainEditor = QScrollArea(self.layoutWidget)
        self.mainEditor.setObjectName(u"mainEditor")
        self.mainEditor.setAcceptDrops(True)
        self.mainEditor.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        self.mainEditor.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        self.mainEditor.setWidgetResizable(True)
        self.mainEditorW = QWidget()
        self.mainEditorW.setObjectName(u"mainEditorW")
        self.mainEditorW.setGeometry(QRect(0, 0, 500, 57))
        self.mainEditor.setWidget(self.mainEditorW)

        self.horizontalLayout.addWidget(self.mainEditor)


        self.gridLayout.addLayout(self.horizontalLayout, 0, 0, 1, 1)

        self.horizontalLayout_2 = QHBoxLayout()
        self.horizontalLayout_2.setSpacing(0)
        self.horizontalLayout_2.setObjectName(u"horizontalLayout_2")
        self.verticalLayout_4 = QVBoxLayout()
        self.verticalLayout_4.setSpacing(0)
        self.verticalLayout_4.setObjectName(u"verticalLayout_4")
        self.label_2 = QLabel(self.layoutWidget)
        self.label_2.setObjectName(u"label_2")

        self.verticalLayout_4.addWidget(self.label_2)

        self.plainTextEdit = QPlainTextEdit(self.layoutWidget)
        self.plainTextEdit.setObjectName(u"plainTextEdit")
        self.plainTextEdit.setMaximumSize(QSize(16777215, 200))

        self.verticalLayout_4.addWidget(self.plainTextEdit)


        self.horizontalLayout_2.addLayout(self.verticalLayout_4)

        self.verticalLayout_3 = QVBoxLayout()
        self.verticalLayout_3.setSpacing(0)
        self.verticalLayout_3.setObjectName(u"verticalLayout_3")
        self.label_3 = QLabel(self.layoutWidget)
        self.label_3.setObjectName(u"label_3")

        self.verticalLayout_3.addWidget(self.label_3)

        self.lineEdit_2 = QLineEdit(self.layoutWidget)
        self.lineEdit_2.setObjectName(u"lineEdit_2")

        self.verticalLayout_3.addWidget(self.lineEdit_2)

        self.label_4 = QLabel(self.layoutWidget)
        self.label_4.setObjectName(u"label_4")

        self.verticalLayout_3.addWidget(self.label_4)

        self.textEdit = QTextEdit(self.layoutWidget)
        self.textEdit.setObjectName(u"textEdit")

        self.verticalLayout_3.addWidget(self.textEdit)


        self.horizontalLayout_2.addLayout(self.verticalLayout_3)


        self.gridLayout.addLayout(self.horizontalLayout_2, 1, 0, 1, 1)

        self.verticalLayout_2 = QVBoxLayout()
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.horizontalLayout_3 = QHBoxLayout()
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.lineEdit = QLineEdit(self.layoutWidget)
        self.lineEdit.setObjectName(u"lineEdit")

        self.horizontalLayout_3.addWidget(self.lineEdit)

        self.pushButton = QPushButton(self.layoutWidget)
        self.pushButton.setObjectName(u"pushButton")
        self.pushButton.setMaximumSize(QSize(60, 16777215))

        self.horizontalLayout_3.addWidget(self.pushButton)


        self.verticalLayout_2.addLayout(self.horizontalLayout_3)

        self.Objects = QTabWidget(self.layoutWidget)
        self.Objects.setObjectName(u"Objects")
        self.Objects.setStyleSheet(u"")
        self.Variables = QWidget()
        self.Variables.setObjectName(u"Variables")
        self.verticalLayout_14 = QVBoxLayout(self.Variables)
        self.verticalLayout_14.setObjectName(u"verticalLayout_14")
        self.saVariables = QScrollArea(self.Variables)
        self.saVariables.setObjectName(u"saVariables")
        self.saVariables.setWidgetResizable(True)
        self.saVariablesC = QWidget()
        self.saVariablesC.setObjectName(u"saVariablesC")
        self.saVariablesC.setGeometry(QRect(0, 0, 180, 241))
        self.saVariablesCL = QVBoxLayout(self.saVariablesC)
        self.saVariablesCL.setObjectName(u"saVariablesCL")
        self.saVariables.setWidget(self.saVariablesC)

        self.verticalLayout_14.addWidget(self.saVariables)

        self.Objects.addTab(self.Variables, "")
        self.Functions = QWidget()
        self.Functions.setObjectName(u"Functions")
        self.verticalLayout_17 = QVBoxLayout(self.Functions)
        self.verticalLayout_17.setObjectName(u"verticalLayout_17")
        self.saFunctions = QScrollArea(self.Functions)
        self.saFunctions.setObjectName(u"saFunctions")
        self.saFunctions.setWidgetResizable(True)
        self.saFunctionsC = QWidget()
        self.saFunctionsC.setObjectName(u"saFunctionsC")
        self.saFunctionsC.setGeometry(QRect(0, 0, 98, 28))
        self.saFunctionsCL = QVBoxLayout(self.saFunctionsC)
        self.saFunctionsCL.setObjectName(u"saFunctionsCL")
        self.saFunctions.setWidget(self.saFunctionsC)

        self.verticalLayout_17.addWidget(self.saFunctions)

        self.Objects.addTab(self.Functions, "")
        self.Types = QWidget()
        self.Types.setObjectName(u"Types")
        self.verticalLayout_21 = QVBoxLayout(self.Types)
        self.verticalLayout_21.setObjectName(u"verticalLayout_21")
        self.saTypes = QScrollArea(self.Types)
        self.saTypes.setObjectName(u"saTypes")
        self.saTypes.setWidgetResizable(True)
        self.saTypesC = QWidget()
        self.saTypesC.setObjectName(u"saTypesC")
        self.saTypesC.setGeometry(QRect(0, 0, 98, 28))
        self.saTypesCL = QVBoxLayout(self.saTypesC)
        self.saTypesCL.setObjectName(u"saTypesCL")
        self.saTypes.setWidget(self.saTypesC)

        self.verticalLayout_21.addWidget(self.saTypes)

        self.Objects.addTab(self.Types, "")
        self.Operators = QWidget()
        self.Operators.setObjectName(u"Operators")
        self.verticalLayout_23 = QVBoxLayout(self.Operators)
        self.verticalLayout_23.setObjectName(u"verticalLayout_23")
        self.saOperators = QScrollArea(self.Operators)
        self.saOperators.setObjectName(u"saOperators")
        self.saOperators.setWidgetResizable(True)
        self.saOperatorsC = QWidget()
        self.saOperatorsC.setObjectName(u"saOperatorsC")
        self.saOperatorsC.setGeometry(QRect(0, 0, 98, 28))
        self.saOperatorsCL = QVBoxLayout(self.saOperatorsC)
        self.saOperatorsCL.setObjectName(u"saOperatorsCL")
        self.saOperators.setWidget(self.saOperatorsC)

        self.verticalLayout_23.addWidget(self.saOperators)

        self.Objects.addTab(self.Operators, "")
        self.Misc = QWidget()
        self.Misc.setObjectName(u"Misc")
        self.verticalLayout_25 = QVBoxLayout(self.Misc)
        self.verticalLayout_25.setObjectName(u"verticalLayout_25")
        self.saMisc = QScrollArea(self.Misc)
        self.saMisc.setObjectName(u"saMisc")
        self.saMisc.setWidgetResizable(True)
        self.saMiscC = QWidget()
        self.saMiscC.setObjectName(u"saMiscC")
        self.saMiscC.setGeometry(QRect(0, 0, 98, 28))
        self.saMiscCL = QVBoxLayout(self.saMiscC)
        self.saMiscCL.setObjectName(u"saMiscCL")
        self.saMisc.setWidget(self.saMiscC)

        self.verticalLayout_25.addWidget(self.saMisc)

        self.Objects.addTab(self.Misc, "")

        self.verticalLayout_2.addWidget(self.Objects)


        self.gridLayout.addLayout(self.verticalLayout_2, 0, 1, 2, 1)

        Display.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(Display)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 777, 19))
        Display.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(Display)
        self.statusbar.setObjectName(u"statusbar")
        Display.setStatusBar(self.statusbar)

        self.retranslateUi(Display)

        self.Objects.setCurrentIndex(0)


        QMetaObject.connectSlotsByName(Display)
    # setupUi

    def retranslateUi(self, Display):
        Display.setWindowTitle(QCoreApplication.translate("Display", u"Display", None))
        self.label_2.setText(QCoreApplication.translate("Display", u"Output:", None))
        self.label_3.setText(QCoreApplication.translate("Display", u"Current Path:", None))
        self.label_4.setText(QCoreApplication.translate("Display", u"Input:", None))
        self.pushButton.setText(QCoreApplication.translate("Display", u"SEARCH", None))
#if QT_CONFIG(tooltip)
        self.Objects.setToolTip(QCoreApplication.translate("Display", u"<html><head/><body><p><br/></p></body></html>", None))
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        self.Objects.setWhatsThis(QCoreApplication.translate("Display", u"<html><head/><body><p><br/></p></body></html>", None))
#endif // QT_CONFIG(whatsthis)
        self.Objects.setTabText(self.Objects.indexOf(self.Variables), QCoreApplication.translate("Display", u"Variables", None))
        self.Objects.setTabText(self.Objects.indexOf(self.Functions), QCoreApplication.translate("Display", u"Functions", None))
        self.Objects.setTabText(self.Objects.indexOf(self.Types), QCoreApplication.translate("Display", u"Types", None))
        self.Objects.setTabText(self.Objects.indexOf(self.Operators), QCoreApplication.translate("Display", u"Operators", None))
        self.Objects.setTabText(self.Objects.indexOf(self.Misc), QCoreApplication.translate("Display", u"Misc", None))
    # retranslateUi

