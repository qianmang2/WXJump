#include "WxJump.h"
#include <QtWidgets/QApplication>
#include "QIcon"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WxJump w;
	w.setWindowTitle(QString::fromLocal8Bit("��һ������ By:Ǯ��"));
	QIcon icon;
	icon.addFile("cat.ico");
	w.setWindowIcon(icon);
	w.show();
	return a.exec();
}
