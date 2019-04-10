#include "PlayScreen.h"
#include <stdlib.h>
#include <QTimer>

GameScreen::GameScreen(QWidget * parent):QWidget(parent){

    this->setStyleSheet("background-color:#85e783;");
    this->setFixedSize(800, 400);

    QTimer * paint = new QTimer(this);
    connect(paint, SIGNAL(timeout()), this, SLOT(update()));
    paint->setInterval(1000);
    paint->start();    

}


void GameScreen::paintEvent(QPaintEvent* event) {
	
    int maxRadius = 30;
    int minRadius = 10;
    int MaxLeftMargin = 800;
    int MaxTopMargin = 400;
    int marginLeft;
    int marginTop;

    int Diameter = rand() % maxRadius;
    if (Diameter < 10) {
        Diameter = 10;
    }

    marginLeft = rand() % MaxLeftMargin;
    marginTop  = rand() % MaxTopMargin;
    if (marginLeft > MaxLeftMargin - Diameter)
    	marginLeft = marginLeft - Diameter;
    if (marginTop > MaxTopMargin - Diameter)
    	marginTop  = marginTop - Diameter;

    (void)event;
    QColor color = "#00cdaa";
    QBrush brush = QBrush(color);
    // setting widget to paint
    QPainter paint(this);
    // do not use pen for drawing the widget
    paint.setPen(Qt::NoPen);
    // setting the bursh color
    paint.setBrush(brush);
    // paint circle
    paint.drawEllipse(marginLeft, marginTop, Diameter, Diameter);
}

