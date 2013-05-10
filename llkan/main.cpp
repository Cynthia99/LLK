#include <QApplication>
#include <QTextCodec>
#include "mainwidget.h"
#include <QDesktopWidget>

int main(int argc, char * argv[])
{
    QApplication app(argc,argv);

    QPixmap p(":/images/llk.jpg");
    QSplashScreen s(p);
    s.show();
    app.processEvents();

    QTranslator translator;
    translator.load("pintu_zh");
    app.installTranslator(&translator);

    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));

    MainWidget w;
    w.show();
    w.move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
    s.finish(&w);

    return app.exec();
}
