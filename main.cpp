#include "Controller/mainview.h"
#include <QApplication>

// dgb

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainView w;
    w.show();

    return a.exec();
}
