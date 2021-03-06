#include "paintarea.h"
#include <qpainter.h>

PaintArea::PaintArea(QWidget *parent) :
	QWidget(parent)
{
	setPalette(QPalette(Qt::white));
	setAutoFillBackground(true);	//设置窗体的背景色,白色
	setMinimumSize(400, 400);		//设置最小大小
}

void PaintArea::setShape(Shape s)
{
	shape = s;
	update();
}

void PaintArea::setPen(QPen p)
{
	pen = p;
	update();
}

void PaintArea::setBrush(QBrush b)
{
	brush = b;
	update();
}

void PaintArea::setFillRule(Qt::FillRule rule)
{
	fillRule = rule;
	update();		//重画绘制区窗体
}

void PaintArea::paintEvent(QPaintEvent *)
{
	QPainter p(this);		//创建一个QPainter对象						
	p.setPen(pen);			//设置QPainter对象的画笔和画刷
	p.setBrush(brush);

	QRect rect(50, 100, 300, 200);	//设置一个方形区域，为画长方形，圆角方形等做准备

	static const QPoint points[4] =	//创建一个QPoint的数组，包含四个点，为画多边形，多变线及点做准备
	{
		QPoint(150, 100),
		QPoint(300, 150),
		QPoint(350, 250),
		QPoint(100, 300)
	};
	int startAngle = 30 * 16;	//起始角
	int spanAngle = 120 * 16;	//跨度角

	QPainterPath path;			//
	path.addRect(150, 150, 100, 100);
	path.moveTo(100, 100);
	path.cubicTo(300, 100, 200, 200, 300, 300);
	path.cubicTo(100, 300, 200, 200, 100, 100);
	path.setFillRule(fillRule);

	switch (shape)
	{
	case Line:		//直线
		p.drawLine(rect.topLeft(), rect.bottomRight()); break;
	case Rectangle:	//长方形
		p.drawRect(rect); break;
	case RoundRect:	//圆角方形	
		p.drawRoundRect(rect); break;
	case Ellipse:	//椭圆
		p.drawEllipse(rect); break;
	case Polygon:	//多边形
		p.drawPolygon(points, 4); break;
	case Polyline:	//多边线
		p.drawPolyline(points, 4); break;
	case Points:	//点
		p.drawPoints(points, 4); break;
	case Arc:		//弧
		p.drawArc(rect, startAngle, spanAngle); break;
	case Path:		//路径	
		p.drawPath(path); break;
	case Text:		//文字
		p.drawText(rect, Qt::AlignCenter, tr("Hello Qt!")); break;
	case Pixmap:	//图片
		p.drawPixmap(0, 0, QPixmap("226.png")); break;
	default:	break;
	}
}