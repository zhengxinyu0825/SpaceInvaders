#pragma once

#include "config.h"
#include "menu.h"
#include "ship.h"
#include "swarm.h"
#include "swarminfo.h"
#include <QDialog>
#include <QSoundEffect>
#include <QWidget>
#include <vector>
#include <QKeyEvent>
#include "keycommand.h"
#include <QMouseEvent>
#include "mousecommand.h"

namespace game {
class GameDialog : public QDialog {
    Q_OBJECT

public:
    GameDialog(QWidget* parent = nullptr);
    void generateAliens(const QList<SwarmInfo>& swarms);
    virtual ~GameDialog();
    Config* c;

protected:
    QTimer* timer;
    void paintEvent(QPaintEvent* event);
    void paintBullets(QPainter& painter);
    void updateBullets();
    void execute(QInputEvent*inputEvent);
    void paintSwarm(QPainter& painter, AlienBase*& root);
    void checkSwarmCollisions(AlienBase*& root);
    // ship and swarms
    Ship* ship;
    std::vector<Bullet*> bullets;
    AlienBase* swarms;  // swarms is the ROOT node of the composite
    QList<SwarmInfo> swarmList = {};
    QSoundEffect shipFiringSound;
    int next_instruct;

    // keys
    void keyPressEvent(QKeyEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    // about the canvas
    int frames;
    const int WIDTH = 800;
    const int HEIGHT = 600;
    int SCALEDWIDTH;
    int SCALEDHEIGHT;
    int currentlevel;
    // collision...
    int get_collided_swarm(Bullet*& b, AlienBase*& root);
    int get_collided(Bullet*& b, AlienBase*& root, int i);
    void addBullets(const QList<Bullet*>& list);

    // pausing & menu

    bool paused;
    void pauseStart();
    Menu* menu;
    KeyCommand* m_keyCommand;
    MouseCommand* m_MouseCommand;
    //MouseCommand* m_mouseCommand;
    // score
    int gameScore;  // this run's score.
    int lifetime=5;

    //shoe the score and level in the right screen
    QLabel* LevelLabel;
    QLabel* ScoreLabel;
    QLabel* LevelNumber;
    QLabel* ScoreNumber;
    int levelnumber=0;
    int restart=0;

public slots:
    void nextFrame();
    // menus
    void showScore();
    void showShape();
    void showShape1();
    void showShape2();
    void showShape3();
    void showSpeed();
    void showSpeedlow();
    void showSpeednormal();
    void showSpeedfast();
    void showQuit();
    void showRestart();

};
}
