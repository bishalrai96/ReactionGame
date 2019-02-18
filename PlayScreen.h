#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include <QPushButton>

class Box : public QWidget {
    Q_OBJECT
public:
    Box (QWidget * parent = nullptr):QWidget(parent){
        widget = parent;
        mXCord  = 200;
        mYCord  = 200;
        mHeight = 400;
        mWidth  = 800;

       this->setFixedSize(800, 400);
//        this->setStyleSheet("background-color: red;");

    }
private:
    void paintEvent(QPaintEvent* event) {
        (void)event;
        // setting widget to paint
        QPainter paint(this);
        // do not use pen for drawing the widget
        paint.setPen(Qt::NoPen);
        // setting the bursh color
        paint.setBrush(Qt::green);
        // paint rectangle with rounded corner
        paint.drawRect(QRect(60, 10, 800, 400));
    }

    void setPosition(int X, int Y, int height, int width) {
        mXCord  = X;
        mYCord  = Y;
        mHeight = height;
        mWidth  = width;
    }

#if 0
    void mouseReleaseEvent(QMouseEvent * event) {
        (void) event;
        if(event->button() & Qt::LeftButton) {

        }
    }
#endif

private:
    int mXCord;
    int mYCord;
    int mHeight;
    int mWidth;

    QWidget * widget;
};


class GameScreen : public QMainWindow {
    Q_OBJECT
public:
    GameScreen(QWidget * parent = 0) : QMainWindow(parent){

        centralWidget = new QWidget(this);

        this->setStyleSheet("QMainWindow {background-color: #2359ab;}");
        this->setFixedSize(800, 400);
        centralWidget->setStyleSheet("background-color: yellow");
        centralWidget->setFixedSize(800, 400);

        box = new Box(centralWidget);
        box->show();

    }

    void changePosition() {

    }

private:
    Box * box;
    QWidget * centralWidget;
};

#endif // PLAYSCREEN_H
