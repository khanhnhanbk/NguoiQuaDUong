#pragma once
#include "console.h"
#include <iostream>
class Point
{
private:
    short m_x;
    short m_y;
    char m_symbol;

public:
    Point(short x = 0, short y = 0, char symbol = '*');
    ~Point();
    void setPosition(short x, short y);
    void drawPoint();
    void clearPoint();

    short getX() const;
    short getY() const;

    void move(int dx, int dy);
};

Point::Point(short x, short y, char symbol) : m_x{x}, m_y{y}, m_symbol{symbol}
{
}

Point::~Point()
{
}
void Point::drawPoint()
{
    GotoXY(m_x, m_y);
    std::cout << m_symbol;
}
void Point::clearPoint()
{
    GotoXY(m_x, m_y);
    std::cout << ' ';
}
void Point::setPosition(short x, short y)
{
    m_x = x;
    m_y = y;
}
short Point::getX() const
{
    return m_x;
}

short Point::getY() const
{
    return m_y;
}
void Point::move(int dx, int dy)
{
    this->clearPoint();
    m_x += dx;
    m_y += dy;
    this->drawPoint();
}