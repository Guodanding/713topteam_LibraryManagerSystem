/********************************************************************************
** Form generated from reading UI file 'userprofilemanager.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPROFILEMANAGER_H
#define UI_USERPROFILEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserProfileManager
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_gif;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;

    void setupUi(QWidget *UserProfileManager)
    {
        if (UserProfileManager->objectName().isEmpty())
            UserProfileManager->setObjectName("UserProfileManager");
        UserProfileManager->resize(1100, 700);
        label = new QLabel(UserProfileManager);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 20, 191, 71));
        pushButton = new QPushButton(UserProfileManager);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(590, 410, 93, 29));
        label_gif = new QLabel(UserProfileManager);
        label_gif->setObjectName("label_gif");
        label_gif->setGeometry(QRect(0, 0, 1100, 700));
        verticalLayoutWidget = new QWidget(UserProfileManager);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(130, 90, 160, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName("label_6");

        verticalLayout->addWidget(label_6);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

        verticalLayoutWidget_2 = new QWidget(UserProfileManager);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(340, 80, 160, 321));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_5 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_5->setObjectName("lineEdit_5");

        verticalLayout_2->addWidget(lineEdit_5);

        lineEdit = new QLineEdit(verticalLayoutWidget_2);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_2->setObjectName("lineEdit_2");

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout_2->addWidget(lineEdit_3);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_4->setObjectName("lineEdit_4");

        verticalLayout_2->addWidget(lineEdit_4);

        label_gif->raise();
        label->raise();
        pushButton->raise();
        verticalLayoutWidget->raise();
        verticalLayoutWidget_2->raise();

        retranslateUi(UserProfileManager);

        QMetaObject::connectSlotsByName(UserProfileManager);
    } // setupUi

    void retranslateUi(QWidget *UserProfileManager)
    {
        UserProfileManager->setWindowTitle(QCoreApplication::translate("UserProfileManager", "Form", nullptr));
        label->setText(QCoreApplication::translate("UserProfileManager", "\350\256\276\347\275\256\344\275\240\347\232\204\345\244\264\345\203\217", nullptr));
        pushButton->setText(QCoreApplication::translate("UserProfileManager", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        label_gif->setText(QCoreApplication::translate("UserProfileManager", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("UserProfileManager", "\346\230\265\347\247\260", nullptr));
        label_2->setText(QCoreApplication::translate("UserProfileManager", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("UserProfileManager", "\351\202\256\347\256\261", nullptr));
        label_4->setText(QCoreApplication::translate("UserProfileManager", "\347\224\265\350\257\235", nullptr));
        label_5->setText(QCoreApplication::translate("UserProfileManager", "\347\255\276\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserProfileManager: public Ui_UserProfileManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPROFILEMANAGER_H
