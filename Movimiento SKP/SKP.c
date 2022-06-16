#include <stdio.h>
#include <windows.h>

void move(int x , int y);


int main()
{
    int x = 8 , y = 19;
    move(x,y);
    printf("(o_o)");

    while(1)
    {
        Sleep(100);

        if (GetAsyncKeyState(0x25)){

            move(x,y); printf("     ");
            x--;
            move(x,y); printf("(o_o)");
        }

        if (GetAsyncKeyState(0x27)){

            move(x,y); printf("     ");
            x++;
            move(x,y); printf("(o_o)");
        }

        if (GetAsyncKeyState(0x28)){

            move(x,y); printf("     ");
            y++;
            move(x,y); printf("(o_o)");
        }
        if (GetAsyncKeyState(0x26)){

            move(x,y); printf("     ");
            y--;
            move(x,y); printf("(o_o)");
        }
    }

    return 0;
}

void move(int x , int y){

HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);

COORD pos;
pos.X = x;
pos.Y = y;

SetConsoleCursorPosition(consola,pos);
}
