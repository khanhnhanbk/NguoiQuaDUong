#pragma once

#include "Point.h"
#include <Windows.h>
class Car
{
private:
    Point m_pos;
    int m_lengthCar;

public:
    Car(short x = 0, short y = 0, int len = 1);
    void setPrototype(short x, short y, int len);
    void drawCar();
    void clearCar();

    void swing(short w);
    void move(int dx, int dy);
    ~Car();
};

Car::Car(short x, short y, int len) : m_pos{x, y, '.'}, m_lengthCar{len}
{
}
void Car::setPrototype(short x, short y, int len)
{
    m_pos.setPosition(x, y);
    m_lengthCar = len;
}
Car::~Car()
{
}
void Car::drawCar()
{
    m_pos.drawPoint();
    for (short i = 1; i < m_lengthCar; i++)
    {

        Point tempt{m_pos.getX() + i, m_pos.getY(), '.'};
        tempt.drawPoint();
    }
}
void Car::clearCar()
{
    m_pos.clearPoint();
    for (short i = 1; i < m_lengthCar; i++)
    {

        Point tempt{m_pos.getX() + i, m_pos.getY(), '.'};
        tempt.clearPoint();
    }
}
void Car::move(int dx, int dy)
{
    this->clearCar();
    m_pos.move(dx, dy);
    this->drawCar();
}
void Car::swing(short w)
{
    this->move(w, 0);
}