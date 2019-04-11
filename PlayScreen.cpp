#include "PlayScreen.h"
#include "mainwindow.h"
#include <stdlib.h>
#include <QTimer>
#include <QMouseEvent>

GameScreen::GameScreen(QMainWindow * win, QWidget * parent):QWidget(parent){

    mMainWindow = win;
    this->setStyleSheet("background-color:#2359ab;");
    this->setFixedSize(800, 400);

    QTimer * paint = new QTimer(this);
    connect(paint, SIGNAL(timeout()), this, SLOT(update()));
    paint->setInterval(1000);
    paint->start();    

    mHorizontalLayout = new QHBoxLayout(this);

    mGoBack = new QPushButton("GO BACK", this);
    mGoBack->setFixedSize(100, 50);
    mGoBack->setStyleSheet("background-color:#e7efff;");
    

    mSelectLevel = new QPushButton("LEVEL", this);
    mSelectLevel->setFixedSize(100, 50);
    mSelectLevel->setStyleSheet("background-color:#e7efff;");

    mShowScore = new QLabel("SCORE: 0", this);
    mShowScore->setFixedSize(100, 50);
    mShowScore->setStyleSheet("background-color:#e7efff;");
    mShowScore->setAlignment(Qt::AlignCenter);

    mHorizontalLayout->addWidget(mGoBack);
    mHorizontalLayout->addWidget(mSelectLevel);
    mHorizontalLayout->addWidget(mShowScore);

    mHorizontalLayout->setAlignment(Qt::AlignBottom);
    mHorizontalLayout->setSpacing(240);

    connect(mGoBack, SIGNAL(clicked()), this, SLOT(OpenMainScreen()));

    this->setAttribute(Qt::WA_DeleteOnClose);
    
}


void GameScreen::paintEvent(QPaintEvent* event) {
	  
    mDiameter = rand() % mMaxCircleDiameter;
    if (mDiameter < mMinCircleDiameter) {
        mDiameter = mMinCircleDiameter;
    }

    mMarginLeft = rand() % mMaxLeftMargin;
    mMarginTop  = rand() % mMaxTopMargin;
    if (mMarginLeft > mMaxLeftMargin - mDiameter)
        mMarginLeft = mMarginLeft - mDiameter;
    if (mMarginTop > mMaxTopMargin - mDiameter)
        mMarginTop  = mMarginTop - mDiameter;

    (void)event;
    QColor color = "#85e783";
    QBrush brush = QBrush(color);
    // setting widget to paint
    QPainter paint(this);
    // do not use pen for drawing the widget
    paint.setPen(Qt::NoPen);
    // setting the bursh color
    paint.setBrush(brush);
    // paint circle

    paint.drawRect(0,0,mMaxLeftMargin,mMaxTopMargin);
    QBrush brush2 = QBrush("#00cdaa");
    color = "#00cdaa";
    paint.setBrush(brush2);
    paint.drawEllipse(mMarginLeft, mMarginTop, mDiameter, mDiameter);
}

void GameScreen::mousePressEvent(QMouseEvent *e) {
	int x = e->x();
	int y = e->y();

    // check if user click is within the green frame
    if (x < mMaxLeftMargin && y < mMaxTopMargin) {
        // check if user has clicked the circle
        if (x >= mMarginLeft && x <= mMarginLeft + mDiameter) {
            if (y >= mMarginTop && y <= mMarginTop + mDiameter) {
                mScore++;
                mShowScore->setText("SCORE: " + QString::number(mScore));
            }
        }
    }
}

void GameScreen::OpenMainScreen() {
    this->close();
    mMainWindow = new MainWindow();
    mMainWindow->show();
}


