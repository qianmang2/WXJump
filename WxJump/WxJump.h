#pragma once

#include <QtWidgets/QWidget>
#include "ui_WxJump.h"
#include "QLabel"
#include "screencapImage.h"
#include "QThread"
class WxJump : public QWidget
{
	Q_OBJECT

public:
	WxJump(QWidget *parent = Q_NULLPTR);
	void JumpOne();
	void showImage();
private:
	Ui::WxJumpClass ui;
	QPushButton *btnAutoJump;
	QPushButton *btnManualJump;
	QLabel *screenImg;
	ScreencapImage *screen;
};
