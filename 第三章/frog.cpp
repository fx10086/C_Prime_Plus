#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
using namespace std;

class Frog{
    private:
        int x, y;
    public:
        Frog();
        void show();
        void move(char);
};

Frog::Frog() {
    long t;
    time(&t); srand(t); x = rand() % 40;
    time(&t); srand(t); y = rand() % 17;
}

void Frog::show() {
    for (int i = 0; i < y; i++) cout << endl;
    cout << setw(x) << "🐸\n";
    //cout << setw(2 + x) << "🐸🐸🐸\n";
}

void Frog::move(char dir) {
    switch (dir) {
        case 'w': if (y > 0) y--; break;
        case 's': if (y < 17) y++; break;
        case 'a': if (x > 0) x--; break;
        case 'd': if (x < 40) x++; break;
    }
    system("clear");
    show();
}

int main() {
    Frog f;
    f.show();
    char dir;
    do {
        dir = getch();
        f.move(dir);
    }while(dir != '#');
    return 0;
}