#ifndef PICWIDGET_H
#define PICWIDGET_H

#include <QWidget>
#include <QSize>
#include <QListView>
#include <QString>
#include <QPainter>
#include "ui_picwidget.h"

class picWidget : public QWidget
{
	Q_OBJECT
//SIGNAL:
//	sendToFather();
public:
	picWidget(QWidget *parent = 0);
	~picWidget();
	void SetBgImage(const QString &strPath);
	void paintEvent (QPaintEvent * event);
	QWidget* m_pParent;
public slots:
	void Slot_ItemClicked(QListWidgetItem * item);

	

private:
	Ui::picWidget ui;
	QString strPath;


};

#endif // PICWIDGET_H
