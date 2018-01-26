#include "sizebutton.h"
#include <iostream>
SizeButton::SizeButton(int x, int y, QWidget* parent)
{
    isOpen = false;
    loadSizes(x, y, parent);

}

SizeButton::~SizeButton() {
    delete size;
    delete tiny;
    delete normal;
    delete large;
    delete giant;
}


void SizeButton::loadSizes(int x, int y, QWidget* parent) {
    size = new QPushButton("Size", parent);
    size->setVisible(false);
    size->setGeometry(QRect(x, y, 100, 30));
    size->setStyleSheet("background-color: white");
    QObject::connect(size, SIGNAL(released()), parent, SLOT(displaySizeOptions()));

    tiny = new QPushButton("Tiny", parent);
    tiny->setVisible(false);
    tiny->setGeometry(QRect(x, y + 30, 100, 30));
    tiny->setStyleSheet("background-color: red");
    QObject::connect(tiny, SIGNAL(released()), parent, SLOT(setTiny()));

    normal = new QPushButton("Normal", parent);
    normal->setVisible(false);
    normal->setGeometry(QRect(x, y + (30 * 2), 100, 30));
    normal->setStyleSheet("background-color: orange");
    QObject::connect(normal, SIGNAL(released()), parent, SLOT(setNormal()));

    large = new QPushButton("Large", parent);
    large->setVisible(false);
    large->setGeometry(QRect(x, y + (30 * 3), 100, 30));
    large->setStyleSheet("background-color: yellow");
    QObject::connect(large, SIGNAL(released()), parent, SLOT(setLarge()));

    giant = new QPushButton("Giant", parent);
    giant->setVisible(false);
    giant->setGeometry(QRect(x, y + (30 * 4), 100, 30));
    giant->setStyleSheet("background-color: green");
    QObject::connect(giant, SIGNAL(released()), parent, SLOT(setGiant()));

}

//loads main button
void SizeButton::displayMenu(bool pause) {
    size->setVisible(pause);

    //also hide the smaller buttons if it's false
    if (!pause) {
        isOpen = false;
        show(isOpen);
    }
}

void SizeButton::show(bool flag) {
    tiny->setVisible(flag);
    normal->setVisible(flag);
    large->setVisible(flag);
    giant->setVisible(flag);
}

//opens up the color options or closes it
void SizeButton::displayOptions() {
    if (isOpen) {
        isOpen = false;
    } else {
        isOpen = true;
    }
     std::cout<<"display option"<<std::endl;
     show(isOpen);
}
