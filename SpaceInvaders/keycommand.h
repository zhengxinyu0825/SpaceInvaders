#ifndef KEYCOMMAND_H
#define KEYCOMMAND_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include "command.h"
#include <QInputEvent>
#include <QKeyEvent>
#include <QTimer>
#include "ship.h"
#include "gamedialog.h"
#include <QSoundEffect>
namespace game {
class KeyCommand: public Command{
public:

    KeyCommand(QWidget *windowAccess, Ship* ship, QTimer* timer, Menu* menu, std::vector<Bullet*>& bullets, QSoundEffect* shipFiringSound);
    void execute(QInputEvent*inputEvent);

private:
    Menu* m_menu;
    QTimer* m_timer;
    std::vector<Bullet*>& m_bullets;

};

}

#endif // KEYCOMMAND_H
