#include "maingui.h"
#include <QTextCodec>
MainGUI::MainGUI(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    this->setWindowFlags(Qt::FramelessWindowHint /*| Qt::WindowStaysOnTopHint*/);

    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
   ui.closeButton->setIcon(closePix);

    QPixmap maxPix = style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
    ui.maxButton->setIcon(maxPix);

    QPixmap restorePix = style()->standardPixmap(QStyle::SP_TitleBarNormalButton);

    QPixmap minPix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    ui.minButton->setIcon(minPix);

    QPixmap picPix = style()->standardPixmap(QStyle::SP_TitleBarUnshadeButton);
    ui.picButton->setIcon(picPix);





    ui.minButton->setStyleSheet("background-color:transparent;");
    ui.minButton->setFocusPolicy(Qt::NoFocus);
    ui.closeButton->setStyleSheet("background-color:transparent;");
    ui.closeButton->setFocusPolicy(Qt::NoFocus);
    ui.maxButton->setStyleSheet("background-color:transparent;");
    ui.maxButton->setFocusPolicy(Qt::NoFocus);

    ui.picButton->setStyleSheet("background-color:transparent;");
    ui.picButton->setFocusPolicy(Qt::NoFocus);

    maxNormal =false;
    connect(ui.minButton,SIGNAL(clicked()),this,SLOT(showMinimized()));
    connect(ui.closeButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui.maxButton,SIGNAL(clicked()),this,SLOT(showMaxRestore() ));


    int index[13]={0,1,2,3,4,5,6,7,8,9,10,11,12};
    signalMapper = new QSignalMapper(this);

    connect(ui.jhToolBox->toolButton1_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton1_1, index[0]);

    connect(ui.jhToolBox->toolButton1_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton1_2, index[1]);

    connect(ui.jhToolBox->toolButton2_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton2_1, index[2]);

    connect(ui.jhToolBox->toolButton2_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton2_2, index[3]);

    connect(ui.jhToolBox->toolButton3_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton3_1, index[4]);

    connect(ui.jhToolBox->toolButton3_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton3_2, index[5]);

    connect(ui.jhToolBox->toolButton4_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton4_1, index[6]);

    connect(ui.jhToolBox->toolButton4_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton4_2, index[7]);

    connect(ui.jhToolBox->toolButton4_3, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton4_3, index[8]);

    connect(ui.jhToolBox->toolButton5_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton5_1, index[9]);

    connect(ui.jhToolBox->toolButton5_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton5_2, index[10]);

    connect(ui.jhToolBox->toolButton6_1, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton6_1, index[11]);

    connect(ui.jhToolBox->toolButton6_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    signalMapper->setMapping(ui.jhToolBox->toolButton6_2, index[12]);


    connect(signalMapper, SIGNAL(mapped(int)),ui.stackedWidget,SLOT(setCurrentIndex(int)));
    connect(ui.picButton,SIGNAL(clicked()),this,SLOT(showPicWidget()));






    QPixmap pixmap(":/MainGUI/pic/6.jpg");
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(pixmap));
    this->setPalette(palette);

    this->setAutoFillBackground(true);



}
void MainGUI::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mouse_press = true;

        //鼠标相对于窗体的位置（或者使用event->globalPos() - this->pos()）
        move_point = event->pos();;

    }

}

void MainGUI::mouseMoveEvent(QMouseEvent *event)
{
    //若鼠标左键被按下
    if(mouse_press)
    {
        //鼠标相对于屏幕的位置
        QPoint move_pos = event->globalPos();

        //移动主窗体位置
        this->move(move_pos - move_point);
    }

}

void MainGUI::mouseReleaseEvent(QMouseEvent *event)
{
    //设置鼠标为未被按下
    mouse_press = false;
}

void MainGUI::showMaxRestore()

{

    if (maxNormal) {

        /*ui->maxButton->setIcon(maxPix);  */
        this->showNormal();

        maxNormal = !maxNormal;



    }

    else {

        /*ui->maxButton->setIcon(restorePix);*/
        this->showMaximized();

        maxNormal = !maxNormal;



    }

}

void MainGUI::showPicWidget()
{
    picwidget = new picWidget();
    picwidget->m_pParent = this->ui.frame;
    picwidget->setWindowModality(Qt::ApplicationModal);
    picwidget->show();


}
