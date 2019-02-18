#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QBoxLayout>

#include "PlayScreen.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    QPushButton * mPlayButton;
    QPushButton * mScoreBoard;
    QPushButton * mPickLevel;

    QWidget * mCentralWidget;
    QVBoxLayout * mVerticalLayout;

    GameScreen * mPlayScreen;


private slots:
    void OpenGameScreen();
};

#endif // MAINWINDOW_H
