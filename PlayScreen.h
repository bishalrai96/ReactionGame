#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>

class GameScreen : public QWidget {
    Q_OBJECT
public:
    GameScreen(QMainWindow * win, QWidget * parent = 0);
private slots:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent *e);
    void OpenMainScreen ();

private:

    QPushButton * mGoBack;
    QPushButton * mSelectLevel;
    QLabel * mShowScore;
    QHBoxLayout * mHorizontalLayout;
    QWidget * mBoxWidget;

    int mMaxCircleDiameter = 30;
    int mMinCircleDiameter = 10;
    int mMaxLeftMargin = 800;
    int mMaxTopMargin = 320;
    int mMarginLeft;
    int mMarginTop;
    int mScore = 0;
    int mDiameter;

    QMainWindow * mMainWindow;


};

#endif // PLAYSCREEN_H
