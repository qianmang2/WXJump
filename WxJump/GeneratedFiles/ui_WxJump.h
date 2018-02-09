/********************************************************************************
** Form generated from reading UI file 'WxJump.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WXJUMP_H
#define UI_WXJUMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WxJumpClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QLabel *screenImg;
    QPushButton *autoJump;
    QPushButton *manualJump;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *WxJumpClass)
    {
        if (WxJumpClass->objectName().isEmpty())
            WxJumpClass->setObjectName(QStringLiteral("WxJumpClass"));
        WxJumpClass->resize(665, 539);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../Desktop/timg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        WxJumpClass->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(WxJumpClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        screenImg = new QLabel(WxJumpClass);
        screenImg->setObjectName(QStringLiteral("screenImg"));
        screenImg->setMinimumSize(QSize(320, 480));
        screenImg->setMaximumSize(QSize(1024, 2000));
        screenImg->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(screenImg, 0, 0, 1, 2);

        autoJump = new QPushButton(WxJumpClass);
        autoJump->setObjectName(QStringLiteral("autoJump"));

        gridLayout_2->addWidget(autoJump, 1, 0, 1, 1);

        manualJump = new QPushButton(WxJumpClass);
        manualJump->setObjectName(QStringLiteral("manualJump"));

        gridLayout_2->addWidget(manualJump, 1, 1, 1, 1);

        plainTextEdit = new QPlainTextEdit(WxJumpClass);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout_2->addWidget(plainTextEdit, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(WxJumpClass);

        QMetaObject::connectSlotsByName(WxJumpClass);
    } // setupUi

    void retranslateUi(QWidget *WxJumpClass)
    {
        WxJumpClass->setWindowTitle(QApplication::translate("WxJumpClass", "WxJump", nullptr));
        screenImg->setText(QApplication::translate("WxJumpClass", "\350\257\267\347\250\215\345\200\231...", nullptr));
        autoJump->setText(QApplication::translate("WxJumpClass", "\350\267\263\344\270\200\344\270\213", nullptr));
        manualJump->setText(QApplication::translate("WxJumpClass", "\351\207\215\346\226\260\350\216\267\345\217\226\345\233\276\347\211\207", nullptr));
        plainTextEdit->setPlainText(QApplication::translate("WxJumpClass", "\344\275\277\347\224\250\350\257\264\346\230\216:\n"
"    \345\233\276\344\270\255\347\232\204\345\260\217\347\272\242\347\202\271\345\210\206\345\210\253\350\241\250\347\244\272\346\243\213\345\255\220\344\275\215\345\200\274\345\222\214\344\270\213\344\270\200\347\233\256\346\240\207\344\275\215\345\200\274.\345\246\202\346\236\234\344\270\213\344\270\200\347\233\256\346\240\207\344\275\215\345\200\274\344\270\215\345\207\206\347\241\256\357\274\214\345\217\257\344\273\245\351\200\232\350\277\207\347\202\271\345\207\273 \351\207\215\346\226\260\350\216\267\345\217\226\345\233\276\347\211\207 \346\214\211\351\222\256\345\260\235\350\257\225\350\247\243\345\206\263\343\200\202\n"
"\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WxJumpClass: public Ui_WxJumpClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WXJUMP_H
