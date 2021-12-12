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
from PySide6.QtWidgets import (QApplication, QGridLayout, QGroupBox, QHBoxLayout,
    QLabel, QLineEdit, QMainWindow, QMenuBar,
    QPlainTextEdit, QPushButton, QScrollArea, QSizePolicy,
    QStackedWidget, QStatusBar, QTabWidget, QTextEdit,
    QVBoxLayout, QWidget)

class Ui_Display(object):
    def setupUi(self, Display):
        if not Display.objectName():
            Display.setObjectName(u"Display")
        Display.resize(777, 601)
        self.centralwidget = QWidget(Display)
        self.centralwidget.setObjectName(u"centralwidget")
        self.layoutWidget = QWidget(self.centralwidget)
        self.layoutWidget.setObjectName(u"layoutWidget")
        self.layoutWidget.setGeometry(QRect(10, 0, 726, 320))
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
        self.scrollAreaWidgetContents = QWidget()
        self.scrollAreaWidgetContents.setObjectName(u"scrollAreaWidgetContents")
        self.scrollAreaWidgetContents.setGeometry(QRect(0, 0, 500, 54))
        self.label = QLabel(self.scrollAreaWidgetContents)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(10, -10, 861, 101))
        self.label_9 = QLabel(self.scrollAreaWidgetContents)
        self.label_9.setObjectName(u"label_9")
        self.label_9.setGeometry(QRect(290, 40, 861, 101))
        self.mainEditor.setWidget(self.scrollAreaWidgetContents)

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
        self.saVariablesC.setGeometry(QRect(0, 0, 180, 238))
        self.verticalLayout_15 = QVBoxLayout(self.saVariablesC)
        self.verticalLayout_15.setObjectName(u"verticalLayout_15")
        self.label_7 = QLabel(self.saVariablesC)
        self.label_7.setObjectName(u"label_7")

        self.verticalLayout_15.addWidget(self.label_7)

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
        self.saFunctionsC.setGeometry(QRect(0, 0, 180, 238))
        self.verticalLayout_16 = QVBoxLayout(self.saFunctionsC)
        self.verticalLayout_16.setObjectName(u"verticalLayout_16")
        self.label_8 = QLabel(self.saFunctionsC)
        self.label_8.setObjectName(u"label_8")

        self.verticalLayout_16.addWidget(self.label_8)

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
        self.saTypesC.setGeometry(QRect(0, 0, 180, 238))
        self.verticalLayout_20 = QVBoxLayout(self.saTypesC)
        self.verticalLayout_20.setObjectName(u"verticalLayout_20")
        self.label_14 = QLabel(self.saTypesC)
        self.label_14.setObjectName(u"label_14")

        self.verticalLayout_20.addWidget(self.label_14)

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
        self.saOperatorsC.setGeometry(QRect(0, 0, 180, 238))
        self.verticalLayout_22 = QVBoxLayout(self.saOperatorsC)
        self.verticalLayout_22.setObjectName(u"verticalLayout_22")
        self.label_15 = QLabel(self.saOperatorsC)
        self.label_15.setObjectName(u"label_15")

        self.verticalLayout_22.addWidget(self.label_15)

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
        self.saMiscC.setGeometry(QRect(0, 0, 180, 238))
        self.verticalLayout_24 = QVBoxLayout(self.saMiscC)
        self.verticalLayout_24.setObjectName(u"verticalLayout_24")
        self.label_16 = QLabel(self.saMiscC)
        self.label_16.setObjectName(u"label_16")

        self.verticalLayout_24.addWidget(self.label_16)

        self.saMisc.setWidget(self.saMiscC)

        self.verticalLayout_25.addWidget(self.saMisc)

        self.Objects.addTab(self.Misc, "")

        self.verticalLayout_2.addWidget(self.Objects)


        self.gridLayout.addLayout(self.verticalLayout_2, 0, 1, 2, 1)

        self.scrollArea_3 = QScrollArea(self.centralwidget)
        self.scrollArea_3.setObjectName(u"scrollArea_3")
        self.scrollArea_3.setGeometry(QRect(600, 400, 98, 118))
        self.scrollArea_3.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        self.scrollArea_3.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        self.scrollArea_3.setWidgetResizable(True)
        self.scrollAreaWidgetContents_3 = QWidget()
        self.scrollAreaWidgetContents_3.setObjectName(u"scrollAreaWidgetContents_3")
        self.scrollAreaWidgetContents_3.setGeometry(QRect(0, 0, 82, 102))
        self.verticalLayout = QVBoxLayout(self.scrollAreaWidgetContents_3)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.verticalLayout_10 = QVBoxLayout()
        self.verticalLayout_10.setObjectName(u"verticalLayout_10")
        self.Variables_2 = QVBoxLayout()
        self.Variables_2.setObjectName(u"Variables_2")
        self.label_10 = QLabel(self.scrollAreaWidgetContents_3)
        self.label_10.setObjectName(u"label_10")

        self.Variables_2.addWidget(self.label_10)


        self.verticalLayout_10.addLayout(self.Variables_2)

        self.verticalLayout_11 = QVBoxLayout()
        self.verticalLayout_11.setObjectName(u"verticalLayout_11")
        self.label_11 = QLabel(self.scrollAreaWidgetContents_3)
        self.label_11.setObjectName(u"label_11")

        self.verticalLayout_11.addWidget(self.label_11)


        self.verticalLayout_10.addLayout(self.verticalLayout_11)

        self.verticalLayout_12 = QVBoxLayout()
        self.verticalLayout_12.setObjectName(u"verticalLayout_12")
        self.label_12 = QLabel(self.scrollAreaWidgetContents_3)
        self.label_12.setObjectName(u"label_12")

        self.verticalLayout_12.addWidget(self.label_12)


        self.verticalLayout_10.addLayout(self.verticalLayout_12)

        self.verticalLayout_13 = QVBoxLayout()
        self.verticalLayout_13.setObjectName(u"verticalLayout_13")
        self.label_13 = QLabel(self.scrollAreaWidgetContents_3)
        self.label_13.setObjectName(u"label_13")

        self.verticalLayout_13.addWidget(self.label_13)


        self.verticalLayout_10.addLayout(self.verticalLayout_13)


        self.verticalLayout.addLayout(self.verticalLayout_10)

        self.scrollArea_3.setWidget(self.scrollAreaWidgetContents_3)
        self.stackedWidget = QStackedWidget(self.centralwidget)
        self.stackedWidget.setObjectName(u"stackedWidget")
        self.stackedWidget.setGeometry(QRect(390, 390, 120, 80))
        self.page = QWidget()
        self.page.setObjectName(u"page")
        self.stackedWidget.addWidget(self.page)
        self.page_2 = QWidget()
        self.page_2.setObjectName(u"page_2")
        self.stackedWidget.addWidget(self.page_2)
        self.scrollArea_4 = QScrollArea(self.centralwidget)
        self.scrollArea_4.setObjectName(u"scrollArea_4")
        self.scrollArea_4.setGeometry(QRect(340, 380, 193, 286))
        self.scrollArea_4.setWidgetResizable(True)
        self.scrollAreaWidgetContents_5 = QWidget()
        self.scrollAreaWidgetContents_5.setObjectName(u"scrollAreaWidgetContents_5")
        self.scrollAreaWidgetContents_5.setGeometry(QRect(0, 0, 191, 284))
        self.layoutWidget_4 = QWidget(self.scrollAreaWidgetContents_5)
        self.layoutWidget_4.setObjectName(u"layoutWidget_4")
        self.layoutWidget_4.setGeometry(QRect(0, 0, 201, 121))
        self.verticalLayout_18 = QVBoxLayout(self.layoutWidget_4)
        self.verticalLayout_18.setObjectName(u"verticalLayout_18")
        self.verticalLayout_18.setContentsMargins(0, 0, 0, 0)
        self.Variables_4 = QVBoxLayout()
        self.Variables_4.setObjectName(u"Variables_4")
        self.label_18 = QLabel(self.layoutWidget_4)
        self.label_18.setObjectName(u"label_18")

        self.Variables_4.addWidget(self.label_18)

        self.groupBox = QGroupBox(self.layoutWidget_4)
        self.groupBox.setObjectName(u"groupBox")

        self.Variables_4.addWidget(self.groupBox)


        self.verticalLayout_18.addLayout(self.Variables_4)

        self.Functions_2 = QVBoxLayout()
        self.Functions_2.setObjectName(u"Functions_2")
        self.label_19 = QLabel(self.layoutWidget_4)
        self.label_19.setObjectName(u"label_19")

        self.Functions_2.addWidget(self.label_19)


        self.verticalLayout_18.addLayout(self.Functions_2)

        self.Types_2 = QVBoxLayout()
        self.Types_2.setObjectName(u"Types_2")
        self.label_20 = QLabel(self.layoutWidget_4)
        self.label_20.setObjectName(u"label_20")

        self.Types_2.addWidget(self.label_20)


        self.verticalLayout_18.addLayout(self.Types_2)

        self.Operators_2 = QVBoxLayout()
        self.Operators_2.setObjectName(u"Operators_2")
        self.label_21 = QLabel(self.layoutWidget_4)
        self.label_21.setObjectName(u"label_21")

        self.Operators_2.addWidget(self.label_21)


        self.verticalLayout_18.addLayout(self.Operators_2)

        self.scrollArea_4.setWidget(self.scrollAreaWidgetContents_5)
        self.scrollArea_2 = QScrollArea(self.centralwidget)
        self.scrollArea_2.setObjectName(u"scrollArea_2")
        self.scrollArea_2.setGeometry(QRect(10, 360, 193, 286))
        self.scrollArea_2.setWidgetResizable(True)
        self.scrollAreaWidgetContents_2 = QWidget()
        self.scrollAreaWidgetContents_2.setObjectName(u"scrollAreaWidgetContents_2")
        self.scrollAreaWidgetContents_2.setGeometry(QRect(0, 0, 177, 978))
        self.verticalLayout_6 = QVBoxLayout(self.scrollAreaWidgetContents_2)
        self.verticalLayout_6.setObjectName(u"verticalLayout_6")
        self.verticalLayout_9 = QVBoxLayout()
        self.verticalLayout_9.setObjectName(u"verticalLayout_9")
        self.Variables_bck = QGroupBox(self.scrollAreaWidgetContents_2)
        self.Variables_bck.setObjectName(u"Variables_bck")
        self.verticalLayout_5 = QVBoxLayout(self.Variables_bck)
        self.verticalLayout_5.setObjectName(u"verticalLayout_5")
        self.label_6 = QLabel(self.Variables_bck)
        self.label_6.setObjectName(u"label_6")

        self.verticalLayout_5.addWidget(self.label_6)

        self.label_23 = QLabel(self.Variables_bck)
        self.label_23.setObjectName(u"label_23")

        self.verticalLayout_5.addWidget(self.label_23)

        self.label_22 = QLabel(self.Variables_bck)
        self.label_22.setObjectName(u"label_22")

        self.verticalLayout_5.addWidget(self.label_22)

        self.label_24 = QLabel(self.Variables_bck)
        self.label_24.setObjectName(u"label_24")

        self.verticalLayout_5.addWidget(self.label_24)

        self.label_26 = QLabel(self.Variables_bck)
        self.label_26.setObjectName(u"label_26")

        self.verticalLayout_5.addWidget(self.label_26)

        self.label_27 = QLabel(self.Variables_bck)
        self.label_27.setObjectName(u"label_27")

        self.verticalLayout_5.addWidget(self.label_27)

        self.label_28 = QLabel(self.Variables_bck)
        self.label_28.setObjectName(u"label_28")

        self.verticalLayout_5.addWidget(self.label_28)

        self.label_29 = QLabel(self.Variables_bck)
        self.label_29.setObjectName(u"label_29")

        self.verticalLayout_5.addWidget(self.label_29)

        self.label_30 = QLabel(self.Variables_bck)
        self.label_30.setObjectName(u"label_30")

        self.verticalLayout_5.addWidget(self.label_30)

        self.label_25 = QLabel(self.Variables_bck)
        self.label_25.setObjectName(u"label_25")

        self.verticalLayout_5.addWidget(self.label_25)


        self.verticalLayout_9.addWidget(self.Variables_bck)

        self.Functions_bck = QGroupBox(self.scrollAreaWidgetContents_2)
        self.Functions_bck.setObjectName(u"Functions_bck")
        self.verticalLayout_8 = QVBoxLayout(self.Functions_bck)
        self.verticalLayout_8.setObjectName(u"verticalLayout_8")
        self.label_41 = QLabel(self.Functions_bck)
        self.label_41.setObjectName(u"label_41")

        self.verticalLayout_8.addWidget(self.label_41)

        self.label_42 = QLabel(self.Functions_bck)
        self.label_42.setObjectName(u"label_42")

        self.verticalLayout_8.addWidget(self.label_42)

        self.label_43 = QLabel(self.Functions_bck)
        self.label_43.setObjectName(u"label_43")

        self.verticalLayout_8.addWidget(self.label_43)

        self.label_44 = QLabel(self.Functions_bck)
        self.label_44.setObjectName(u"label_44")

        self.verticalLayout_8.addWidget(self.label_44)

        self.label_45 = QLabel(self.Functions_bck)
        self.label_45.setObjectName(u"label_45")

        self.verticalLayout_8.addWidget(self.label_45)

        self.label_46 = QLabel(self.Functions_bck)
        self.label_46.setObjectName(u"label_46")

        self.verticalLayout_8.addWidget(self.label_46)

        self.label_47 = QLabel(self.Functions_bck)
        self.label_47.setObjectName(u"label_47")

        self.verticalLayout_8.addWidget(self.label_47)

        self.label_48 = QLabel(self.Functions_bck)
        self.label_48.setObjectName(u"label_48")

        self.verticalLayout_8.addWidget(self.label_48)

        self.label_49 = QLabel(self.Functions_bck)
        self.label_49.setObjectName(u"label_49")

        self.verticalLayout_8.addWidget(self.label_49)

        self.label_50 = QLabel(self.Functions_bck)
        self.label_50.setObjectName(u"label_50")

        self.verticalLayout_8.addWidget(self.label_50)


        self.verticalLayout_9.addWidget(self.Functions_bck)

        self.Types_bck = QGroupBox(self.scrollAreaWidgetContents_2)
        self.Types_bck.setObjectName(u"Types_bck")
        self.verticalLayout_7 = QVBoxLayout(self.Types_bck)
        self.verticalLayout_7.setObjectName(u"verticalLayout_7")
        self.label_31 = QLabel(self.Types_bck)
        self.label_31.setObjectName(u"label_31")

        self.verticalLayout_7.addWidget(self.label_31)

        self.label_32 = QLabel(self.Types_bck)
        self.label_32.setObjectName(u"label_32")

        self.verticalLayout_7.addWidget(self.label_32)

        self.label_33 = QLabel(self.Types_bck)
        self.label_33.setObjectName(u"label_33")

        self.verticalLayout_7.addWidget(self.label_33)

        self.label_34 = QLabel(self.Types_bck)
        self.label_34.setObjectName(u"label_34")

        self.verticalLayout_7.addWidget(self.label_34)

        self.label_35 = QLabel(self.Types_bck)
        self.label_35.setObjectName(u"label_35")

        self.verticalLayout_7.addWidget(self.label_35)

        self.label_36 = QLabel(self.Types_bck)
        self.label_36.setObjectName(u"label_36")

        self.verticalLayout_7.addWidget(self.label_36)

        self.label_37 = QLabel(self.Types_bck)
        self.label_37.setObjectName(u"label_37")

        self.verticalLayout_7.addWidget(self.label_37)

        self.label_38 = QLabel(self.Types_bck)
        self.label_38.setObjectName(u"label_38")

        self.verticalLayout_7.addWidget(self.label_38)

        self.label_39 = QLabel(self.Types_bck)
        self.label_39.setObjectName(u"label_39")

        self.verticalLayout_7.addWidget(self.label_39)

        self.label_40 = QLabel(self.Types_bck)
        self.label_40.setObjectName(u"label_40")

        self.verticalLayout_7.addWidget(self.label_40)


        self.verticalLayout_9.addWidget(self.Types_bck)

        self.Operators_bck = QGroupBox(self.scrollAreaWidgetContents_2)
        self.Operators_bck.setObjectName(u"Operators_bck")
        self.verticalLayout_19 = QVBoxLayout(self.Operators_bck)
        self.verticalLayout_19.setObjectName(u"verticalLayout_19")
        self.label_51 = QLabel(self.Operators_bck)
        self.label_51.setObjectName(u"label_51")

        self.verticalLayout_19.addWidget(self.label_51)

        self.label_52 = QLabel(self.Operators_bck)
        self.label_52.setObjectName(u"label_52")

        self.verticalLayout_19.addWidget(self.label_52)

        self.label_53 = QLabel(self.Operators_bck)
        self.label_53.setObjectName(u"label_53")

        self.verticalLayout_19.addWidget(self.label_53)

        self.label_54 = QLabel(self.Operators_bck)
        self.label_54.setObjectName(u"label_54")

        self.verticalLayout_19.addWidget(self.label_54)

        self.label_55 = QLabel(self.Operators_bck)
        self.label_55.setObjectName(u"label_55")

        self.verticalLayout_19.addWidget(self.label_55)

        self.label_56 = QLabel(self.Operators_bck)
        self.label_56.setObjectName(u"label_56")

        self.verticalLayout_19.addWidget(self.label_56)

        self.label_57 = QLabel(self.Operators_bck)
        self.label_57.setObjectName(u"label_57")

        self.verticalLayout_19.addWidget(self.label_57)

        self.label_58 = QLabel(self.Operators_bck)
        self.label_58.setObjectName(u"label_58")

        self.verticalLayout_19.addWidget(self.label_58)

        self.label_59 = QLabel(self.Operators_bck)
        self.label_59.setObjectName(u"label_59")

        self.verticalLayout_19.addWidget(self.label_59)

        self.label_60 = QLabel(self.Operators_bck)
        self.label_60.setObjectName(u"label_60")

        self.verticalLayout_19.addWidget(self.label_60)


        self.verticalLayout_9.addWidget(self.Operators_bck)


        self.verticalLayout_6.addLayout(self.verticalLayout_9)

        self.scrollArea_2.setWidget(self.scrollAreaWidgetContents_2)
        Display.setCentralWidget(self.centralwidget)
        self.menubar = QMenuBar(Display)
        self.menubar.setObjectName(u"menubar")
        self.menubar.setGeometry(QRect(0, 0, 777, 19))
        Display.setMenuBar(self.menubar)
        self.statusbar = QStatusBar(Display)
        self.statusbar.setObjectName(u"statusbar")
        Display.setStatusBar(self.statusbar)

        self.retranslateUi(Display)

        self.Objects.setCurrentIndex(4)


        QMetaObject.connectSlotsByName(Display)
    # setupUi

    def retranslateUi(self, Display):
        Display.setWindowTitle(QCoreApplication.translate("Display", u"Display", None))
        self.label.setText(QCoreApplication.translate("Display", u"HellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHello"
                        "sHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHell"
                        "osHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHel"
                        "losHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHe"
                        "llosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosH"
                        "ellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellos", None))
        self.label_9.setText(QCoreApplication.translate("Display", u"HellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHello"
                        "sHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHell"
                        "osHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHel"
                        "losHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHe"
                        "llosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosH"
                        "ellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellosHellos", None))
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
        self.label_7.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.Objects.setTabText(self.Objects.indexOf(self.Variables), QCoreApplication.translate("Display", u"Variables", None))
        self.label_8.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.Objects.setTabText(self.Objects.indexOf(self.Functions), QCoreApplication.translate("Display", u"Functions", None))
        self.label_14.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.Objects.setTabText(self.Objects.indexOf(self.Types), QCoreApplication.translate("Display", u"Types", None))
        self.label_15.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.Objects.setTabText(self.Objects.indexOf(self.Operators), QCoreApplication.translate("Display", u"Operators", None))
        self.label_16.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.Objects.setTabText(self.Objects.indexOf(self.Misc), QCoreApplication.translate("Display", u"Misc", None))
        self.label_10.setText(QCoreApplication.translate("Display", u"Variables", None))
        self.label_11.setText(QCoreApplication.translate("Display", u"Functions", None))
        self.label_12.setText(QCoreApplication.translate("Display", u"Types", None))
        self.label_13.setText(QCoreApplication.translate("Display", u"Operators", None))
        self.label_18.setText(QCoreApplication.translate("Display", u"Variables", None))
        self.groupBox.setTitle(QCoreApplication.translate("Display", u"GroupBox", None))
        self.label_19.setText(QCoreApplication.translate("Display", u"Functions", None))
        self.label_20.setText(QCoreApplication.translate("Display", u"Types", None))
        self.label_21.setText(QCoreApplication.translate("Display", u"Operators", None))
        self.Variables_bck.setTitle(QCoreApplication.translate("Display", u"Variables", None))
        self.label_6.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_23.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_22.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_24.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_26.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_27.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_28.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_29.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_30.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_25.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.Functions_bck.setTitle(QCoreApplication.translate("Display", u"Functions", None))
        self.label_41.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_42.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_43.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_44.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_45.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_46.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_47.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_48.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_49.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_50.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.Types_bck.setTitle(QCoreApplication.translate("Display", u"Types", None))
        self.label_31.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_32.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_33.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_34.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_35.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_36.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_37.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_38.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_39.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_40.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.Operators_bck.setTitle(QCoreApplication.translate("Display", u"Operators", None))
        self.label_51.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_52.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_53.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_54.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_55.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_56.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_57.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_58.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_59.setText(QCoreApplication.translate("Display", u"TextLabel", None))
        self.label_60.setText(QCoreApplication.translate("Display", u"TextLabel", None))
    # retranslateUi

