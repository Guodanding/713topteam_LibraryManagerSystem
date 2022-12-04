/********************************************************************************
** Form generated from reading UI file 'bookinformationmanageradddatadialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINFORMATIONMANAGERADDDATADIALOG_H
#define UI_BOOKINFORMATIONMANAGERADDDATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_BookInformationManagerAddDataDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *depcbBox;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_6;

    void setupUi(QDialog *BookInformationManagerAddDataDialog)
    {
        if (BookInformationManagerAddDataDialog->objectName().isEmpty())
            BookInformationManagerAddDataDialog->setObjectName("BookInformationManagerAddDataDialog");
        BookInformationManagerAddDataDialog->resize(399, 300);
        buttonBox = new QDialogButtonBox(BookInformationManagerAddDataDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(40, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(BookInformationManagerAddDataDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 10, 71, 21));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        line = new QFrame(BookInformationManagerAddDataDialog);
        line->setObjectName("line");
        line->setGeometry(QRect(130, 12, 251, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(BookInformationManagerAddDataDialog);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(20, 10, 21, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(BookInformationManagerAddDataDialog);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(20, 250, 361, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        lineEdit = new QLineEdit(BookInformationManagerAddDataDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 50, 111, 21));
        lineEdit_2 = new QLineEdit(BookInformationManagerAddDataDialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(270, 50, 113, 21));
        lineEdit_3 = new QLineEdit(BookInformationManagerAddDataDialog);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(270, 110, 113, 21));
        lineEdit_4 = new QLineEdit(BookInformationManagerAddDataDialog);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(100, 170, 31, 21));
        lineEdit_5 = new QLineEdit(BookInformationManagerAddDataDialog);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(82, 220, 301, 21));
        label_2 = new QLabel(BookInformationManagerAddDataDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 51, 21));
        label_2->setFont(font);
        label_3 = new QLabel(BookInformationManagerAddDataDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 50, 51, 21));
        label_3->setFont(font);
        label_4 = new QLabel(BookInformationManagerAddDataDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 110, 51, 21));
        label_4->setFont(font);
        label_5 = new QLabel(BookInformationManagerAddDataDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 220, 51, 21));
        label_5->setFont(font);
        label_6 = new QLabel(BookInformationManagerAddDataDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 170, 71, 21));
        label_6->setFont(font);
        depcbBox = new QComboBox(BookInformationManagerAddDataDialog);
        depcbBox->setObjectName("depcbBox");
        depcbBox->setGeometry(QRect(220, 170, 161, 21));
        label_7 = new QLabel(BookInformationManagerAddDataDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(150, 170, 71, 21));
        label_7->setFont(font);
        label_8 = new QLabel(BookInformationManagerAddDataDialog);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 110, 51, 21));
        label_8->setFont(font);
        lineEdit_6 = new QLineEdit(BookInformationManagerAddDataDialog);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(80, 110, 113, 21));

        retranslateUi(BookInformationManagerAddDataDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, BookInformationManagerAddDataDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, BookInformationManagerAddDataDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(BookInformationManagerAddDataDialog);
    } // setupUi

    void retranslateUi(QDialog *BookInformationManagerAddDataDialog)
    {
        BookInformationManagerAddDataDialog->setWindowTitle(QCoreApplication::translate("BookInformationManagerAddDataDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("BookInformationManagerAddDataDialog", "\345\233\276\344\271\246\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("BookInformationManagerAddDataDialog", "\345\233\276\344\271\246\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("BookInformationManagerAddDataDialog", "\344\275\234\350\200\205\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("BookInformationManagerAddDataDialog", "\345\233\276\344\271\246ID", nullptr));
        label_5->setText(QCoreApplication::translate("BookInformationManagerAddDataDialog", "\345\207\272\347\211\210\347\244\276", nullptr));
        label_6->setText(QCoreApplication::translate("BookInformationManagerAddDataDialog", "\345\233\276\344\271\246\346\225\260\351\207\217", nullptr));
        label_7->setText(QCoreApplication::translate("BookInformationManagerAddDataDialog", "\345\233\276\344\271\246\347\261\273\345\236\213", nullptr));
        label_8->setText(QCoreApplication::translate("BookInformationManagerAddDataDialog", "\345\233\276\344\271\246\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookInformationManagerAddDataDialog: public Ui_BookInformationManagerAddDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINFORMATIONMANAGERADDDATADIALOG_H
