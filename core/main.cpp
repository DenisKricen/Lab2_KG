#include <QApplication>
#include <QString>
#include "CMainWindow/CMainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int randomPoints = 0;
    for (int i = 1; i < argc; ++i) {
        QString arg(argv[i]);
        if ((arg == "--random" || arg == "-r") && i + 1 < argc) {
            randomPoints = QString(argv[++i]).toInt();
        }
    }

    CMainWindow w(nullptr, randomPoints);
    w.show();

    return app.exec();
}