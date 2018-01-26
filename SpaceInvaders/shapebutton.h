#ifndef SHAPEBUTTON_H
#define SHAPEBUTTON_H
/*
#include <QPushButton>
class SizeButton
{
public:
    SizeButton(int x, int y, QWidget* parent);
    ~SizeButton();

    void displayMenu(bool paused);
    void displayOptions();
private:
    void loadSizes(int x, int y, QWidget* parent);
    void show(bool flag);
    bool isOpen;
    QPushButton *size;

    QPushButton *tiny;
    QPushButton *normal;
    QPushButton *large;
    QPushButton *giant;
};
*/
#include <QPushButton>
class ShapeButton
{
public:
    ShapeButton(int x, int y, QWidget* parent);
    ~ShapeButton();

    void displayMenu(bool paused);
    void displayOptions();
private:
    void loadShapes(int x, int y, QWidget* parent);
    void show(bool flag);
    bool isOpen;
    QPushButton *shape;

    QPushButton *shape1;
    QPushButton *shape2;
    QPushButton *shape3;
};
#endif // SHAPEBUTTON_H
