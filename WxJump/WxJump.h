#pragma once

#include <QtWidgets/QWidget>
#include "ui_WxJump.h"
#include "QLabel"
class WxJump : public QWidget
{
	Q_OBJECT

public:
	WxJump(QWidget *parent = Q_NULLPTR);
	void autoJump();
private:
	Ui::WxJumpClass ui;
	QPushButton *btnAutoJump;
	QPushButton *btnManualJump;
	QLabel *screenImg;
};
