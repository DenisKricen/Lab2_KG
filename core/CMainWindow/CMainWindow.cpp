#include "CMainWindow.h"
#include "ui_CMainWindow.h"
#include <QPainter>

CMainWindow::CMainWindow(QWidget *parent) : QWidget(parent), ui(new Ui::CMainWindow) {
    ui->setupUi(this);
}

CMainWindow::~CMainWindow() {
    delete ui; // Обов'язково чистимо пам'ять
}

void CMainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::red, 3));
    painter.drawLine(20, 20, 200, 200);
}

void CMainWindow::onAddTriangleClicked() {
    // TODO: Реалізувати додавання фігури на сцену.
}

void CMainWindow::onDrawClicked() {
    // TODO: Реалізувати малювання.
}

void CMainWindow::onClearClicked() {
    // TODO: Реалізувати очищення.
}

