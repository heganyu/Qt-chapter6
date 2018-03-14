#include "MainWidget.h"

MainWidget::MainWidget(QWidget *parent)
	: QWidget(parent)
{
	paintArea = new PaintArea;

	shapeLabel = new QLabel(tr("��״"));
	shapeComboBox = new QComboBox;
	shapeComboBox->addItem(tr("Line"), PaintArea::Line);
	shapeComboBox->addItem(tr("Rectangle"), PaintArea::Rectangle);
	shapeComboBox->addItem(tr("RoundedRect"), PaintArea::RoundRect);
	shapeComboBox->addItem(tr("Ellipse"), PaintArea::Ellipse);
	shapeComboBox->addItem(tr("Polygon"), PaintArea::Polygon);
	shapeComboBox->addItem(tr("Polyline"), PaintArea::Polyline);
	shapeComboBox->addItem(tr("Points"), PaintArea::Points);
	shapeComboBox->addItem(tr("Arc"), PaintArea::Arc);
	shapeComboBox->addItem(tr("Path"), PaintArea::Path);
	shapeComboBox->addItem(tr("Text"), PaintArea::Text);
	shapeComboBox->addItem(tr("Pixmap"), PaintArea::Pixmap);

	connect(shapeComboBox, SIGNAL(activated(int)), this, SLOT(ShowShape(int)));

	penColorLabel = new QLabel(tr("������ɫ��"));
	penColorFrame = new QFrame;
	penColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	penColorFrame->setAutoFillBackground(true);
	penColorFrame->setPalette(QPalette(Qt::blue));
	penColorBtn = new QPushButton(tr("����"));

	connect(penColorBtn, SIGNAL(clicked()), this, SLOT(ShowPenColor()));

	penWidthLabel = new QLabel(tr("�����߿���"));
	penWidthSpinBox = new QSpinBox;
	penWidthSpinBox->setRange(0, 20);
	connect(penWidthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(ShowPenWidth(int)));

	penStyleLabel = new QLabel(tr("���ʷ��"));
	penStyleComboBox = new QComboBox;
	penStyleComboBox->addItem(tr("SolidLine"),
		static_cast<int>(Qt::SolidLine));
	penStyleComboBox->addItem(tr("DashLine"),
		static_cast<int>(Qt::DashLine));
	penStyleComboBox->addItem(tr("DotLine"),
		static_cast<int>(Qt::DotLine));
	penStyleComboBox->addItem(tr("DashDotLine"),
		static_cast<int>(Qt::DashDotLine));
	penStyleComboBox->addItem(tr("DashDotDotLine"),
		static_cast<int>(Qt::DashDotDotLine));
	penStyleComboBox->addItem(tr("CustomDashLine"),
		static_cast<int>(Qt::CustomDashLine));
	connect(penStyleComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenStyle(int)));

	penCapLabel = new QLabel(tr("���ʶ�ñ��"));
	penCapComboBox = new QComboBox;
	penCapComboBox->addItem(tr("SquareCap"), Qt::SquareCap);
	penCapComboBox->addItem(tr("FlatCap"), Qt::FlatCap);
	penCapComboBox->addItem(tr("RoundCap"), Qt::RoundCap);
	connect(penCapComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenCap(int)));

	penJoinLabel = new QLabel(tr("�������ӵ㣺"));
	penJoinComboBox = new QComboBox;
	penJoinComboBox->addItem(tr("BevelJoin"), Qt::BevelJoin);
	penJoinComboBox->addItem(tr("MiterJoin"), Qt::MiterJoin);
	penJoinComboBox->addItem(tr("RoundJoin"), Qt::RoundJoin);
	connect(penJoinComboBox, SIGNAL(activated(int)), this, SLOT(ShowPenJoin(int)));

	fillRuleLabel = new QLabel(tr("���ģʽ��"));
	fillRuleComboBox = new QComboBox;
	fillRuleComboBox->addItem(tr("OddEvenFill"), Qt::OddEvenFill);
	fillRuleComboBox->addItem(tr("WindingFill"), Qt::WindingFill);
	connect(fillRuleComboBox, SIGNAL(activated(int)), this, SLOT(ShowFillRule(int)));

	brushColorLabel = new QLabel(tr("��ˢ��ɫ��"));
	brushColorFrame = new QFrame;
	brushColorFrame->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	brushColorFrame->setAutoFillBackground(true);
	brushColorFrame->setPalette(QPalette(Qt::green));
	brushColorBtn = new QPushButton(tr("����"));
	connect(brushColorBtn, SIGNAL(clicked()), this, SLOT(ShowBrushColor()));

	brushStyleLabel = new QLabel(tr("��ˢ���"));
	brushStyleComboBox = new QComboBox;
	brushStyleComboBox->addItem(tr("SolidPattern"), 
		static_cast<int>(Qt::SolidPattern));
	brushStyleComboBox->addItem(tr("Dense1Pattern"),
		static_cast<int>(Qt::Dense1Pattern));
	brushStyleComboBox->addItem(tr("Dense2Pattern"),
		static_cast<int>(Qt::Dense2Pattern));
	brushStyleComboBox->addItem(tr("Dense3Pattern"),
		static_cast<int>(Qt::Dense3Pattern));
	brushStyleComboBox->addItem(tr("Dense4Pattern"),
		static_cast<int>(Qt::Dense4Pattern));
	brushStyleComboBox->addItem(tr("Dense5Pattern"), 
		static_cast<int>(Qt::Dense5Pattern));
	brushStyleComboBox->addItem(tr("Dense6Pattern"),
		static_cast<int>(Qt::Dense6Pattern));
	brushStyleComboBox->addItem(tr("Dense7Pattern"),
		static_cast<int>(Qt::Dense7Pattern));
	brushStyleComboBox->addItem(tr("HorPattern"),
		static_cast<int>(Qt::HorPattern));
	brushStyleComboBox->addItem(tr("VerPattern"),
		static_cast<int>(Qt::VerPattern));
	brushStyleComboBox->addItem(tr("CrossPattern"),
		static_cast<int>(Qt::CrossPattern));
	brushStyleComboBox->addItem(tr("BDiagPattern"),
		static_cast<int>(Qt::BDiagPattern));
	brushStyleComboBox->addItem(tr("FDiagPattern"),
		static_cast<int>(Qt::FDiagPattern));
	brushStyleComboBox->addItem(tr("DiagCrossPattern"),
		static_cast<int>(Qt::DiagCrossPattern));
	brushStyleComboBox->addItem(tr("LinearGradientPattern"),
		static_cast<int>(Qt::LinearGradientPattern));
	brushStyleComboBox->addItem(tr("ConicalGradientPattern"),
		static_cast<int>(Qt::ConicalGradientPattern));
	brushStyleComboBox->addItem(tr("RadialGradientPattern"),
		static_cast<int>(Qt::RadialGradientPattern));
	brushStyleComboBox->addItem(tr("TexturePattern"),
		static_cast<int>(Qt::TexturePattern));
	connect(brushStyleComboBox, SIGNAL(activated(int)), this, SLOT(ShowBursh(int)));

	rightLayout = new QGridLayout;
	rightLayout->addWidget(shapeLabel, 0, 0);
	rightLayout->addWidget(shapeComboBox, 0, 1);
	rightLayout->addWidget(penColorLabel, 1, 0);
	rightLayout->addWidget(penColorFrame, 1, 1);
	rightLayout->addWidget(penColorBtn, 1, 2);
	rightLayout->addWidget(penWidthLabel, 2, 0);
	rightLayout->addWidget(penWidthSpinBox, 2, 1);
	rightLayout->addWidget(penStyleLabel, 3, 0);
	rightLayout->addWidget(penStyleComboBox, 3, 1);
	rightLayout->addWidget(penCapLabel, 4, 0);
	rightLayout->addWidget(penCapComboBox, 4, 1);
	rightLayout->addWidget(penJoinLabel, 5, 0);
	rightLayout->addWidget(penJoinComboBox, 5, 1);
	rightLayout->addWidget(fillRuleLabel, 6, 0);
	rightLayout->addWidget(fillRuleComboBox, 6, 1);
	//rightLayout->addWidget(spreadLabel, 7, 0);
	//rightLayout->addWidget(spreadComboBox, 7, 1);
	rightLayout->addWidget(brushColorLabel, 8, 0);
	rightLayout->addWidget(brushColorFrame, 8, 1);
	rightLayout->addWidget(brushColorBtn, 8, 2);
	rightLayout->addWidget(shapeLabel, 9, 0);
	rightLayout->addWidget(shapeLabel, 9, 1);

	QHBoxLayout *mainLayout = new QHBoxLayout(this);
	mainLayout->addWidget(paintArea);
	mainLayout->addLayout(rightLayout);
	mainLayout->setStretchFactor(paintArea, 1);
	mainLayout->setStretchFactor(rightLayout, 0);

	ShowShape(shapeComboBox->currentIndex());
}

void MainWidget::ShowShape(int)
{
}

void MainWidget::ShowPenWidth(int) 
{
}

void MainWidget::ShowPenColor()
{
}

void MainWidget::ShowPenCap(int)
{
}

void MainWidget::ShowPenStyle(int)
{
}

void MainWidget::ShowPenJoin(int)
{
}

void MainWidget::ShowSpreadStyle()
{
}

void MainWidget::ShowFillRule()
{
}

void MainWidget::ShowBrushColor()
{
}

void MainWidget::ShowBrush(int)
{
}
