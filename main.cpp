#include <QApplication>
#include "mainwindow.h"
#if defined _MSC_VER
#pragma comment(lib, "OPENGL32.lib")
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if defined USE_FORCE_GL
    a.setAttribute(Qt::AA_UseDesktopOpenGL);
#endif

    MainWindow w;

    w.setWindowTitle("Fuzzy Logic Regression 2.1");
    w.show();

    return a.exec();
}
