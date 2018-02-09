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

	screen = new ScreencapImage(screenImg, btnAutoJump);
	showImage();

	connect(btnAutoJump, &QPushButton::released, this, &WxJump::JumpOne); //跳一下
	connect(btnManualJump, &QPushButton::released, this, &WxJump::showImage); //重新获取图片并显示
	connect(screen, &ScreencapImage::jumpFinish, this, &WxJump::showImage); //跳跃完后显示图片
	connect(screen, &ScreencapImage::showImageFinish, this, [&]() {
		btnAutoJump->setEnabled(true);
	});

	qDebug() << "WxJump:currentThreadId:" << QThread::currentThreadId();
}

void WxJump::JumpOne() {
	btnAutoJump->setEnabled(false);
	screen->jump();
//	qDebug() << "Wx_currentThreadId2:" << QThread::currentThreadId();
}

void WxJump::showImage() {
	
	QThread *thread_ = new QThread;
	screen->moveToThread(thread_);
	thread_->start();
	connect(thread_, &QThread::started, screen, &ScreencapImage::showImage);
	
}