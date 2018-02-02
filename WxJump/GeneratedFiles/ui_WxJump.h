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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WxJumpClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QPushButton *autoJump;
    QPushButton *manualJump;
    QLabel *screenImg;

    void setupUi(QWidget *WxJumpClass)
    {
        if (WxJumpClass->objectName().isEmpty())
            WxJumpClass->setObjectName(QStringLiteral("WxJumpClass"));
        WxJumpClass->resize(348, 482);
        verticalLayout = new QVBoxLayout(WxJumpClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        autoJump = new QPushButton(WxJumpClass);
        autoJump->setObjectName(QStringLiteral("autoJump"));

        gridLayout_2->addWidget(autoJump, 1, 0, 1, 1);

        manualJump = new QPushButton(WxJumpClass);
        manualJump->setObjectName(QStringLiteral("manualJump"));

        gridLayout_2->addWidget(manualJump, 1, 1, 1, 1);

        screenImg = new QLabel(WxJumpClass);
        screenImg->setObjectName(QStringLiteral("screenImg"));
        screenImg->setMinimumSize(QSize(320, 480));
        screenImg->setMaximumSize(QSize(1024, 2000));
        screenImg->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(screenImg, 0, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(WxJumpClass);

        QMetaObject::connectSlotsByName(WxJumpClass);
    } // setupUi

    void retranslateUi(QWidget *WxJumpClass)
    {
        WxJumpClass->setWindowTitle(QApplication::translate("WxJumpClass", "WxJump", nullptr));
        autoJump->setText(QApplication::translate("WxJumpClass", "\350\207\252\345\212\250", nullptr));
        manualJump->setText(QApplication::translate("WxJumpClass", "\346\211\213\345\212\250", nullptr));
        screenImg->setText(QApplication::translate("WxJumpClass", "\350\257\267\347\250\215\345\200\231...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WxJumpClass: public Ui_WxJumpClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WXJUMP_H
