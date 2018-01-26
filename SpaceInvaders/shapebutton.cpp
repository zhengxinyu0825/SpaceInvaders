#include "shapebutton.h"
#include <iostream>
ShapeButton::ShapeButton(int x, int y, QWidget* parent)
{
    isOpen = false;
    loadShapes(x, y, parent);

}

ShapeButton::~ShapeButton() {
    delete shape;
    delete shape1;
    delete shape2;
    delete shape3;
}


void ShapeButton::loadShapes(int x, int y, QWidget* parent) {
    shape = new QPushButton("Shape", parent);
    shape->setVisible(false);
    shape->setGeometry(QRect(x, y, 100, 30));
    shape->setStyleSheet("background-color: white");
    //std::cout<<"Shape get"<<std::endl;
    QObject::connect(shape, SIGNAL(released()), parent, SLOT(displayShapeOptions()));

    shape1 = new QPushButton("Shape1", parent);
    shape1->setVisible(false);
    shape1->setGeometry(QRect(x, y + 30, 100, 30));
    shape1->setStyleSheet("background-color: red");
    QObject::connect(shape1, SIGNAL(released()), parent, SLOT(setShape1()));

    shape2 = new QPushButton("Shape2", parent);
    shape2->setVisible(false);
    shape2->setGeometry(QRect(x, y + (30 * 2), 100, 30));
    shape2->setStyleSheet("background-color: orange");
    QObject::connect(shape2, SIGNAL(released()), parent, SLOT(setShape2()));

    shape3 = new QPushButton("Shape3", parent);
    shape3->setVisible(false);
    shape3->setGeometry(QRect(x, y + (30 * 3), 100, 30));
    shape3->setStyleSheet("background-color: yellow");
    QObject::connect(shape3, SIGNAL(released()), parent, SLOT(setShape3()));
}

//loads main button
void ShapeButton::displayMenu(bool pause) {
    shape->setVisible(pause);

    //also hide the smaller buttons if it's false
    if (!pause) {
        isOpen = false;
        show(isOpen);
    }
}

void ShapeButton::show(bool flag) {
    shape1->setVisible(flag);
    shape2->setVisible(flag);
    shape3->setVisible(flag);
}

//opens up the color options or closes it
void ShapeButton::displayOptions() {
    if (isOpen) {
        isOpen = false;

    } else {
        isOpen = true;

    }
    show(isOpen);

}
