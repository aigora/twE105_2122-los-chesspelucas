#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>



#define ESCENARIO_FILAS 100
#define ESCENARIO_COLUMNAS 100



void inicializar_mapa(int e[ESCENARIO_FILAS][ESCENARIO_COLUMNAS]);
void posicion(int x , int y);
void juego(int e[ESCENARIO_FILAS][ESCENARIO_COLUMNAS]);
int menu(char op);
int puerta_1(int x, int y);
int laberinto_p2(int x, int y);
int puerta_3(int x, int y);
int buscar_interrogaciones_p4(int x, int y);
int puerta_5(int x, int y);
int puerta_6(int x, int y);
int puerta_7(int x, int y);
int puerta_8(int x, int y);
int puerta_9(int x, int y);
int puerta_10(int x, int y);
int puerta_11(int x, int y);
int puerta_12(int x, int y);
