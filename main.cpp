// #include <origin.h>
#include <stdio.h>
#include <iostream>
#include <conio.h>
// #include <winuser.h>
#include <thread>
#include <ctype.h>
#include "console.h"
#include "point.h"
#include "Car.h"
#include "Board.h"
using namespace std;
#define MAX_CAR 17
#define MAX_CAR_LENGTH 10
#define MAX_SPEED 3
//Biến toàn cục
Car *X;                                       //Mảng chứa MAX_CAR xe
Point Y{18, 19, 'Y'};                         // Đại diện người qua đường
int cnt = 0;                                  //Biến hỗ trợ trong quá trình tăng tốc độ xe di chuyển
char MOVING;                                  //Biến xác định hướng di chuyển của người
int SPEED;                                    // Tốc độ xe chạy (xem như level)
int HEIGH_CONSOLE = 100, WIDTH_CONSOLE = 100; // Độ rộng và độ cao của màn hình console
bool STATE;

void ResetData()
{
    MOVING = 'D';          // Ban đầu cho người di chuyển sang phải
    SPEED = 1;             // Tốc độ lúc đầu
    Y.setPosition(18, 19); // Vị trí lúc đầu của người
    // Tạo mảng xe chạy
    Y.drawPoint();
    if (X == NULL)
    {
        X = new Car[MAX_CAR];
        for (int i = 0; i < MAX_CAR; i++)
        {
            short posTmp = rand() % (WIDTH_CONSOLE - MAX_CAR_LENGTH) + 5;
            X[i].setPrototype(posTmp, i + 7, MAX_CAR_LENGTH);
            X[i].drawCar();
        }
    }
}
void playerInput()
{
    while (true)
    {
        switch (MOVING)
        {
        case 'a':
            Y.move(-1, 0);
            break;
        case 'd':
            Y.move(1, 0);
            break;
        case 'w':
            Y.move(0, -1);
            break;
        case 's':
            Y.move(0, 1);
            break;
        case 'q':
            exit(1);
            break;
        default:
            break;
        }
        for (int i = 0; i < MAX_CAR; i++)
        {
            X[i].move(1, 0);
        }
        MOVING = ' ';
        Sleep(100);
        for (int i = 0; i < MAX_CAR; i++)
        {
            X[i].move(-1, 0);
        }
        Sleep(100);
    }
}
int main()
{
    //    DrawBoard(1, 1, 10, 10, 1, 1);
    ShowConsoleCursor(false);
    FixConsoleWindow();
    GotoXY(0, 0);
    Board board{5, 5, 100, 20};
    // POINT cur;
    board.draw(0, 0);
    ResetData();
    thread newThead(playerInput);
    while (true)
    {
        MOVING = getch();
    }

    std::getchar();
    return 0;
}
