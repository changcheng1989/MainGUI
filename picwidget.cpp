#include "picwidget.h"
#define W_ICONSIZE 150
#define H_ICONSIZE 150
#define H_ITEMSIZE 150
picWidget::picWidget(QWidget *parent)
	: QWidget(parent)
{
	m_pParent = NULL;

	ui.setupUi(this);
	
	//����QListWidget�еĵ�Ԫ���ͼƬ��С
	ui.listWidget->setIconSize(QSize(W_ICONSIZE, H_ICONSIZE));
	ui.listWidget->setResizeMode(QListView::Adjust);
	//����QListWidget����ʾģʽ
	ui.listWidget->setViewMode(QListView::IconMode);
	//����QListWidget�еĵ�Ԫ��ɱ��϶�
	ui.listWidget->setMovement(QListView::Static);
	//����QListWidget�еĵ�Ԫ��ļ��
	ui.listWidget->setSpacing(10);

	//���δ���11����Ԫ��
	for(int nIndex = 0;nIndex<6;++nIndex)
	{
		//���ͼƬ·��
        strPath=QString(":/MainGUI/pic/%1.jpg").arg(nIndex+1);
		//����ͼ��objPixmap
		QPixmap objPixmap(strPath);
		//����QListWidgetItem����(ע�⣺��Iconͼ�����������[96*96])---scaled����
		QListWidgetItem *pItem = new QListWidgetItem(QIcon(objPixmap.scaled(QSize(W_ICONSIZE,H_ICONSIZE))),"animal tiger pig");
		//���õ�Ԫ��Ŀ�Ⱥ͸߶�
		pItem->setSizeHint(QSize(W_ICONSIZE,H_ITEMSIZE));
		ui.listWidget->insertItem(nIndex, pItem);

	}


	//�����źŲ�
	 connect(ui.listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(Slot_ItemClicked(QListWidgetItem*)));

	//strPath = "";

	this->setWindowTitle(tr("����"));



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

//�ۺ���
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

