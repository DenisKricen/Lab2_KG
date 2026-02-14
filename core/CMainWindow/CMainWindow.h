#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QGraphicsView>
#include <QPushButton>
#include <QPainter>
#include <QPaintEvent>
#include "../CScene/CScene.h"    
#include "../CFigure/CFigure.h"  

namespace Ui {
class CMainWindow;
}

class CMainWindow : public QWidget {
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

protected:

    virtual void paintEvent(QPaintEvent *event) override;

private slots:

    void onAddTriangleClicked();
    void onDrawClicked();
    void onClearClicked();

private:
    Ui::CMainWindow *ui;
};

#endif // MAINWINDOW_H