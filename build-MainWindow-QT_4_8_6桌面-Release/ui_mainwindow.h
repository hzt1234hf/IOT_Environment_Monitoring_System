/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <linecharwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_O;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_Main;
    QGroupBox *groupBox_DeviceCtrl;
    QGridLayout *gridLayout_7;
    QPushButton *pBtn_WindowOn_OFF;
    QPushButton *pBtn_LightOn_OFF;
    QGroupBox *groupBox_DeviceState;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_dataCO2;
    QGridLayout *gridLayout_6;
    QLabel *label_dataCO2Interval;
    QSpinBox *spinBox_dataCO2Count;
    QLabel *label_intervalSignal_3;
    QCheckBox *dataCO2_OnOff;
    QPushButton *pushButton_CO2Warning;
    QLabel *label_textCO2;
    QLineEdit *lineEdit_CO2;
    QLabel *label_dataCO2;
    QGroupBox *groupBox_dataHumid;
    QGridLayout *gridLayout_9;
    QLabel *label_dataHumidInterval;
    QSpinBox *spinBox_dataHumidCount;
    QLabel *label_intervalSignal;
    QCheckBox *dataHumid_OnOff;
    QPushButton *pushButton_HumidWarning;
    QLabel *label_textHumid;
    QLineEdit *lineEdit_Humid;
    QLabel *label_dataHumid;
    QGroupBox *groupBox_dataTempe;
    QGridLayout *gridLayout_8;
    QLabel *label_dataTempeInterval;
    QSpinBox *spinBox_dataTempeCount;
    QLabel *label_intervalSignal_2;
    QCheckBox *dataTempe_OnOff;
    QPushButton *pushButton_TemperaWarning;
    QLabel *label_textTempe;
    QLineEdit *lineEdit_Tempe;
    QLabel *label_dataTempe;
    QGroupBox *groupBox_dataLight;
    QGridLayout *gridLayout_4;
    QLabel *label_dataLightInterval;
    QSpinBox *spinBox_dataLightCount;
    QLabel *label_intervalSignal_4;
    QCheckBox *dataLight_OnOff;
    QPushButton *pushButton_LightWarning;
    QLabel *label_textLight;
    QLineEdit *lineEdit_Light;
    QLabel *label_dataLight;
    QGridLayout *gridLayout_LCW;
    LineCharWidget *LCWidget;
    QGroupBox *groupBox_DataShow;
    QGridLayout *gridLayout_10;
    QPushButton *pushButton_lightData;
    QPushButton *pushButton_co2Data;
    QPushButton *pushButton_tempeData;
    QPushButton *pushButton_humidData;
    QGroupBox *groupBox_ttyData;
    QGridLayout *gridLayout;
    QLabel *labelReceive;
    QTextBrowser *serialTextReceive;
    QLabel *labelSend;
    QLineEdit *serialLineSend;
    QPushButton *serialBtnSend;
    QGroupBox *groupBox_ttyConf;
    QGridLayout *gridLayout_2;
    QLabel *UART1_label_ttyUSB;
    QComboBox *UART1_comboBox_ttyUSB;
    QLabel *UART1_label_BaudRate;
    QComboBox *UART1_comboBox_BaudRate;
    QLabel *UART1_label_ParityBit;
    QComboBox *UART1_comboBox_ParityBit;
    QLabel *UART1_label_StopBit;
    QComboBox *UART1_comboBox_StopBit;
    QCheckBox *UART1_check_clrRecv;
    QPushButton *BTN_OpenttyUSB;
    QMenuBar *menuBar;
    QMenu *menuFile_F;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1300, 753);
        MainWindow->setMinimumSize(QSize(1300, 753));
        actionOpen_O = new QAction(MainWindow);
        actionOpen_O->setObjectName(QString::fromUtf8("actionOpen_O"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/myImg/myImg/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_O->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        centralWidget->setFont(font);
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_Main = new QGridLayout();
        gridLayout_Main->setSpacing(6);
        gridLayout_Main->setObjectName(QString::fromUtf8("gridLayout_Main"));
        groupBox_DeviceCtrl = new QGroupBox(centralWidget);
        groupBox_DeviceCtrl->setObjectName(QString::fromUtf8("groupBox_DeviceCtrl"));
        groupBox_DeviceCtrl->setMinimumSize(QSize(250, 0));
        groupBox_DeviceCtrl->setMaximumSize(QSize(250, 300));
        gridLayout_7 = new QGridLayout(groupBox_DeviceCtrl);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        pBtn_WindowOn_OFF = new QPushButton(groupBox_DeviceCtrl);
        pBtn_WindowOn_OFF->setObjectName(QString::fromUtf8("pBtn_WindowOn_OFF"));

        gridLayout_7->addWidget(pBtn_WindowOn_OFF, 0, 0, 1, 1);

        pBtn_LightOn_OFF = new QPushButton(groupBox_DeviceCtrl);
        pBtn_LightOn_OFF->setObjectName(QString::fromUtf8("pBtn_LightOn_OFF"));

        gridLayout_7->addWidget(pBtn_LightOn_OFF, 1, 0, 1, 1);


        gridLayout_Main->addWidget(groupBox_DeviceCtrl, 2, 2, 1, 1);

        groupBox_DeviceState = new QGroupBox(centralWidget);
        groupBox_DeviceState->setObjectName(QString::fromUtf8("groupBox_DeviceState"));
        groupBox_DeviceState->setMinimumSize(QSize(250, 0));
        groupBox_DeviceState->setMaximumSize(QSize(250, 16777215));
        gridLayout_3 = new QGridLayout(groupBox_DeviceState);
        gridLayout_3->setSpacing(4);
        gridLayout_3->setContentsMargins(7, 7, 7, 7);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_dataCO2 = new QGroupBox(groupBox_DeviceState);
        groupBox_dataCO2->setObjectName(QString::fromUtf8("groupBox_dataCO2"));
        gridLayout_6 = new QGridLayout(groupBox_dataCO2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_dataCO2Interval = new QLabel(groupBox_dataCO2);
        label_dataCO2Interval->setObjectName(QString::fromUtf8("label_dataCO2Interval"));

        gridLayout_6->addWidget(label_dataCO2Interval, 0, 0, 1, 1);

        spinBox_dataCO2Count = new QSpinBox(groupBox_dataCO2);
        spinBox_dataCO2Count->setObjectName(QString::fromUtf8("spinBox_dataCO2Count"));
        spinBox_dataCO2Count->setMinimumSize(QSize(0, 20));
        spinBox_dataCO2Count->setMinimum(1);
        spinBox_dataCO2Count->setMaximum(20);
        spinBox_dataCO2Count->setValue(1);

        gridLayout_6->addWidget(spinBox_dataCO2Count, 0, 1, 1, 2);

        label_intervalSignal_3 = new QLabel(groupBox_dataCO2);
        label_intervalSignal_3->setObjectName(QString::fromUtf8("label_intervalSignal_3"));

        gridLayout_6->addWidget(label_intervalSignal_3, 0, 3, 1, 1);

        dataCO2_OnOff = new QCheckBox(groupBox_dataCO2);
        dataCO2_OnOff->setObjectName(QString::fromUtf8("dataCO2_OnOff"));
        dataCO2_OnOff->setChecked(false);

        gridLayout_6->addWidget(dataCO2_OnOff, 1, 0, 1, 1);

        pushButton_CO2Warning = new QPushButton(groupBox_dataCO2);
        pushButton_CO2Warning->setObjectName(QString::fromUtf8("pushButton_CO2Warning"));
        pushButton_CO2Warning->setEnabled(false);
        pushButton_CO2Warning->setMinimumSize(QSize(15, 15));
        pushButton_CO2Warning->setMaximumSize(QSize(15, 15));

        gridLayout_6->addWidget(pushButton_CO2Warning, 1, 1, 1, 1);

        label_textCO2 = new QLabel(groupBox_dataCO2);
        label_textCO2->setObjectName(QString::fromUtf8("label_textCO2"));
        label_textCO2->setMinimumSize(QSize(0, 15));
        label_textCO2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_textCO2, 1, 2, 1, 1);

        lineEdit_CO2 = new QLineEdit(groupBox_dataCO2);
        lineEdit_CO2->setObjectName(QString::fromUtf8("lineEdit_CO2"));
        lineEdit_CO2->setEnabled(true);
        lineEdit_CO2->setMinimumSize(QSize(0, 20));
        lineEdit_CO2->setMaximumSize(QSize(80, 16777215));
        lineEdit_CO2->setAlignment(Qt::AlignCenter);
        lineEdit_CO2->setReadOnly(true);

        gridLayout_6->addWidget(lineEdit_CO2, 2, 0, 1, 1);

        label_dataCO2 = new QLabel(groupBox_dataCO2);
        label_dataCO2->setObjectName(QString::fromUtf8("label_dataCO2"));
        label_dataCO2->setMinimumSize(QSize(50, 20));
        label_dataCO2->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(label_dataCO2, 2, 2, 1, 2);


        gridLayout_3->addWidget(groupBox_dataCO2, 2, 0, 1, 2);

        groupBox_dataHumid = new QGroupBox(groupBox_DeviceState);
        groupBox_dataHumid->setObjectName(QString::fromUtf8("groupBox_dataHumid"));
        gridLayout_9 = new QGridLayout(groupBox_dataHumid);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_dataHumidInterval = new QLabel(groupBox_dataHumid);
        label_dataHumidInterval->setObjectName(QString::fromUtf8("label_dataHumidInterval"));

        gridLayout_9->addWidget(label_dataHumidInterval, 0, 0, 1, 1);

        spinBox_dataHumidCount = new QSpinBox(groupBox_dataHumid);
        spinBox_dataHumidCount->setObjectName(QString::fromUtf8("spinBox_dataHumidCount"));
        spinBox_dataHumidCount->setMinimumSize(QSize(0, 20));
        spinBox_dataHumidCount->setMinimum(1);
        spinBox_dataHumidCount->setMaximum(20);
        spinBox_dataHumidCount->setValue(1);

        gridLayout_9->addWidget(spinBox_dataHumidCount, 0, 1, 1, 2);

        label_intervalSignal = new QLabel(groupBox_dataHumid);
        label_intervalSignal->setObjectName(QString::fromUtf8("label_intervalSignal"));

        gridLayout_9->addWidget(label_intervalSignal, 0, 3, 1, 1);

        dataHumid_OnOff = new QCheckBox(groupBox_dataHumid);
        dataHumid_OnOff->setObjectName(QString::fromUtf8("dataHumid_OnOff"));
        dataHumid_OnOff->setChecked(false);

        gridLayout_9->addWidget(dataHumid_OnOff, 1, 0, 1, 1);

        pushButton_HumidWarning = new QPushButton(groupBox_dataHumid);
        pushButton_HumidWarning->setObjectName(QString::fromUtf8("pushButton_HumidWarning"));
        pushButton_HumidWarning->setEnabled(false);
        pushButton_HumidWarning->setMinimumSize(QSize(15, 15));
        pushButton_HumidWarning->setMaximumSize(QSize(15, 15));

        gridLayout_9->addWidget(pushButton_HumidWarning, 1, 1, 1, 1);

        label_textHumid = new QLabel(groupBox_dataHumid);
        label_textHumid->setObjectName(QString::fromUtf8("label_textHumid"));
        label_textHumid->setMinimumSize(QSize(0, 15));
        label_textHumid->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_textHumid, 1, 2, 1, 1);

        lineEdit_Humid = new QLineEdit(groupBox_dataHumid);
        lineEdit_Humid->setObjectName(QString::fromUtf8("lineEdit_Humid"));
        lineEdit_Humid->setEnabled(true);
        lineEdit_Humid->setMinimumSize(QSize(0, 20));
        lineEdit_Humid->setMaximumSize(QSize(80, 16777215));
        lineEdit_Humid->setAlignment(Qt::AlignCenter);
        lineEdit_Humid->setReadOnly(true);

        gridLayout_9->addWidget(lineEdit_Humid, 2, 0, 1, 1);

        label_dataHumid = new QLabel(groupBox_dataHumid);
        label_dataHumid->setObjectName(QString::fromUtf8("label_dataHumid"));
        label_dataHumid->setMinimumSize(QSize(50, 20));
        label_dataHumid->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_dataHumid, 2, 2, 1, 2);


        gridLayout_3->addWidget(groupBox_dataHumid, 4, 0, 1, 1);

        groupBox_dataTempe = new QGroupBox(groupBox_DeviceState);
        groupBox_dataTempe->setObjectName(QString::fromUtf8("groupBox_dataTempe"));
        gridLayout_8 = new QGridLayout(groupBox_dataTempe);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_dataTempeInterval = new QLabel(groupBox_dataTempe);
        label_dataTempeInterval->setObjectName(QString::fromUtf8("label_dataTempeInterval"));

        gridLayout_8->addWidget(label_dataTempeInterval, 0, 0, 1, 1);

        spinBox_dataTempeCount = new QSpinBox(groupBox_dataTempe);
        spinBox_dataTempeCount->setObjectName(QString::fromUtf8("spinBox_dataTempeCount"));
        spinBox_dataTempeCount->setMinimumSize(QSize(0, 20));
        spinBox_dataTempeCount->setMinimum(1);
        spinBox_dataTempeCount->setMaximum(20);
        spinBox_dataTempeCount->setValue(1);

        gridLayout_8->addWidget(spinBox_dataTempeCount, 0, 1, 1, 2);

        label_intervalSignal_2 = new QLabel(groupBox_dataTempe);
        label_intervalSignal_2->setObjectName(QString::fromUtf8("label_intervalSignal_2"));

        gridLayout_8->addWidget(label_intervalSignal_2, 0, 3, 1, 1);

        dataTempe_OnOff = new QCheckBox(groupBox_dataTempe);
        dataTempe_OnOff->setObjectName(QString::fromUtf8("dataTempe_OnOff"));
        dataTempe_OnOff->setChecked(false);

        gridLayout_8->addWidget(dataTempe_OnOff, 1, 0, 1, 1);

        pushButton_TemperaWarning = new QPushButton(groupBox_dataTempe);
        pushButton_TemperaWarning->setObjectName(QString::fromUtf8("pushButton_TemperaWarning"));
        pushButton_TemperaWarning->setEnabled(false);
        pushButton_TemperaWarning->setMinimumSize(QSize(15, 15));
        pushButton_TemperaWarning->setMaximumSize(QSize(15, 15));

        gridLayout_8->addWidget(pushButton_TemperaWarning, 1, 1, 1, 1);

        label_textTempe = new QLabel(groupBox_dataTempe);
        label_textTempe->setObjectName(QString::fromUtf8("label_textTempe"));
        label_textTempe->setMinimumSize(QSize(0, 15));
        label_textTempe->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_textTempe, 1, 2, 1, 1);

        lineEdit_Tempe = new QLineEdit(groupBox_dataTempe);
        lineEdit_Tempe->setObjectName(QString::fromUtf8("lineEdit_Tempe"));
        lineEdit_Tempe->setEnabled(true);
        lineEdit_Tempe->setMinimumSize(QSize(0, 20));
        lineEdit_Tempe->setMaximumSize(QSize(80, 16777215));
        lineEdit_Tempe->setAlignment(Qt::AlignCenter);
        lineEdit_Tempe->setReadOnly(true);

        gridLayout_8->addWidget(lineEdit_Tempe, 2, 0, 1, 1);

        label_dataTempe = new QLabel(groupBox_dataTempe);
        label_dataTempe->setObjectName(QString::fromUtf8("label_dataTempe"));
        label_dataTempe->setMinimumSize(QSize(50, 20));
        label_dataTempe->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(label_dataTempe, 2, 2, 1, 2);


        gridLayout_3->addWidget(groupBox_dataTempe, 3, 0, 1, 2);

        groupBox_dataLight = new QGroupBox(groupBox_DeviceState);
        groupBox_dataLight->setObjectName(QString::fromUtf8("groupBox_dataLight"));
        gridLayout_4 = new QGridLayout(groupBox_dataLight);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_dataLightInterval = new QLabel(groupBox_dataLight);
        label_dataLightInterval->setObjectName(QString::fromUtf8("label_dataLightInterval"));

        gridLayout_4->addWidget(label_dataLightInterval, 0, 0, 1, 1);

        spinBox_dataLightCount = new QSpinBox(groupBox_dataLight);
        spinBox_dataLightCount->setObjectName(QString::fromUtf8("spinBox_dataLightCount"));
        spinBox_dataLightCount->setMinimumSize(QSize(0, 20));
        spinBox_dataLightCount->setMinimum(1);
        spinBox_dataLightCount->setMaximum(20);
        spinBox_dataLightCount->setValue(1);

        gridLayout_4->addWidget(spinBox_dataLightCount, 0, 1, 1, 2);

        label_intervalSignal_4 = new QLabel(groupBox_dataLight);
        label_intervalSignal_4->setObjectName(QString::fromUtf8("label_intervalSignal_4"));

        gridLayout_4->addWidget(label_intervalSignal_4, 0, 3, 1, 1);

        dataLight_OnOff = new QCheckBox(groupBox_dataLight);
        dataLight_OnOff->setObjectName(QString::fromUtf8("dataLight_OnOff"));
        dataLight_OnOff->setChecked(false);

        gridLayout_4->addWidget(dataLight_OnOff, 1, 0, 1, 1);

        pushButton_LightWarning = new QPushButton(groupBox_dataLight);
        pushButton_LightWarning->setObjectName(QString::fromUtf8("pushButton_LightWarning"));
        pushButton_LightWarning->setEnabled(false);
        pushButton_LightWarning->setMinimumSize(QSize(15, 15));
        pushButton_LightWarning->setMaximumSize(QSize(15, 15));

        gridLayout_4->addWidget(pushButton_LightWarning, 1, 1, 1, 1);

        label_textLight = new QLabel(groupBox_dataLight);
        label_textLight->setObjectName(QString::fromUtf8("label_textLight"));
        label_textLight->setMinimumSize(QSize(0, 15));
        label_textLight->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_textLight, 1, 2, 1, 1);

        lineEdit_Light = new QLineEdit(groupBox_dataLight);
        lineEdit_Light->setObjectName(QString::fromUtf8("lineEdit_Light"));
        lineEdit_Light->setEnabled(true);
        lineEdit_Light->setMinimumSize(QSize(0, 20));
        lineEdit_Light->setMaximumSize(QSize(80, 16777215));
        lineEdit_Light->setAlignment(Qt::AlignCenter);
        lineEdit_Light->setReadOnly(true);

        gridLayout_4->addWidget(lineEdit_Light, 2, 0, 1, 1);

        label_dataLight = new QLabel(groupBox_dataLight);
        label_dataLight->setObjectName(QString::fromUtf8("label_dataLight"));
        label_dataLight->setMinimumSize(QSize(50, 20));
        label_dataLight->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_dataLight, 2, 2, 1, 2);


        gridLayout_3->addWidget(groupBox_dataLight, 1, 0, 1, 2);


        gridLayout_Main->addWidget(groupBox_DeviceState, 0, 2, 2, 1);

        gridLayout_LCW = new QGridLayout();
        gridLayout_LCW->setSpacing(6);
        gridLayout_LCW->setObjectName(QString::fromUtf8("gridLayout_LCW"));
        LCWidget = new LineCharWidget(centralWidget);
        LCWidget->setObjectName(QString::fromUtf8("LCWidget"));
        LCWidget->setMinimumSize(QSize(1022, 436));
        LCWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_LCW->addWidget(LCWidget, 0, 0, 1, 1);


        gridLayout_Main->addLayout(gridLayout_LCW, 0, 0, 2, 2);

        groupBox_DataShow = new QGroupBox(centralWidget);
        groupBox_DataShow->setObjectName(QString::fromUtf8("groupBox_DataShow"));
        gridLayout_10 = new QGridLayout(groupBox_DataShow);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        pushButton_lightData = new QPushButton(groupBox_DataShow);
        pushButton_lightData->setObjectName(QString::fromUtf8("pushButton_lightData"));

        gridLayout_10->addWidget(pushButton_lightData, 0, 0, 1, 1);

        pushButton_co2Data = new QPushButton(groupBox_DataShow);
        pushButton_co2Data->setObjectName(QString::fromUtf8("pushButton_co2Data"));

        gridLayout_10->addWidget(pushButton_co2Data, 0, 1, 1, 1);

        pushButton_tempeData = new QPushButton(groupBox_DataShow);
        pushButton_tempeData->setObjectName(QString::fromUtf8("pushButton_tempeData"));

        gridLayout_10->addWidget(pushButton_tempeData, 1, 0, 1, 1);

        pushButton_humidData = new QPushButton(groupBox_DataShow);
        pushButton_humidData->setObjectName(QString::fromUtf8("pushButton_humidData"));

        gridLayout_10->addWidget(pushButton_humidData, 1, 1, 1, 1);


        gridLayout_Main->addWidget(groupBox_DataShow, 3, 2, 1, 1);

        groupBox_ttyData = new QGroupBox(centralWidget);
        groupBox_ttyData->setObjectName(QString::fromUtf8("groupBox_ttyData"));
        groupBox_ttyData->setMaximumSize(QSize(16777215, 300));
        gridLayout = new QGridLayout(groupBox_ttyData);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelReceive = new QLabel(groupBox_ttyData);
        labelReceive->setObjectName(QString::fromUtf8("labelReceive"));

        gridLayout->addWidget(labelReceive, 0, 0, 1, 2);

        serialTextReceive = new QTextBrowser(groupBox_ttyData);
        serialTextReceive->setObjectName(QString::fromUtf8("serialTextReceive"));
        serialTextReceive->setMinimumSize(QSize(500, 0));
        serialTextReceive->setMaximumSize(QSize(16777215, 200));
        serialTextReceive->viewport()->setProperty("cursor", QVariant(QCursor(Qt::IBeamCursor)));
        serialTextReceive->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        serialTextReceive->setUndoRedoEnabled(true);
        serialTextReceive->setAcceptRichText(false);
        serialTextReceive->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(serialTextReceive, 1, 0, 1, 2);

        labelSend = new QLabel(groupBox_ttyData);
        labelSend->setObjectName(QString::fromUtf8("labelSend"));

        gridLayout->addWidget(labelSend, 2, 0, 1, 2);

        serialLineSend = new QLineEdit(groupBox_ttyData);
        serialLineSend->setObjectName(QString::fromUtf8("serialLineSend"));

        gridLayout->addWidget(serialLineSend, 3, 0, 1, 1);

        serialBtnSend = new QPushButton(groupBox_ttyData);
        serialBtnSend->setObjectName(QString::fromUtf8("serialBtnSend"));
        serialBtnSend->setEnabled(false);

        gridLayout->addWidget(serialBtnSend, 3, 1, 1, 1);


        gridLayout_Main->addWidget(groupBox_ttyData, 2, 0, 2, 1);

        groupBox_ttyConf = new QGroupBox(centralWidget);
        groupBox_ttyConf->setObjectName(QString::fromUtf8("groupBox_ttyConf"));
        groupBox_ttyConf->setMaximumSize(QSize(350, 300));
        QFont font1;
        font1.setItalic(false);
        groupBox_ttyConf->setFont(font1);
        gridLayout_2 = new QGridLayout(groupBox_ttyConf);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        UART1_label_ttyUSB = new QLabel(groupBox_ttyConf);
        UART1_label_ttyUSB->setObjectName(QString::fromUtf8("UART1_label_ttyUSB"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("AcadEref"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        UART1_label_ttyUSB->setFont(font2);
        UART1_label_ttyUSB->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(UART1_label_ttyUSB, 0, 0, 1, 1);

        UART1_comboBox_ttyUSB = new QComboBox(groupBox_ttyConf);
        UART1_comboBox_ttyUSB->setObjectName(QString::fromUtf8("UART1_comboBox_ttyUSB"));

        gridLayout_2->addWidget(UART1_comboBox_ttyUSB, 0, 1, 1, 1);

        UART1_label_BaudRate = new QLabel(groupBox_ttyConf);
        UART1_label_BaudRate->setObjectName(QString::fromUtf8("UART1_label_BaudRate"));
        UART1_label_BaudRate->setFont(font2);
        UART1_label_BaudRate->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(UART1_label_BaudRate, 1, 0, 1, 1);

        UART1_comboBox_BaudRate = new QComboBox(groupBox_ttyConf);
        UART1_comboBox_BaudRate->setObjectName(QString::fromUtf8("UART1_comboBox_BaudRate"));

        gridLayout_2->addWidget(UART1_comboBox_BaudRate, 1, 1, 1, 1);

        UART1_label_ParityBit = new QLabel(groupBox_ttyConf);
        UART1_label_ParityBit->setObjectName(QString::fromUtf8("UART1_label_ParityBit"));
        UART1_label_ParityBit->setFont(font2);
        UART1_label_ParityBit->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(UART1_label_ParityBit, 2, 0, 1, 1);

        UART1_comboBox_ParityBit = new QComboBox(groupBox_ttyConf);
        UART1_comboBox_ParityBit->setObjectName(QString::fromUtf8("UART1_comboBox_ParityBit"));

        gridLayout_2->addWidget(UART1_comboBox_ParityBit, 2, 1, 1, 1);

        UART1_label_StopBit = new QLabel(groupBox_ttyConf);
        UART1_label_StopBit->setObjectName(QString::fromUtf8("UART1_label_StopBit"));
        UART1_label_StopBit->setFont(font2);
        UART1_label_StopBit->setTextFormat(Qt::AutoText);

        gridLayout_2->addWidget(UART1_label_StopBit, 3, 0, 1, 1);

        UART1_comboBox_StopBit = new QComboBox(groupBox_ttyConf);
        UART1_comboBox_StopBit->setObjectName(QString::fromUtf8("UART1_comboBox_StopBit"));

        gridLayout_2->addWidget(UART1_comboBox_StopBit, 3, 1, 1, 1);

        UART1_check_clrRecv = new QCheckBox(groupBox_ttyConf);
        UART1_check_clrRecv->setObjectName(QString::fromUtf8("UART1_check_clrRecv"));
        UART1_check_clrRecv->setMaximumSize(QSize(310, 16777215));
        UART1_check_clrRecv->setAcceptDrops(true);
        UART1_check_clrRecv->setAutoFillBackground(false);
        UART1_check_clrRecv->setCheckable(true);
        UART1_check_clrRecv->setChecked(true);
        UART1_check_clrRecv->setAutoRepeat(false);
        UART1_check_clrRecv->setAutoExclusive(false);
        UART1_check_clrRecv->setTristate(false);

        gridLayout_2->addWidget(UART1_check_clrRecv, 4, 0, 1, 2);

        BTN_OpenttyUSB = new QPushButton(groupBox_ttyConf);
        BTN_OpenttyUSB->setObjectName(QString::fromUtf8("BTN_OpenttyUSB"));
        BTN_OpenttyUSB->setDefault(true);

        gridLayout_2->addWidget(BTN_OpenttyUSB, 5, 0, 1, 1);


        gridLayout_Main->addWidget(groupBox_ttyConf, 2, 1, 2, 1);


        gridLayout_5->addLayout(gridLayout_Main, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 28));
        menuFile_F = new QMenu(menuBar);
        menuFile_F->setObjectName(QString::fromUtf8("menuFile_F"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile_F->menuAction());
        menuFile_F->addAction(actionOpen_O);
        menuFile_F->addSeparator();
        menuFile_F->addAction(actionExit);

        retranslateUi(MainWindow);

        UART1_comboBox_BaudRate->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Environmental Monitoring of Net Of Thing", 0, QApplication::UnicodeUTF8));
        actionOpen_O->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionOpen_O->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        groupBox_DeviceCtrl->setTitle(QApplication::translate("MainWindow", "Device Control:", 0, QApplication::UnicodeUTF8));
        pBtn_WindowOn_OFF->setText(QApplication::translate("MainWindow", "Open Window", 0, QApplication::UnicodeUTF8));
        pBtn_LightOn_OFF->setText(QApplication::translate("MainWindow", "Open Light", 0, QApplication::UnicodeUTF8));
        groupBox_DeviceState->setTitle(QApplication::translate("MainWindow", "Device State:", 0, QApplication::UnicodeUTF8));
        groupBox_dataCO2->setTitle(QApplication::translate("MainWindow", "CO2:", 0, QApplication::UnicodeUTF8));
        label_dataCO2Interval->setText(QApplication::translate("MainWindow", "Data Interval:", 0, QApplication::UnicodeUTF8));
        label_intervalSignal_3->setText(QApplication::translate("MainWindow", "sec", 0, QApplication::UnicodeUTF8));
        dataCO2_OnOff->setText(QApplication::translate("MainWindow", "CO2:", 0, QApplication::UnicodeUTF8));
        pushButton_CO2Warning->setText(QString());
        label_textCO2->setText(QApplication::translate("MainWindow", "info", 0, QApplication::UnicodeUTF8));
        label_dataCO2->setText(QApplication::translate("MainWindow", "(PPM)", 0, QApplication::UnicodeUTF8));
        groupBox_dataHumid->setTitle(QApplication::translate("MainWindow", "Temperature:", 0, QApplication::UnicodeUTF8));
        label_dataHumidInterval->setText(QApplication::translate("MainWindow", "Data interval:", 0, QApplication::UnicodeUTF8));
        label_intervalSignal->setText(QApplication::translate("MainWindow", "sec", 0, QApplication::UnicodeUTF8));
        dataHumid_OnOff->setText(QApplication::translate("MainWindow", "Humidity:", 0, QApplication::UnicodeUTF8));
        pushButton_HumidWarning->setText(QString());
        label_textHumid->setText(QApplication::translate("MainWindow", "info", 0, QApplication::UnicodeUTF8));
        label_dataHumid->setText(QApplication::translate("MainWindow", "(g/Kg)", 0, QApplication::UnicodeUTF8));
        groupBox_dataTempe->setTitle(QApplication::translate("MainWindow", "Temperature:", 0, QApplication::UnicodeUTF8));
        label_dataTempeInterval->setText(QApplication::translate("MainWindow", "Data Interval:", 0, QApplication::UnicodeUTF8));
        label_intervalSignal_2->setText(QApplication::translate("MainWindow", "sec", 0, QApplication::UnicodeUTF8));
        dataTempe_OnOff->setText(QApplication::translate("MainWindow", "Tempera:", 0, QApplication::UnicodeUTF8));
        pushButton_TemperaWarning->setText(QString());
        label_textTempe->setText(QApplication::translate("MainWindow", "info", 0, QApplication::UnicodeUTF8));
        lineEdit_Tempe->setText(QString());
        label_dataTempe->setText(QApplication::translate("MainWindow", "(\302\260C)", 0, QApplication::UnicodeUTF8));
        groupBox_dataLight->setTitle(QApplication::translate("MainWindow", "Light:", 0, QApplication::UnicodeUTF8));
        label_dataLightInterval->setText(QApplication::translate("MainWindow", "Data Interval:", 0, QApplication::UnicodeUTF8));
        label_intervalSignal_4->setText(QApplication::translate("MainWindow", "sec", 0, QApplication::UnicodeUTF8));
        dataLight_OnOff->setText(QApplication::translate("MainWindow", "Light:", 0, QApplication::UnicodeUTF8));
        pushButton_LightWarning->setText(QString());
        label_textLight->setText(QApplication::translate("MainWindow", "info", 0, QApplication::UnicodeUTF8));
        label_dataLight->setText(QApplication::translate("MainWindow", "(Lux)", 0, QApplication::UnicodeUTF8));
        groupBox_DataShow->setTitle(QApplication::translate("MainWindow", "DataShow:", 0, QApplication::UnicodeUTF8));
        pushButton_lightData->setText(QApplication::translate("MainWindow", "Light data", 0, QApplication::UnicodeUTF8));
        pushButton_co2Data->setText(QApplication::translate("MainWindow", "CO2 data", 0, QApplication::UnicodeUTF8));
        pushButton_tempeData->setText(QApplication::translate("MainWindow", "Tempera data", 0, QApplication::UnicodeUTF8));
        pushButton_humidData->setText(QApplication::translate("MainWindow", "Humid data", 0, QApplication::UnicodeUTF8));
        groupBox_ttyData->setTitle(QApplication::translate("MainWindow", "tty Data:", 0, QApplication::UnicodeUTF8));
        labelReceive->setText(QApplication::translate("MainWindow", "Received Data:", 0, QApplication::UnicodeUTF8));
        labelSend->setText(QApplication::translate("MainWindow", "Send Data:", 0, QApplication::UnicodeUTF8));
        serialBtnSend->setText(QApplication::translate("MainWindow", "Send", 0, QApplication::UnicodeUTF8));
        groupBox_ttyConf->setTitle(QApplication::translate("MainWindow", "tty Configura:", 0, QApplication::UnicodeUTF8));
        UART1_label_ttyUSB->setText(QApplication::translate("MainWindow", "tty:", 0, QApplication::UnicodeUTF8));
        UART1_comboBox_ttyUSB->clear();
        UART1_comboBox_ttyUSB->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "ttyUSB0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ttyUSB1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ttyUSB2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ttyUSB3", 0, QApplication::UnicodeUTF8)
        );
        UART1_label_BaudRate->setText(QApplication::translate("MainWindow", "BaudRate", 0, QApplication::UnicodeUTF8));
        UART1_comboBox_BaudRate->clear();
        UART1_comboBox_BaudRate->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "9600", "9600", QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "14400", "14400", QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "115200", 0, QApplication::UnicodeUTF8)
        );
        UART1_label_ParityBit->setText(QApplication::translate("MainWindow", "Parity:", 0, QApplication::UnicodeUTF8));
        UART1_comboBox_ParityBit->clear();
        UART1_comboBox_ParityBit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "NONE", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "ODD", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "EVEN", 0, QApplication::UnicodeUTF8)
        );
        UART1_label_StopBit->setText(QApplication::translate("MainWindow", "StopBits:", 0, QApplication::UnicodeUTF8));
        UART1_comboBox_StopBit->clear();
        UART1_comboBox_StopBit->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1 Bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "1.5 Bit", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "2 Bit", 0, QApplication::UnicodeUTF8)
        );
        UART1_check_clrRecv->setText(QApplication::translate("MainWindow", "Clear Receive Window While Open ttyUSB", 0, QApplication::UnicodeUTF8));
        BTN_OpenttyUSB->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        menuFile_F->setTitle(QApplication::translate("MainWindow", "File(&F)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
