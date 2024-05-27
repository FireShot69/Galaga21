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

struct bullet {
    int x;
    int y;
};

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

        // Позиция объекта
        int x = 20, y = 45;
        bullet *pulka = new bullet{ x, y };


        /*int * bullet_count = new int{ 1 };
        bullet* bullets = new bullet[*bullet_count]{};*/

        char laser = '|';
        // Основной цикл
        while (true)
        {
            // Очистка экрана
            system("cls");
            
            if (GetAsyncKeyState(VK_UP))
            {
                cout << string(pulka->y++, '\n') << string(pulka -> x, ' ') << laser << endl;
            }
                /*{
                
                bullets[*(bullet_count)-1] = *pulka;

            }
            for (size_t i = 0; i < *bullet_count; i++)
            {
                cout << string(bullets[i].y, '\n') << string(bullets[i].x, ' ') << laser << endl;
            }*/


            // Отрисовка объекта
            cout << string(y--, '\n') << string(x, ' ') << "|>-0-<|" << endl;
            
            // Обработка нажатий на стрелки
            if (GetAsyncKeyState(VK_LEFT))
                if (x != 0)
                x--;
            if (GetAsyncKeyState(VK_RIGHT))
                if (x != 43)
                x++;
            
            
            // Задержка
            Sleep(500);
        }

        return 0;
    }


