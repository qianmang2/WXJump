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

	connect(btnAutoJump, &QPushButton::released, this, &WxJump::JumpOne); //��һ��
	connect(btnManualJump, &QPushButton::released, this, &WxJump::showImage); //���»�ȡͼƬ����ʾ
	connect(screen, &ScreencapImage::jumpFinish, this, &WxJump::showImage); //��Ծ�����ʾͼƬ
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