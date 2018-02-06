#include "WxJump.h"
#include "screencapImage.h"
#include "QDebug"
#include "QThread"
#include "QDebug"

WxJump::WxJump(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	screenImg = ui.screenImg;
	btnAutoJump = ui.autoJump;
	btnManualJump = ui.manualJump;

	screen = new ScreencapImage(screenImg);
	showImage();
	connect(btnAutoJump, &QPushButton::released, this, &WxJump::JumpOne);
	connect(btnManualJump, &QPushButton::released, this, &WxJump::showImage);

	connect(screen, &ScreencapImage::jumpFinish, this, &WxJump::showImage);
	qDebug() << "Wx_currentThreadId1:" << QThread::currentThreadId();
}

void WxJump::JumpOne() {
	screen->jump();
	qDebug() << "Wx_currentThreadId2:" << QThread::currentThreadId();
}

void WxJump::showImage() {
	
	QThread *thread_ = new QThread;
	screen->moveToThread(thread_);
	thread_->start();
	connect(thread_, &QThread::started, screen, &ScreencapImage::showImage);

}