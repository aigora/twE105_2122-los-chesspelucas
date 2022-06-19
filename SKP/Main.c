#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Funciones.h"

#define ESCENARIO_FILAS 100
#define ESCENARIO_COLUMNAS 100



int main(){



    int escenario[ESCENARIO_FILAS][ESCENARIO_COLUMNAS];
    int x = 50 , y = 5;



    inicializar_mapa(escenario);



    posicion(x,y);
    printf("(o_o)");
    while(1){
        Sleep(100); //Ralentiza el bucle
        //Flecha izquierda
        if (GetAsyncKeyState(0x25)){

            if(escenario[x-1][y] == 0){
                posicion(x,y);
                printf("     ");
                x--;
                posicion(x,y);
                printf("(o_o)");
            }
        }
        //Flecha derecha
        if (GetAsyncKeyState(0x27)){

            if(escenario[x+5][y] == 0){
                posicion(x,y);
                printf("     ");
                x++;
                posicion(x,y);
                printf("(o_o)");
            }
        }
        //Flecha abajo
        if (GetAsyncKeyState(0x28)){

            if(escenario[x][y+1] == 0){
                posicion(x,y);
                printf("     ");
                y++;
                posicion(x,y);
                printf("(o_o)");
            }
        }
        //Flecha arriba
        if (GetAsyncKeyState(0x26)){

            if(escenario[x][y-1] == 0){
                posicion(x,y); printf("     ");
                y--;
                posicion(x,y); printf("(o_o)");
            }
        }
    }



    return 0;
}

