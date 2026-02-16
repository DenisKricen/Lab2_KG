#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QWidget>
#include "CScene/CScene.h"    
#include "CCanvas/CCanvas.h"
#include "Figures/CFigure/CFigure.h"

namespace Ui {
    class CMainWindow;
}

class CMainWindow : public QWidget {
    Q_OBJECT
private:
    CScene* scene;
    CCanvas* canvas;
    Ui::CMainWindow *ui;

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

private slots:
    void onCreateClicked();
    void onClearClicked();
};

#endif // CMAINWINDOW_H