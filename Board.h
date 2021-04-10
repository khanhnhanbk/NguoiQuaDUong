#pragma once
#include "console.h"
#include <iostream>
class Board
{
private:
    short m_x;
    short m_y;
    int m_width;
    int m_height;

public:
    Board(short x, short y, int width, int height);
    ~Board();
    void draw(short posX, short posY);
};

Board::Board(short x, short y, int width, int height)
    : m_x{x}, m_y{y}, m_width{width}, m_height{height}
{
}

Board::~Board()
{
}
void Board::draw(short posX, short posY)
{
    GotoXY(m_x, m_y);
    std::cout << 'X';
    for (int i = 1; i < m_width; i++)
        std::cout << 'X';
    std::cout << 'X';
    GotoXY(m_x, m_height + m_y);
    std::cout << 'X';
    for (int i = 1; i < m_width; i++)
        std::cout << 'X';
    std::cout << 'X';
    for (int i = m_y + 1; i < m_height + m_y; i++)
    {
        GotoXY(m_x, i);
        std::cout << 'X';
        GotoXY(m_x + m_width, i);
        std::cout << 'X';
    }
    GotoXY(posX, posY);
}