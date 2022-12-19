/********************************************************************************
** Form generated from reading UI file 'bookinformationmanagermodifydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINFORMATIONMANAGERMODIFYDIALOG_H
#define UI_BOOKINFORMATIONMANAGERMODIFYDIALOG_H

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

class Ui_BookInformationManagerModifyDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *BookNUMlineEdit;
    QComboBox *BookTypedepcbBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *BookIDlineEdit;
    QLineEdit *PublisherlineEdit;
    QLabel *label_6;
    QLineEdit *NumberlineEdit;
    QLineEdit *WriterlineEdit;
    QLabel *label_4;
    QFrame *line;
    QLabel *label_7;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_8;
    QLineEdit *BookNamelineEdit;
    QLabel *label_5;
    QLineEdit *PublishTimelineEdit;
    QLabel *label_9;

    void setupUi(QDialog *BookInformationManagerModifyDialog)
    {
        if (BookInformationManagerModifyDialog->objectName().isEmpty())
            BookInformationManagerModifyDialog->setObjectName("BookInformationManagerModifyDialog");
        BookInformationManagerModifyDialog->resize(438, 332);
        buttonBox = new QDialogButtonBox(BookInformationManagerModifyDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        BookNUMlineEdit = new QLineEdit(BookInformationManagerModifyDialog);
        BookNUMlineEdit->setObjectName("BookNUMlineEdit");
        BookNUMlineEdit->setGeometry(QRect(80, 110, 113, 21));
        BookTypedepcbBox = new QComboBox(BookInformationManagerModifyDialog);
        BookTypedepcbBox->setObjectName("BookTypedepcbBox");
        BookTypedepcbBox->setGeometry(QRect(220, 170, 161, 21));
        label_2 = new QLabel(BookInformationManagerModifyDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 51, 21));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label_3 = new QLabel(BookInformationManagerModifyDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(210, 50, 51, 21));
        label_3->setFont(font);
        label = new QLabel(BookInformationManagerModifyDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 10, 71, 21));
        label->setFont(font);
        BookIDlineEdit = new QLineEdit(BookInformationManagerModifyDialog);
        BookIDlineEdit->setObjectName("BookIDlineEdit");
        BookIDlineEdit->setGeometry(QRect(270, 110, 113, 21));
        PublisherlineEdit = new QLineEdit(BookInformationManagerModifyDialog);
        PublisherlineEdit->setObjectName("PublisherlineEdit");
        PublisherlineEdit->setGeometry(QRect(82, 220, 111, 21));
        label_6 = new QLabel(BookInformationManagerModifyDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 170, 71, 21));
        label_6->setFont(font);
        NumberlineEdit = new QLineEdit(BookInformationManagerModifyDialog);
        NumberlineEdit->setObjectName("NumberlineEdit");
        NumberlineEdit->setGeometry(QRect(100, 170, 41, 21));
        WriterlineEdit = new QLineEdit(BookInformationManagerModifyDialog);
        WriterlineEdit->setObjectName("WriterlineEdit");
        WriterlineEdit->setGeometry(QRect(270, 50, 113, 21));
        label_4 = new QLabel(BookInformationManagerModifyDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 110, 51, 21));
        label_4->setFont(font);
        line = new QFrame(BookInformationManagerModifyDialog);
        line->setObjectName("line");
        line->setGeometry(QRect(130, 12, 251, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(BookInformationManagerModifyDialog);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(150, 170, 71, 21));
        label_7->setFont(font);
        line_2 = new QFrame(BookInformationManagerModifyDialog);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(20, 10, 21, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(BookInformationManagerModifyDialog);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(20, 250, 361, 20));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(BookInformationManagerModifyDialog);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 110, 51, 21));
        label_8->setFont(font);
        BookNamelineEdit = new QLineEdit(BookInformationManagerModifyDialog);
        BookNamelineEdit->setObjectName("BookNamelineEdit");
        BookNamelineEdit->setGeometry(QRect(80, 50, 111, 21));
        label_5 = new QLabel(BookInformationManagerModifyDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 220, 51, 21));
        label_5->setFont(font);
        PublishTimelineEdit = new QLineEdit(BookInformationManagerModifyDialog);
        PublishTimelineEdit->setObjectName("PublishTimelineEdit");
        PublishTimelineEdit->setGeometry(QRect(290, 220, 91, 21));
        label_9 = new QLabel(BookInformationManagerModifyDialog);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(210, 220, 81, 21));
        label_9->setFont(font);

        retranslateUi(BookInformationManagerModifyDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, BookInformationManagerModifyDialog, qOverload<>(&QDialog::reject));
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, BookInformationManagerModifyDialog, qOverload<>(&QDialog::accept));

        QMetaObject::connectSlotsByName(BookInformationManagerModifyDialog);
    } // setupUi

    void retranslateUi(QDialog *BookInformationManagerModifyDialog)
    {
        BookInformationManagerModifyDialog->setWindowTitle(QCoreApplication::translate("BookInformationManagerModifyDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("BookInformationManagerModifyDialog", "\345\233\276\344\271\246\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("BookInformationManagerModifyDialog", "\344\275\234\350\200\205\345\220\215", nullptr));
        label->setText(QCoreApplication::translate("BookInformationManagerModifyDialog", "\345\233\276\344\271\246\344\277\241\346\201\257", nullptr));
        label_6->setText(QCoreApplication::translate("BookInformationManagerModifyDialog", "\345\233\276\344\271\246\346\225\260\351\207\217", nullptr));
        label_4->setText(QCoreApplication::translate("BookInformationManagerModifyDialog", "\345\233\276\344\271\246ID", nullptr));
        label_7->setText(QCoreApplication::translate("BookInformationManagerModifyDialog", "\345\233\276\344\271\246\347\261\273\345\236\213", nullptr));
        label_8->setText(QCoreApplication::translate("BookInformationManagerModifyDialog", "\345\233\276\344\271\246\345\217\267", nullptr));
        label_5->setText(QCoreApplication::translate("BookInformationManagerModifyDialog", "\345\207\272\347\211\210\347\244\276", nullptr));
        label_9->setText(QCoreApplication::translate("BookInformationManagerModifyDialog", "\345\207\272\347\211\210\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookInformationManagerModifyDialog: public Ui_BookInformationManagerModifyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINFORMATIONMANAGERMODIFYDIALOG_H
