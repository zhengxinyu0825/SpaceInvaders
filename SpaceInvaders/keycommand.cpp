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
#include "KeyCommand.h"
namespace game {

KeyCommand::KeyCommand(QWidget *windowAccess, Ship* ship, QTimer* timer,
               Menu* menu, std::vector<Bullet*>& bullets, QSoundEffect* shipFiringSound)
        :Command(windowAccess,ship, shipFiringSound), m_timer(timer), m_menu(menu),
         m_bullets(bullets)
    {

    }
void KeyCommand::execute(QInputEvent*inputEvent){
        QKeyEvent * keyEvent = dynamic_cast < QKeyEvent *>( inputEvent );
        if(keyEvent->type() == QEvent::KeyPress){
            if (keyEvent->key() == Qt::Key_P) {
                if (!m_timer->isActive()) {
                    // start game
                    m_menu->displayMenu(false);
                    m_timer->start(Config::getInstance()->get_frames());
                } else {
                    m_menu->displayMenu(true);
                    m_timer->stop();
                }
            }
            else if(keyEvent->key() == Qt::Key_Left){
                ship->move_left();
            }
            else if(keyEvent->key() == Qt::Key_Right){
                ship->move_right();
            }

            else if (keyEvent->key() == Qt::Key_Up){
                ship->move_up();
            }

            else if (keyEvent->key() == Qt::Key_Down){
                ship->move_down();
            }

            else if (keyEvent->key() == Qt::Key_1) {
               QPixmap image;
               image.load(":/Images/ship.png");
               ship->set_image(image);
            }

            else if (keyEvent->key() == Qt::Key_2) {
                QPixmap image;
                image.load(":/Images/ship33.png");
                ship->set_image(image);
            }

            else if (keyEvent->key() == Qt::Key_3) {
                QPixmap image;
                image.load(":/Images/ship22.png");
                ship->set_image(image);
            }
            else if(keyEvent->key() == Qt::Key_Space){
                m_bullets.push_back(this->ship->shootsmall());
                m_shipFiringSound->play();
            }
            else if (keyEvent->key() == Qt::Key_S) {
                m_bullets.push_back(this->ship->shootsmall());
                m_shipFiringSound->play();
            }

            else if (keyEvent->key() == Qt::Key_M) {
                m_bullets.push_back(this->ship->shootmedium());
                m_shipFiringSound->play();
            }

            else if (keyEvent->key() == Qt::Key_L) {
                m_bullets.push_back(this->ship->shootlarge());
                m_shipFiringSound->play();
            }
        }

    }

}




