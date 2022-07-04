#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>



#include "Funciones.h"



#define ESCENARIO_FILAS 100
#define ESCENARIO_COLUMNAS 100



int main(){
    int i;
    char k,opcion;
    int escenario[ESCENARIO_FILAS][ESCENARIO_COLUMNAS];



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



    do{
            printf ("Ahora debes elegir: pulsa J si deseas aceptar la invitación, I para preguntar las condiciones del trato y E para salir corriendo.\n");
            scanf (" %c", &opcion);
            i = menu(opcion);



        if (i == 1){
            system("cls");
            inicializar_mapa(escenario);
            juego(escenario);
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
            printf ("Volveremos a vernos\n");
        }
    }while (opcion != 'e');

    return 0;
}

