#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int maze[8][8] = {
        {0,1,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0},
        {0,1,1,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
        {0,1,1,1,1,0,0,0},
        {0,1,0,0,1,1,0,0},
        {0,1,1,0,0,1,0,0},
        {0,0,0,0,0,1,0,0}
    };

    int row = 0;
    int col = 1;
    int steps = 0;

    cout << "Начинаем движение по лабиринту:" << endl;

    while (row != 7 || col != 2) {
        cout << "Шаг " << steps << ": позиция (" << row << "," << col << ")" << endl;

        if (row < 7 && maze[row + 1][col] == 1) {
            row++;
            steps++;
            cout << "  Иду ВНИЗ -> (" << row << "," << col << ")" << endl;
        }
        else if (col < 7 && maze[row][col + 1] == 1) {
            col++;
            steps++;
            cout << "  Иду ВПРАВО -> (" << row << "," << col << ")" << endl;
        }
        else if (col > 0 && maze[row][col - 1] == 1) {
            col--;
            steps++;
            cout << "  Иду ВЛЕВО -> (" << row << "," << col << ")" << endl;
        }
        else {
            cout << "  ТУПИК! Не могу двигаться из позиции (" << row << "," << col << ")" << endl;
            break;
        }
    }

    if (row == 7 && col == 2) {
        cout << "УСПЕХ! Достигнута конечная точка (" << row << "," << col << ")" << endl;
    }
    else {
        cout << "ПРОВАЛ! Застряли в позиции (" << row << "," << col << ")" << endl;
    }

    cout << "Всего шагов: " << steps << endl;

    return 0;
}