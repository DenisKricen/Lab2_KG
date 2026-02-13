#include <QWindow>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    
    QWindow window;
    window.setTitle("Lab 1 - Yooo brooo");
    window.resize(800, 600);
    window.show();

    return app.exec();
}