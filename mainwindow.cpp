#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800, 400);

    this->setStyleSheet("QMainWindow {background-color: #2359ab;}");
  
    mCentralWidget = new QWidget(this);
    mVerticalLayout = new QVBoxLayout(mCentralWidget);

    mPlayButton = new QPushButton("Play", this);
    mPlayButton->setFixedSize(200,50);

    mScoreBoard = new QPushButton("Score Board", this);
    mScoreBoard->setFixedSize(200,50);

    mPickLevel  = new QPushButton("Level", this);
    mPickLevel->setFixedSize(200,50);

    mVerticalLayout->addWidget(mPlayButton);
    mVerticalLayout->addWidget(mScoreBoard);
    mVerticalLayout->addWidget(mPickLevel);

    mVerticalLayout->setMargin(6);

    mVerticalLayout->setAlignment(Qt::AlignCenter);

    mCentralWidget->setLayout(mVerticalLayout);
    mCentralWidget->setFixedSize(800, 400);

    connect(mPlayButton, SIGNAL(clicked()), this, SLOT(OpenGameScreen()));
    mPlayScreen = new GameScreen;
}

void MainWindow::OpenGameScreen() {

    this->hide();
    mPlayScreen->show();

}

MainWindow::~MainWindow()
{

}



