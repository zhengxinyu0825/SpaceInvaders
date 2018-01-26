#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include "command.h"
#include <QInputEvent>
#include <QMouseEvent>
#include "ship.h"
#include "mousecommand.h"
#include <QSoundEffect>
namespace game {

MouseCommand::MouseCommand(QWidget* windowAccess, Ship*ship, std::vector<Bullet*>& bullets, QSoundEffect* shipFiringSound)
              : Command(windowAccess,ship, shipFiringSound), m_bullets(bullets)
          {

          }
void MouseCommand::execute(QInputEvent*inputEvent){

    QMouseEvent * mouseEvent = dynamic_cast < QMouseEvent *>( inputEvent );
    if(mouseEvent->type()==QEvent::MouseMove){
        ship->set_x(mouseEvent->pos().x());
     }

    if(mouseEvent->type()==QEvent::MouseButtonPress){
        m_bullets.push_back(this->ship->shootsmall());
        m_shipFiringSound->play();
     }


}
}


