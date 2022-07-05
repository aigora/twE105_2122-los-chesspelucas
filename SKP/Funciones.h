#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>



#define ESCENARIO_FILAS 100
#define ESCENARIO_COLUMNAS 100



typedef struct{
    int day;
    int month;
    int year;
}date;
typedef struct{
    char nombre[20];
    char apellido[20];
    date fecha;
}datos_jugador;



void inicializar_mapa(int e[ESCENARIO_FILAS][ESCENARIO_COLUMNAS]);
void posicion(int x , int y);
void recopilatorio_jugadores(datos_jugador jugador);
void juego(int e[ESCENARIO_FILAS][ESCENARIO_COLUMNAS]);
int menu(char op);
int ahorcado(int x, int y);
int laberinto(int x, int y);
int planetas(int x, int y);
int buscar_interrogaciones(int x, int y);
int gravedad(int x, int y);
int satelites(int x, int y);
int agua(int x, int y);
int estrella(int x, int y);
int velocidad(int x, int y);
int composicion(int x, int y);
int recordar_numero(int x, int y);
int codigo_secreto(int x, int y);
int decision_final(int x, int y);
