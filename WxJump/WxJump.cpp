#include "WxJump.h"
#include "screencapImage.h"
#include "QDebug"
WxJump::WxJump(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	screenImg = ui.screenImg;
	btnAutoJump = ui.autoJump;
	connect(btnAutoJump, &QPushButton::released, this, &WxJump::autoJump);
	btnManualJump = ui.manualJump;

}

void WxJump::autoJump() {
	QThread *thread = new QThread();
	ScreencapImage *screen = new ScreencapImage();
	screen->start();

	connect(screen, &ScreencapImage::picInitFinish, [=]( Mat &src) {
		Utils utils;
		utils.displayResult(screenImg, src); //œ‘ æÕº∆¨
	});
}