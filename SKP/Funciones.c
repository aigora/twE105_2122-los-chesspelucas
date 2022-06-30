#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Funciones.h"

#define ESCENARIO_FILAS 100
#define ESCENARIO_COLUMNAS 100



void inicializar_mapa(int e[ESCENARIO_FILAS][ESCENARIO_COLUMNAS]){



    int i, j;



    for(i = 0; i<ESCENARIO_FILAS; i++){
        for(j = 0; j<ESCENARIO_COLUMNAS; j++)
            e[i][j] = 0;
    }
    for(i = 0; i<ESCENARIO_FILAS; i+=(ESCENARIO_FILAS-1)){
        for(j = 1; j<ESCENARIO_COLUMNAS-1; j++)
            e[i][j] = 1;
    }
    for(j = 0; j<ESCENARIO_FILAS; j+=(ESCENARIO_FILAS-1)){
        for(i = 1; i<ESCENARIO_COLUMNAS-1; i++)
            e[i][j] = 1;
    }
    for(i = 0; i<ESCENARIO_COLUMNAS; i++){
        e[30][i] = 1;
        e[70][i] = 1;
    }
    for(i = 0; i<ESCENARIO_FILAS; i++){
        e[i][30] = 1;
        e[i][70] = 1;
    }
    for(j = 30; j<ESCENARIO_FILAS; j+=40){
        for(i = 12; i<18; i++){
            e[j][i] = 2;
        }
    }
    for(j = 30; j<ESCENARIO_FILAS; j+=40){
        for(i = 46; i<54; i++){
            e[j][i] = 2;
        }
    }
    for(j = 30; j<ESCENARIO_FILAS; j+=40){
        for(i = 82; i<88; i++){
            e[j][i] = 2;
        }
    }
    for(j = 30; j<ESCENARIO_FILAS; j+=40){
        for(i = 12; i<18; i++){
            e[i][j] = 2;
        }
    }
    for(j = 30; j<ESCENARIO_FILAS; j+=40){
        for(i = 46; i<54; i++){
            e[i][j] = 2;
        }
    }
    for(j = 30; j<ESCENARIO_FILAS; j+=40){
        for(i = 82; i<88; i++){
            e[i][j] = 2;
        }
    }
    for(j = 30; j<ESCENARIO_FILAS; j+=40){
        for(i = 12; i<18; i++){
            e[i][j] = 2;
        }
    }
    for(i = 0; i<ESCENARIO_FILAS; i++){
        for(j = 0; j<ESCENARIO_COLUMNAS; j++){
            if(e[i][j] == 1){
                printf("#");
            }
            else if(e[i][j] == 0){
                printf(" ");
            }
            else if(e[i][j] != 1 && e[i][j] != 0){
                printf("/");
            }
        }
    printf("\n");
    }
}

void posicion(int x , int y){



    HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(consola,pos);
}

int menu(char op){
    switch (op){
        case 'j':
        case 'J':
            return 1;
        break;
        case 'i':
        case'I':
            return 2;
        break;
        case 'e':
        case 'E':
            return 3;
        break;
    }
    return 3;
}

int puerta_1(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<35 && x>30 && y<18 && y>12){
                return 1;
            }
            else if(x<30 && x>20 && y<18 && y>12)
                return 2;
        }
    return 3;
}

int puerta_2(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<70 && x>60 && y<18 && y>12){
                return 1;
            }
        }
    return 3;
}

int puerta_3(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<18 && x>12 && y<30 && y>25){
                return 1;
            }
        }
    return 3;
}

int puerta_4(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<53 && x>47 && y<30 && y>25){
                return 1;
            }
        }
    return 3;
}

int puerta_5(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<88 && x>82 && y<30 && y>25){
                return 1;
            }
        }
    return 3;
}

int puerta_6(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<35 && x>30 && y<53 && y>47){
                return 1;
            }
        }
    return 3;
}

int puerta_7(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<70 && x>60 && y<53 && y>47){
                return 1;
            }
        }
    return 3;
}

int puerta_8(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<18 && x>12 && y<70 && y>65){
                return 1;
            }
        }
    return 3;
}

int puerta_9(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<53 && x>47 && y<70 && y>65){
                return 1;
            }
        }
    return 3;
}

int puerta_10(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<88 && x>82 && y<70 && y>65){
                return 1;
            }
        }
    return 3;
}

int puerta_11(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<35 && x>30 && y<87 && y>83){
                return 1;
            }
        }
    return 3;
}

int puerta_12(int x, int y){
    if (GetAsyncKeyState(0x02)){
            if(x<70 && x>60 && y<87 && y>83){
                return 1;
            }
        }
    return 3;
}

void juego(int e[ESCENARIO_FILAS][ESCENARIO_COLUMNAS]){

    int x = 50, y = 2, p, f = 1;
    posicion(x,y);
    printf("(o_o)");

    while(f != 0){
        Sleep(100); //Ralentiza el bucle
        //Flecha izquierda
        if (GetAsyncKeyState(0x25)){

            if(e[x-1][y] == 0){
                posicion(x,y);
                printf("     ");
                x--;
                posicion(x,y);
                printf("(o_o)");
            }
        }
        //Flecha derecha
        if (GetAsyncKeyState(0x27)){

            if(e[x+5][y] == 0){
                posicion(x,y);
                printf("     ");
                x++;
                posicion(x,y);
                printf("(o_o)");
            }
        }
        //Flecha abajo
        if (GetAsyncKeyState(0x28)){

            if(e[x][y+1] == 0){
                posicion(x,y);
                printf("     ");
                y++;
                posicion(x,y);
                printf("(o_o)");
            }
        }
        //Flecha arriba
        if (GetAsyncKeyState(0x26)){

            if(e[x][y-1] == 0){
                posicion(x,y);
                printf("     ");
                y--;
                posicion(x,y);
                printf("(o_o)");
            }
        }
        p = puerta_1(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x -= 11;
            posicion(x,y);
            printf("(o_o)");
        }
        else if(p == 3){
            posicion(x,y);
            printf("     ");
            x += 10;
            posicion(x,y);
            printf("(o_o)");
        }
        p = puerta_2(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        p = puerta_3(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        p = puerta_4(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        p = puerta_5(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        p = puerta_6(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x -= 11;
            posicion(x,y);
            printf("(o_o)");
        }
        p = puerta_7(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        p = puerta_8(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        p = puerta_9(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        p = puerta_10(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        p = puerta_11(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x -= 11;
            posicion(x,y);
            printf("(o_o)");
        }
        p = puerta_12(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        if(y>100){
            f = 0;
        }
    }
}
