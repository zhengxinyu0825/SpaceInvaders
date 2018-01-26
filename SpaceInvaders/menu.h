#ifndef MENU_H
#define MENU_H

#include <QLabel>
#include <QPushButton>

namespace game {
class Menu {
public:
    Menu(QWidget* parent, QString name, int& playeScore, QList<QPair<QString, int>> scores);
    ~Menu();
    void displayMenu(bool paused);
    void openScore();
    void openShape();
    void openSpeed();

private:
    void makeButtons(QWidget* parent, QString name);
    void closeButtons();  // if any buttons are left open, close them
    void revealPlayerScore(bool open);
    int& gameScore;


    QLabel* playerName;
    QLabel* playerScoreLabel;
    QLabel* playerName2;
    QLabel* playerScoreLabel2;
    QLabel* playerName3;
    QLabel* playerScoreLabel3;
    QLabel* playerName4;
    QLabel* playerScoreLabel4;
    QPushButton* score;
    QPushButton* shape;
    QPushButton* shape1;
    QPushButton* shape2;
    QPushButton* shape3;
    QPushButton* speed;
    QPushButton* speedlow;
    QPushButton* speednormal;
    QPushButton* speedfast;
    QPushButton* quit;
    QPushButton* restart;

};
}
#endif  // SCOREBUTTON_H
