/********************************************************************************
** Form generated from reading UI file 'readermanager.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READERMANAGER_H
#define UI_READERMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_readerManager
{
public:
    QFrame *line;
    QLabel *userManager;
    QPushButton *AddpushButton;
    QTableView *readerInformationtableView;
    QPushButton *searchpushButton;
    QPushButton *AllpushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *readerSearchLineEdit;
    QLabel *label_2;
    QLineEdit *phoneSearchLineEdit;
    QLabel *label;
    QLineEdit *emailSearchLineEdit;

    void setupUi(QWidget *readerManager)
    {
        if (readerManager->objectName().isEmpty())
            readerManager->setObjectName("readerManager");
        readerManager->resize(1100, 700);
        line = new QFrame(readerManager);
        line->setObjectName("line");
        line->setGeometry(QRect(41, 161, 911, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        userManager = new QLabel(readerManager);
        userManager->setObjectName("userManager");
        userManager->setGeometry(QRect(50, 0, 141, 61));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        userManager->setFont(font);
        AddpushButton = new QPushButton(readerManager);
        AddpushButton->setObjectName("AddpushButton");
        AddpushButton->setGeometry(QRect(40, 60, 93, 29));
        readerInformationtableView = new QTableView(readerManager);
        readerInformationtableView->setObjectName("readerInformationtableView");
        readerInformationtableView->setGeometry(QRect(40, 190, 931, 471));
        searchpushButton = new QPushButton(readerManager);
        searchpushButton->setObjectName("searchpushButton");
        searchpushButton->setGeometry(QRect(681, 111, 93, 29));
        AllpushButton = new QPushButton(readerManager);
        AllpushButton->setObjectName("AllpushButton");
        AllpushButton->setGeometry(QRect(860, 110, 93, 29));
        horizontalLayoutWidget = new QWidget(readerManager);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(40, 110, 631, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        readerSearchLineEdit = new QLineEdit(horizontalLayoutWidget);
        readerSearchLineEdit->setObjectName("readerSearchLineEdit");

        horizontalLayout->addWidget(readerSearchLineEdit);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        phoneSearchLineEdit = new QLineEdit(horizontalLayoutWidget);
        phoneSearchLineEdit->setObjectName("phoneSearchLineEdit");

        horizontalLayout->addWidget(phoneSearchLineEdit);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        emailSearchLineEdit = new QLineEdit(horizontalLayoutWidget);
        emailSearchLineEdit->setObjectName("emailSearchLineEdit");

        horizontalLayout->addWidget(emailSearchLineEdit);


        retranslateUi(readerManager);

        QMetaObject::connectSlotsByName(readerManager);
    } // setupUi

    void retranslateUi(QWidget *readerManager)
    {
        readerManager->setWindowTitle(QCoreApplication::translate("readerManager", "readerManager", nullptr));
        userManager->setText(QCoreApplication::translate("readerManager", "\350\257\273\350\200\205\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        AddpushButton->setText(QCoreApplication::translate("readerManager", "\342\236\225\346\267\273\345\212\240", nullptr));
        searchpushButton->setText(QCoreApplication::translate("readerManager", "\346\237\245\350\257\242\360\237\224\215", nullptr));
        AllpushButton->setText(QCoreApplication::translate("readerManager", "\345\205\250\351\203\250", nullptr));
        label_3->setText(QCoreApplication::translate("readerManager", "\347\224\250\346\210\266\345\220\215", nullptr));
        readerSearchLineEdit->setText(QString());
        label_2->setText(QCoreApplication::translate("readerManager", "\346\211\213\346\234\272\345\217\267", nullptr));
        phoneSearchLineEdit->setText(QString());
#if QT_CONFIG(accessibility)
        label->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        label->setText(QCoreApplication::translate("readerManager", "\347\224\265\345\255\220\351\202\256\347\256\261", nullptr));
        emailSearchLineEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class readerManager: public Ui_readerManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READERMANAGER_H
