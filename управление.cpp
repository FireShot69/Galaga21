#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <exception>
using namespace std;
void move_cursor(int x, int y);
void kinder(int x, int y);
void resize_console(int vis, int shr);
void resize_console(int vis, int shr)
{
    SMALL_RECT r;
    r.Top = 0;
    r.Bottom = vis;
    r.Left = 0;
    r.Right = vis;
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), true, &r);
}
void move_cursor(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void kinder(int x, int y)
{
    x = 0;
    y = 0;
}
int main()
{
    int vis = 50, shr = 45;
    int inp1 = 0, inp2 = 0;
    resize_console(vis - 1, shr);
    cout << "Controls:\n";
    cout << "A - left\n";
    cout << "D - right \n";
    for (int n = 0; n < (shr / 2 - 1) - 4; n++)
    {
        cout << "\n";
    }
    cout << setw(vis / 2 + 2) << "GALAGA\n";
    move_cursor((vis - 29) / 2, shr - 1);
    cout << "  PRESS -ENTER- TO START\n";

    bool new_game = false;

    while ((inp1 = _getch()) != 13)
    {
        if (inp1 == 224 && (inp2 = _getch()) == 72)
        {
            new_game = true;
        }
    }
    
 //////Конец меню///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ///////Начало игры///////////////////////////////////////////////////////////24-25//////////////////////////////////////////////////////////////////
    
    struct ship {
        int hp = 100;
    };
    
    struct enemies_ship {
        int hp = 30;
        int attack = 10;
    };
    struct Bullets_ship {
        const int MaxBullets = 25;
        int attack = 10;
    };
    

    resize_console(vis - 1, shr);
    for (int n = 0; n < (shr / 2 - 1) - 4; n++)
    {
        cout << "\n";
    }
    cout << setw(vis / 2 + 2) << "\n";
    move_cursor((vis - 29) / 2, shr - 1);
    
    
 
    int shipX = 20, 
    int shipY = 20;
    const int ShipSpeed = 2;
    

    int x = 0;

    while (true) {
        system("cls");
        
        move_cursor(shipX, shipY);
            cout << "       |       " << endl;
            move_cursor(shipX, shipY+1);
            cout << "|      |      |" << endl;
            move_cursor(shipX, shipY+2);
            cout << "|------|------|" << endl;
            move_cursor(shipX, shipY+3);
            cout << "|------|------|" << endl;
            move_cursor(shipX, shipY+4);
            cout << "|             |" << endl;
        
        
        if (_kbhit()) { //проверяем клавишу
            
            char direction = _getch();
            
            if (direction == 'a') {

            shipX = max(shipX - ShipSpeed, 0);//влево
            
            }
            
            else if (direction == 'd') {
                shipX = min(shipX + ShipSpeed, vis - SizeShipX - 1);//вправо
                }

            }
          
        }
        
        Sleep(50);  
    }




return 0;
}
