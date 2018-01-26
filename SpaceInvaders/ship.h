#pragma once
#include "base.h"
#include "bullet.h"
#include "bulletbuilder.h"
#include <QPixmap>

namespace game {

class Ship : public Base {
    // A SHIP CAN MOVE LEFT, RIGHT AND SHOOT (ALL WITH AN VELOCITY)

private:
    int velocity;
    int bullet_velocity;
    BulletBuilder builder;

public:
    Ship(QPixmap image, double scale, int x, int y);
    Bullet* shootsmall();
    Bullet* shootmedium();
    Bullet* shootlarge();
    void move_left();
    void move_right();
    void move_up();
    void move_down();

    virtual ~Ship();
};
}
