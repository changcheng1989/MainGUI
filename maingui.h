#ifndef MAINGUI_H
#define MAINGUI_H


#include <QSignalMapper>
#include <QMessageBox>
#include <QtGui/QWidget>
#include <QtCore/qmath.h>
#include <QMouseEvent>
#include <QPalette>
#include <QMenu>
#include <QAction>
#include <QWidget>
#include "ui_maingui.h"
#include "picwidget.h"
class MainGUI : public QWidget
{
    Q_OBJECT

public:
    explicit MainGUI(QWidget *parent = 0);
public slots:
    void showPicWidget();
    void showMaxRestore();
private:
    Ui::MainGUI ui;

    QSignalMapper *signalMapper;

    QPoint move_point; //移动的距离
    bool mouse_press; //鼠标按下
    bool maxNormal;
    QPixmap closePix;
    QPixmap maxPix;
    QPixmap restorePix;
    QPixmap minPix;
    QMenu *picMenu;
    QAction *picChangeAction;

    picWidget *picwidget;
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event);

    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);

    //鼠标移动事件

    void mouseMoveEvent(QMouseEvent *event);



};

#endif // MAINGUI_H
