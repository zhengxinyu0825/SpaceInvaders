#ifndef MOUSECOMMAND_H
#define MOUSECOMMAND_H

#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include "command.h"
#include <QInputEvent>
#include <QMouseEvent>
#include "ship.h"
#include <QSoundEffect>

namespace game {
class MouseCommand: public Command{
public:

    MouseCommand(QWidget* windowAccess, Ship*ship, std::vector<Bullet*>& bullets, QSoundEffect* shipFiringSound);
    void execute(QInputEvent*inputEvent);

private:

    std::vector<Bullet*>& m_bullets;
};
}
#endif // MOUSECOMMAND_H
