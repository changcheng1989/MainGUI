#include "picwidget.h"
#define W_ICONSIZE 150
#define H_ICONSIZE 150
#define H_ITEMSIZE 150
picWidget::picWidget(QWidget *parent)
	: QWidget(parent)
{
	m_pParent = NULL;

	ui.setupUi(this);
	
	//设置QListWidget中的单元项的图片大小
	ui.listWidget->setIconSize(QSize(W_ICONSIZE, H_ICONSIZE));
	ui.listWidget->setResizeMode(QListView::Adjust);
	//设置QListWidget的显示模式
	ui.listWidget->setViewMode(QListView::IconMode);
	//设置QListWidget中的单元项不可被拖动
	ui.listWidget->setMovement(QListView::Static);
	//设置QListWidget中的单元项的间距
	ui.listWidget->setSpacing(10);

	//依次创建11个单元项
	for(int nIndex = 0;nIndex<6;++nIndex)
	{
		//获得图片路径
        strPath=QString(":/MainGUI/pic/%1.jpg").arg(nIndex+1);
		//生成图像objPixmap
		QPixmap objPixmap(strPath);
		//生成QListWidgetItem对象(注意：其Icon图像进行了伸缩[96*96])---scaled函数
		QListWidgetItem *pItem = new QListWidgetItem(QIcon(objPixmap.scaled(QSize(W_ICONSIZE,H_ICONSIZE))),"animal tiger pig");
		//设置单元项的宽度和高度
		pItem->setSizeHint(QSize(W_ICONSIZE,H_ITEMSIZE));
		ui.listWidget->insertItem(nIndex, pItem);

	}


	//设置信号槽
	 connect(ui.listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(Slot_ItemClicked(QListWidgetItem*)));

	//strPath = "";

	this->setWindowTitle(tr("换肤"));



}

void picWidget::SetBgImage(const QString &strPath)
{


	QPixmap pixmap(strPath);

	QPalette palette;
	palette.setBrush(m_pParent->backgroundRole(),QBrush(pixmap));
	m_pParent->setPalette(palette);
	
	m_pParent->setAutoFillBackground(true);
	m_pParent->show();


}

//槽函数
void picWidget::Slot_ItemClicked(QListWidgetItem * item)
{
	if(!item)
	{
		return;
	}
	int nRowIndex = ui.listWidget->row(item);

    strPath=QString(":/MainGUI/pic/%1.jpg").arg(nRowIndex+1);
	update();
}
void picWidget::paintEvent (QPaintEvent * event)
{
	SetBgImage(strPath);
}

picWidget::~picWidget()
{

}

