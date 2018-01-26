#include "menu.h"
#include <iostream>
//#include "ui_menu.h"
namespace game {
Menu::Menu(QWidget* parent, QString name, int& playerScore, QList<QPair<QString, int>> scores)
        : gameScore(playerScore) {
    // Scores could be read in the future.
    makeButtons(parent, name);

}

Menu::~Menu() {
    delete score;
    delete playerName;
    delete playerScoreLabel;
    delete playerName2;
    delete playerScoreLabel2;
    delete playerName3;
    delete playerScoreLabel3;
    delete playerName4;
    delete playerScoreLabel4;
    delete shape;
    delete shape1;
    delete shape2;
    delete shape3;
    delete speed;
    delete speedlow;
    delete speednormal;
    delete speedfast;
    delete quit;
    delete restart;
}

void Menu::makeButtons(QWidget* parent, QString name) {
    score = new QPushButton("Score:", parent);
    score->setGeometry(QRect(0, 0, 100, 30));
    score->setVisible(false);
    score->setStyleSheet("background-color: red");
    QObject::connect(score, SIGNAL(released()), parent, SLOT(showScore()));

    playerName = new QLabel(parent);
    playerName->setGeometry(0, 30, 100, 30);
    playerName->setText(name);
    playerName->setVisible(false);
    playerName->setStyleSheet("background-color: white");

    playerScoreLabel = new QLabel(parent);
    playerScoreLabel->setGeometry(100, 30, 100, 30);
    playerScoreLabel->setText(QString::number(gameScore));
    playerScoreLabel->setVisible(false);
    playerScoreLabel->setStyleSheet("color:red;");

    playerName2 = new QLabel(parent);
    playerName2->setGeometry(0, 120, 100, 30);
    playerName2->setText("JAMES");
    playerName2->setVisible(false);
    playerName2->setStyleSheet("background-color: white");

    playerScoreLabel2 = new QLabel(parent);
    playerScoreLabel2->setGeometry(100, 120, 100, 30);
    playerScoreLabel2->setText(QString::number(2));
    playerScoreLabel2->setVisible(false);
    playerScoreLabel2->setStyleSheet("color:red;");

    playerName3 = new QLabel(parent);
    playerName3->setGeometry(0, 90, 100, 30);
    playerName3->setText("KRIS");
    playerName3->setVisible(false);
    playerName3->setStyleSheet("background-color: white");

    playerScoreLabel3 = new QLabel(parent);
    playerScoreLabel3->setGeometry(100, 90, 100, 30);
    playerScoreLabel3->setText(QString::number(3));
    playerScoreLabel3->setVisible(false);
    playerScoreLabel3->setStyleSheet("color:red;");

    playerName4 = new QLabel(parent);
    playerName4->setGeometry(0, 60, 100, 30);
    playerName4->setText("WENDY");
    playerName4->setVisible(false);
    playerName4->setStyleSheet("background-color: white");

    playerScoreLabel4 = new QLabel(parent);
    playerScoreLabel4->setGeometry(100, 60, 100, 30);
    playerScoreLabel4->setText(QString::number(5));
    playerScoreLabel4->setVisible(false);
    playerScoreLabel4->setStyleSheet("color:red;");

    shape = new QPushButton("Shape:", parent);
    shape->setGeometry(QRect(200, 0, 100, 30));
    shape->setVisible(false);
    shape->setStyleSheet("background-color: red");
    QObject::connect(shape, SIGNAL(released()), parent, SLOT(showShape()));

    shape1 = new QPushButton("Shape1", parent);
    shape1->setGeometry(QRect(200, 30, 100, 30));
    shape1->setVisible(false);
    shape1->setStyleSheet("background-color: yellow");
    QObject::connect(shape1, SIGNAL(released()), parent, SLOT(showShape1()));

    shape2 = new QPushButton("Shape2", parent);
    shape2->setGeometry(QRect(200, 60, 100, 30));
    shape2->setVisible(false);
    shape2->setStyleSheet("background-color: blue");
    QObject::connect(shape2, SIGNAL(released()), parent, SLOT(showShape2()));

    shape3 = new QPushButton("Shape3", parent);
    shape3->setGeometry(QRect(200, 90, 100, 30));
    shape3->setVisible(false);
    shape3->setStyleSheet("background-color: green");
    QObject::connect(shape3, SIGNAL(released()), parent, SLOT(showShape3()));

    speed = new QPushButton("Speed:", parent);
    speed->setGeometry(QRect(300, 0, 100, 30));
    speed->setVisible(false);
    speed->setStyleSheet("background-color: red");
    QObject::connect(speed, SIGNAL(released()), parent, SLOT(showSpeed()));

    speedlow = new QPushButton("Low", parent);
    speedlow->setGeometry(QRect(300, 30, 100, 30));
    speedlow->setVisible(false);
    speedlow->setStyleSheet("background-color: yellow");
    QObject::connect(speedlow, SIGNAL(released()), parent, SLOT(showSpeedlow()));

    speednormal = new QPushButton("Normal", parent);
    speednormal->setGeometry(QRect(300, 60, 100, 30));
    speednormal->setVisible(false);
    speednormal->setStyleSheet("background-color: blue");
    QObject::connect(speednormal, SIGNAL(released()), parent, SLOT(showSpeednormal()));

    speedfast = new QPushButton("Fast", parent);
    speedfast->setGeometry(QRect(300, 90, 100, 30));
    speedfast->setVisible(false);
    speedfast->setStyleSheet("background-color: green");
    QObject::connect(speedfast, SIGNAL(released()), parent, SLOT(showSpeedfast()));

    quit = new QPushButton("Quit", parent);
    quit->setGeometry(QRect(400, 0, 100, 30));
    quit->setVisible(false);
    quit->setStyleSheet("background-color: red");
    QObject::connect(quit, SIGNAL(released()), parent, SLOT(showQuit()));

    restart = new QPushButton("Restart", parent);
    restart->setGeometry(QRect(500, 0, 100, 30));
    restart->setVisible(false);
    restart->setStyleSheet("background-color: red");
    QObject::connect(restart, SIGNAL(released()), parent, SLOT(showRestart()));

}

// called when game is paused or unpaused

void Menu::displayMenu(bool paused) {
    if (!paused) {
        closeButtons();
    } else {
        score->setVisible(true);
        shape->setVisible(true);
        speed->setVisible(true);
        quit->setVisible(true);
        restart->setVisible(true);

    }
}

// helper, closes all the opened menus
void Menu::closeButtons() {
    score->setVisible(false);
    revealPlayerScore(false);
    shape->setVisible(false);
    shape1->setVisible(false);
    shape2->setVisible(false);
    shape3->setVisible(false);
    speed->setVisible(false);
    speedlow->setVisible(false);
    speednormal->setVisible(false);
    speedfast->setVisible(false);
    quit->setVisible(false);
    restart->setVisible(false);

}

// helper function for OpenScore
void Menu::revealPlayerScore(bool open) {
    // recalculate playerScoreLabel
    playerScoreLabel->setText(QString::number(gameScore));
    playerName->setVisible(open);
    playerScoreLabel->setVisible(open);
    playerName2->setVisible(open);
    playerScoreLabel2->setVisible(open);
    playerName3->setVisible(open);
    playerScoreLabel3->setVisible(open);
    playerName4->setVisible(open);
    playerScoreLabel4->setVisible(open);

}

void Menu::openScore() {
    if (playerName->isVisible()) {
        revealPlayerScore(false);
    } else {
        revealPlayerScore(true);
    }
}

void Menu::openShape(){
    if(shape1->isVisible()){
       shape1->setVisible(false);
       shape2->setVisible(false);
       shape3->setVisible(false);
    }
    else{
       shape1->setVisible(true);
       shape2->setVisible(true);
       shape3->setVisible(true);
    }
}

void Menu::openSpeed(){
    if(speedlow->isVisible()){
       speedlow->setVisible(false);
       speednormal->setVisible(false);
       speedfast->setVisible(false);
    }
    else{
       speedlow->setVisible(true);
       speednormal->setVisible(true);
       speedfast->setVisible(true);
    }
}
}
