#ifndef SIZEBUTTON_H
#define SIZEBUTTON_H
/*
#include <QPushButton>

class ColorButton
{
public:
    ColorButton(int x, int y, QWidget* parent);
    ~ColorButton();

    void displayMenu(bool paused);
    void displayOptions();
private:
    void loadColors(int x, int y, QWidget* parent);
    void show(bool flag);
    bool isOpen;
    QPushButton *color;

    QPushButton *red;
    QPushButton *orange;
    QPushButton *yellow;
    QPushButton *green;
    QPushButton *blue;
};
*/
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

#endif // SIZEBUTTON_H
