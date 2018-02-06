#pragma once
#include "QObject"
#include "QLabel"
#include "QProcess"
#include "utils.h"
class ScreencapImage :public QObject{

	Q_OBJECT
public:
	ScreencapImage(QLabel *qLabel);
	~ScreencapImage();
	void initcharacterLocation();
	void jump();

signals:
	void screencapfinish();
signals:
	void jumpFinish(); //跳完后发送一个信号

public slots:
	void showImage();

private:
	Utils *utils;
	Mat inputImage; //原图像
	Mat character; //小人的模版
	Mat cutImage;
	Point characterBottomCenter; //小人的底部中心点
	Rect characterLocation; //小人的位置
	Point topPosition; //下一目标最顶端的坐标
	Point anotherPoint; //下一目标的另一个边缘的坐标
	Point nextCenterPoint; //下一位置的中心点
	bool isLeftDst; //目标位置是否在小人的左边
	QLabel *imageLabel;

};