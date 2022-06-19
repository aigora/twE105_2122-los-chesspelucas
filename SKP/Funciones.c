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
    /*for(i = 0; i<60; i++){
        e[30][i] = 1;
    }*/
    for(i = 0; i<50; i++){
        e[i][60] = 1;
    }
    for(i = 50; i<ESCENARIO_COLUMNAS; i++){
        e[50][i] = 1;
    }
    for(i = 50; i<80; i++){
        e[i][50] = 1;
    }
    for(i = 0; i<ESCENARIO_COLUMNAS; i++){
        e[80][i] = 1;
    }
    for(j = 30; j<ESCENARIO_COLUMNAS; j += 40){
        for(i = 80; i<ESCENARIO_FILAS; i++)
            e[i][j] = 1;
    }
    for(i = 0; i<ESCENARIO_FILAS; i++){
        for(j = 0; j<ESCENARIO_COLUMNAS; j++){
            if(e[i][j] == 1){
                printf("#");
            }
            else if(e[i][j] == 0){
                printf(" ");
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
