#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>



#define ESCENARIO_FILAS 100
#define ESCENARIO_COLUMNAS 100



void inicializar_mapa(int e[ESCENARIO_FILAS][ESCENARIO_COLUMNAS]);
void posicion(int x , int y);
void juego(int e[ESCENARIO_FILAS][ESCENARIO_COLUMNAS]);
int menu(char op);
int ahorcado(int x, int y);
int laberinto_p2(int x, int y);
int planetas(int x, int y);
int buscar_interrogaciones_p4(int x, int y);
int gravedad(int x, int y);
int satelites(int x, int y);
int agua(int x, int y);
int estrella(int x, int y);
int velocidad(int x, int y);
int composicion(int x, int y);
int puerta_11(int x, int y);
int puerta_12(int x, int y);
