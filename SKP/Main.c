#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>



#include "Funciones.h"



#define ESCENARIO_FILAS 100
#define ESCENARIO_COLUMNAS 100



int main(){
    int i;
    char k,opcion;
    int escenario[ESCENARIO_FILAS][ESCENARIO_COLUMNAS];
    datos_jugador usuario;



    FILE *fplot,*finstrucciones;
    fplot = fopen("Plot.txt", "r");



    if (fplot == NULL) {
        printf("Error al abrir el fichero.Plot\n");
        return -1;
    }
    else{
        while (fscanf(fplot,"%c",&k) != EOF){
        printf("%c",k);
        }
    }
    fclose(fplot);
    printf("\n");



    do{
            printf ("Ahora debes elegir: pulsa J para empezar la prueba, I para saber mas sobre SKP y E para suicidarte.\n");
            scanf (" %c", &opcion);
            i = menu(opcion);


        if (i == 1){
            printf("Escriba su nombre y apellido:\n");
            scanf("%19s %19s", usuario.nombre, usuario.apellido);
            printf("Introduce la fecha separada por espacios: dd mm aaaa\n");
            scanf("%i %i %i", &usuario.fecha.day, &usuario.fecha.month, &usuario.fecha.year);
            recopilatorio_jugadores(usuario);
            system("cls");
            inicializar_mapa(escenario);
            juego(escenario);
            return 0;
        }
        else if (i == 2){
            finstrucciones = fopen ("Instrucciones SKP.txt", "r");



            if (finstrucciones == NULL){
                    printf ("Error al abrir fichero.Instrucciones SKP\n");
                    return -1;
            }
            else{
                    while (fscanf(finstrucciones,"%c",&k) != EOF){
                    printf("%c", k);
                    }



            }
            fclose(finstrucciones);
            printf ("\n");
            scanf ("%c", &opcion);
        }
        else{
            printf ("Lo siento mama...\n");
        }
    }while (opcion != 'e' || opcion != 'E');

    return 0;
}

