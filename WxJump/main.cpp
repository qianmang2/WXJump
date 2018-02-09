#include "WxJump.h"
#include <QtWidgets/QApplication>
#include "QIcon"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WxJump w;
	w.setWindowTitle(QString::fromLocal8Bit("ÌøÒ»Ìø¸¨Öú By:Ç®äÝ"));
	QIcon icon;
	icon.addFile("cat.ico");
	w.setWindowIcon(icon);
	w.show();
	return a.exec();
}
