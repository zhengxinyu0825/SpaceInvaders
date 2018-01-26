#ifndef COMMAND_H
#define COMMAND_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include "command.h"
#include <QInputEvent>
#include <QKeyEvent>
#include <QSoundEffect>
#include "ship.h"

namespace game {
class Command{
public:
    Command(QWidget*windowAccess,Ship*ship, QSoundEffect* shipFiringSound)
        :m_windowAccess(windowAccess)
        ,ship(ship)
        ,m_shipFiringSound(shipFiringSound)
   {

   }
    ~Command(){}

    virtual void execute(QInputEvent* inpurEvent) = 0;

protected:
    QWidget *m_windowAccess = 0;
    Ship * ship;
    QSoundEffect* m_shipFiringSound;
};
}
#endif // COMMAND_H
