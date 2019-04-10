#ifndef PLAYSCREEN_H
#define PLAYSCREEN_H

#include <QWidget>
#include <QPainter>
#include <QMainWindow>
#include <QPushButton>


class GameScreen : public QWidget {
    Q_OBJECT
public:
    GameScreen(QWidget * parent = 0);
private slots:
    void paintEvent(QPaintEvent* event);


private:
    QWidget * mBoxWidget;
};

#endif // PLAYSCREEN_H
