#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    char direction;

    int shipPosition = 0;

    while (true) {
        if (_kbhit()) { //проверяем клавишу

            direction = _getch();

            if (direction == 'a') {

                shipPosition--;

                cout << shipPosition << endl;

            }
            else if (direction == 'd') {

                shipPosition++;

                cout << shipPosition << endl;

            }
        }
    }
    return 0;
}