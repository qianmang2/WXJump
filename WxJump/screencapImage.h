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
	void jumpFinish(); //�������һ���ź�

public slots:
	void showImage();

private:
	Utils *utils;
	Mat inputImage; //ԭͼ��
	Mat character; //С�˵�ģ��
	Mat cutImage;
	Point characterBottomCenter; //С�˵ĵײ����ĵ�
	Rect characterLocation; //С�˵�λ��
	Point topPosition; //��һĿ����˵�����
	Point anotherPoint; //��һĿ�����һ����Ե������
	Point nextCenterPoint; //��һλ�õ����ĵ�
	bool isLeftDst; //Ŀ��λ���Ƿ���С�˵����
	QLabel *imageLabel;

};