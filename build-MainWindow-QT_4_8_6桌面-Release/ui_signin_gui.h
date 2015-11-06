/********************************************************************************
** Form generated from reading UI file 'signin_gui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNIN_GUI_H
#define UI_SIGNIN_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Signin_GUI
{
public:
    QGridLayout *gridLayout;
    QLabel *label_topImg;
    QFormLayout *formLayout;
    QLabel *label_user;
    QLineEdit *lineEdit_user;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_exit;
    QPushButton *pushButton_signin;

    void setupUi(QDialog *Signin_GUI)
    {
        if (Signin_GUI->objectName().isEmpty())
            Signin_GUI->setObjectName(QString::fromUtf8("Signin_GUI"));
        Signin_GUI->resize(338, 229);
        gridLayout = new QGridLayout(Signin_GUI);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_topImg = new QLabel(Signin_GUI);
        label_topImg->setObjectName(QString::fromUtf8("label_topImg"));
        label_topImg->setPixmap(QPixmap(QString::fromUtf8(":/myImg/topImg.jpg")));

        gridLayout->addWidget(label_topImg, 0, 0, 1, 2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_user = new QLabel(Signin_GUI);
        label_user->setObjectName(QString::fromUtf8("label_user"));
        label_user->setMinimumSize(QSize(100, 0));
        label_user->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_user);

        lineEdit_user = new QLineEdit(Signin_GUI);
        lineEdit_user->setObjectName(QString::fromUtf8("lineEdit_user"));
        lineEdit_user->setMaxLength(20);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_user);

        label_password = new QLabel(Signin_GUI);
        label_password->setObjectName(QString::fromUtf8("label_password"));
        label_password->setMinimumSize(QSize(100, 0));
        label_password->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_password);

        lineEdit_password = new QLineEdit(Signin_GUI);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setMaxLength(20);
        lineEdit_password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_password);


        gridLayout->addLayout(formLayout, 1, 0, 1, 2);

        pushButton_exit = new QPushButton(Signin_GUI);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        gridLayout->addWidget(pushButton_exit, 2, 0, 1, 1);

        pushButton_signin = new QPushButton(Signin_GUI);
        pushButton_signin->setObjectName(QString::fromUtf8("pushButton_signin"));
        pushButton_signin->setDefault(true);

        gridLayout->addWidget(pushButton_signin, 2, 1, 1, 1);

        QWidget::setTabOrder(lineEdit_user, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, pushButton_signin);
        QWidget::setTabOrder(pushButton_signin, pushButton_exit);

        retranslateUi(Signin_GUI);

        QMetaObject::connectSlotsByName(Signin_GUI);
    } // setupUi

    void retranslateUi(QDialog *Signin_GUI)
    {
        Signin_GUI->setWindowTitle(QApplication::translate("Signin_GUI", "Admin Sign In", 0, QApplication::UnicodeUTF8));
        label_topImg->setText(QString());
        label_user->setText(QApplication::translate("Signin_GUI", "User:", 0, QApplication::UnicodeUTF8));
        label_password->setText(QApplication::translate("Signin_GUI", "Password:", 0, QApplication::UnicodeUTF8));
        pushButton_exit->setText(QApplication::translate("Signin_GUI", "Exit", 0, QApplication::UnicodeUTF8));
        pushButton_signin->setText(QApplication::translate("Signin_GUI", "Sign In", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Signin_GUI: public Ui_Signin_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNIN_GUI_H
