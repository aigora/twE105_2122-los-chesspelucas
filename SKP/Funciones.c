#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>

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

int ahorcado(int x, int y){
    int xl = 102, yl = 0, i, j;
    int intentos = 0;
    char letra, a='_', b='_', c='_', d='_', e='_', f='_';



            if(x<35 && x>30 && y<18 && y>12){
                    do {
                    posicion (xl, yl);
                    printf ("%c %c %c %c %c %c\n", a,b,c,d,e,f);
                    posicion (xl, yl+1);
                    printf ("Escribe una letra en mayusculas SIN TILDE:");
                    scanf ("%c", &letra);
                    printf ("\n");
                    switch (letra){
                        case 'V':
                            a = 'V';
                        break;
                        case 'E':
                            b = 'E';
                        break;
                        case 'C':
                            c = 'C';
                        break;
                        case 'T':
                            d = 'T';
                        break;
                        case 'O':
                            e = 'O';
                        break;
                        case 'R':
                            f = 'R';
                        break;
                    }



                    if (a == 'V' && b == 'E' && c == 'C' && d == 'T' && e == 'O' && f == 'R'){
                        yl = 0;
                        for(i = 0; i<50; i++){
                            xl = 102;
                            posicion(xl,yl);
                            for(j = 0; j<100; j++){
                                    printf(" ");
                                    xl++;
                            }
                            printf("\n");
                            yl++;
                        }
                        return 1;
                    }
                    intentos++;
                }while (intentos != 15);
                yl = 0;
                for(i = 0; i<50; i++){
                    xl = 102;
                    posicion(xl,yl);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xl++;
                    }
                    printf("\n");
                    yl++;
                }
                return 2;
            }



    return 3;
}

int laberinto(int x, int y){
    int i, j, ms = 30000, xl = 120, yl = 20;
    clock_t start_time = clock();
    int lab[10][10] = {
        {1,1,1,1,1,1,1,1,1,1},
        {0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,0,1,1,0,1},
        {1,0,1,0,0,0,1,0,0,1},
        {1,0,1,1,1,0,1,0,1,1},
        {1,0,0,1,1,0,1,0,0,1},
        {1,0,1,1,0,0,1,1,0,1},
        {1,0,1,1,0,1,1,1,1,1},
        {1,0,1,1,0,0,0,0,0,0},
        {1,1,1,1,1,1,1,1,1,1}
    };
            if(x<70 && x>63 && y<18 && y>12){
                for(i = 0; i<10; i++){
                    posicion(xl,yl);
                    for(j = 0; j<10; j++){
                        if(lab[i][j] == 1){
                            printf("#");
                        }
                        else if(lab[i][j] == 0){
                            printf(" ");
                        }
                    }
                printf("\n");
                yl++;
                }
                xl = 120;
                yl = 21;
                posicion(xl,yl);
                printf("o");
                do{
                    Sleep(100); //Ralentiza el bucle
                    //A
                    if (GetAsyncKeyState(0x41)){

                            posicion(xl,yl);
                            printf(" ");
                            xl--;
                            posicion(xl,yl);
                            printf("o");
                    }
                    //D
                    if (GetAsyncKeyState(0x44)){

                            posicion(xl,yl);
                            printf(" ");
                            xl++;
                            posicion(xl,yl);
                            printf("o");
                    }
                    //S
                    if (GetAsyncKeyState(0x53)){

                            posicion(xl,yl);
                            printf(" ");
                            yl++;
                            posicion(xl,yl);
                            printf("o");
                    }
                    //W
                    if (GetAsyncKeyState(0x57)){

                            posicion(xl,yl);
                            printf(" ");
                            yl--;
                            posicion(xl,yl);
                            printf("o");
                    }
                    if(xl>129){
                        yl = 20;
                        for(i = 0; i<11; i++){
                            xl = 120;
                            posicion(xl,yl);
                            for(j = 0; j<11; j++){
                                    printf(" ");
                                    xl++;
                            }
                            printf("\n");
                            yl++;
                        }
                        return 1;
                    }
                }while(clock() < start_time+ms);
                yl = 20;
                for(i = 0; i<11; i++){
                    xl = 120;
                    posicion(xl,yl);
                    for(j = 0; j<11; j++){
                            printf(" ");
                            xl++;
                    }
                    printf("\n");
                    yl++;
                }
                return 2;
            }
    return 3;
}

int planetas(int x, int y){
    int xi=102, y1=5, i, j;
    char solucion[]="JUPITER", jugador[50];
        if(x<18 && x>12 && y<30 && y>25){
            posicion (xi,y1);
            printf ("Escribe en mayusculas y sin tildes el 5 planeta del sistema solar:");
            posicion(xi, y1+1);
            scanf("%49s", jugador);



            if (strcmp(solucion, jugador)==0){
                y1 = 0;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,y1);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    y1++;
                }
                return 1;
            }
            else{
                y1 = 0;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,y1);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    y1++;
                }
                return 2;
            }
        }
    return 3;
}

int buscar_interrogaciones(int x, int y){
    int i, j, respuesta = 0, n = 0, xl = 120, yl = 20;
    int m[10][10];
    //Da valores aleatorios a la matriz entre el 0 y el 4
    for(i = 0; i<10; i++){
        for(j = 0; j<10; j++){
            m[i][j] = rand() % 5;
            //Cuenta el numero de interrogaciones
            if(m[i][j] == 4)
                n++;
        }
    }
    if(x<53 && x>47 && y<30 && y>25){
                        for(i = 0; i<10; i++){
                            posicion(xl,yl);
                            for(j = 0; j<10; j++){
                                if(m[i][j] == 0){
                                    printf("  ");
                                }
                                else if(m[i][j] == 1){
                                    printf("! ");
                                }
                                else if(m[i][j] == 2){
                                    printf("o ");
                                }
                                else if(m[i][j] == 3){
                                    printf("$ ");
                                }
                                else if(m[i][j] == 4){
                                    printf("? ");
                                }
                            }
                            printf("\n\n");
                            yl += 2;
                        }
                        xl = 150;
                        yl = 20;
                        posicion(xl,yl);
                        printf("Escriba el numero de interrogaciones: ");
                        scanf(" %d", &respuesta);
                        if(respuesta == n){
                            for(i = 0; i<40; i++){
                                xl = 120;
                                posicion(xl,yl);
                                for(j = 0; j<100; j++){
                                        printf(" ");
                                        xl++;
                                }
                                printf("\n");
                                yl++;
                            }
                            return 1;
                        }
                        else{
                            for(i = 0; i<40; i++){
                                xl = 120;
                                posicion(xl,yl);
                                for(j = 0; j<100; j++){
                                        printf(" ");
                                        xl++;
                                }
                                printf("\n");
                                yl++;
                               }
                            return 2;
                        }
                }
    return 3;
}

int gravedad(int x, int y){
    char solucion[]="9.8", jugador[50], i, j;
    int xi=102, yi=0;
        if(x<88 && x>82 && y<30 && y>25){
            posicion (xi,yi);
            printf ("Aproximacion de la aceleracion de la gravedad en m/s. Si tiene decimales separa con '.':");
            scanf("%49s", jugador);



            if (strcmp(solucion, jugador)==0){
                yi = 0;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,yi);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    yi++;
                }
                return 1;
            }
            else{
                yi = 0;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,yi);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    yi++;
                }
                return 2;
            }
        }
    return 3;
}

int satelites(int x, int y){
    char k;
    int xi=140, y1=50,y2=51,y3=52,y4=53, i, j;
    if(x<35 && x>30 && y<53 && y>47){
        posicion (xi,y1);
        printf ("Cual NO es un satelite de Jupiter: ");
        scanf("%c",&k);
        posicion (xi,y2);
        printf ("a)Adonis");
        posicion (xi,y3);
        printf ("b)Europa");
        posicion (xi,y4);
        printf ("c)Ganimedes");



        switch(k){
            case'a':
                y1 = 50;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,y1);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    y1++;
                }
                return 1;
            case 'b':
                y1 = 50;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,y1);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    y1++;
                }
                return 2;
            case 'c':
                y1 = 50;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,y1);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    y1++;
                }
                return 2;
        }
    }
    return 3;
}

int agua(int x, int y){
    char solucion[]="AGUA", jugador[50], i, j;
    int xi=102, yj=50;
    if(x<70 && x>60 && y<53 && y>47){
        posicion (xi, yj);
        printf("Elemento necesario para que se de la vida en un planeta:");
        scanf ("%49s", jugador);



        if (strcmp(jugador, solucion)==0){
            yj = 50;
            for(i = 0; i<50; i++){
                xi = 102;
                posicion(xi,yj);
                for(j = 0; j<100; j++){
                        printf(" ");
                        xi++;
                }
                printf("\n");
                yj++;
            }
            return 1;
        }
        else {
            yj = 50;
            for(i = 0; i<50; i++){
                xi = 102;
                posicion(xi,yj);
                for(j = 0; j<100; j++){
                        printf(" ");
                        xi++;
                }
                printf("\n");
                yj++;
            }
            return 2;
        }
    }



    return 3;
}

int estrella(int x, int y){
    int xi=102, yi=25, yj=26, i, j;
    char solucion[]="PROXIMA-CENTAURI", jugador[50];
    if(x<18 && x>12 && y<70 && y>65){
        posicion(xi,yi);
        printf ("Pista:PROXIMA-C_NT__R_\n");
        posicion (xi, yj);
        printf("Cual es la 2da estrella mas cercana a la Tierra(CUIDADAO CON EL GUION):");
        scanf ("%49s", jugador);



        if (strcmp(jugador, solucion)==0){
            yj = 25;
            for(i = 0; i<50; i++){
                xi = 102;
                posicion(xi,yj);
                for(j = 0; j<100; j++){
                        printf(" ");
                        xi++;
                }
                printf("\n");
                yj++;
            }
            return 1;
        }
        else {
            yj = 25;
            for(i = 0; i<50; i++){
                xi = 102;
                posicion(xi,yj);
                for(j = 0; j<100; j++){
                        printf(" ");
                        xi++;
                }
                printf("\n");
                yj++;
            }
            return 2;
        }
    }
    return 3;
}

int velocidad(int x, int y){
    int xi=102, y1=70, y2=71, y3=72, y4=73, i, j;
    char k;
    if(x<53 && x>47 && y<70 && y>65){
        posicion (xi,y1);
        printf ("Cual es la velocidad de la luz:");
        scanf("%c",&k);
        posicion (xi,y2);
        printf ("a)300 m/s");
        posicion (xi,y3);
        printf ("b)3x10^8 km/s");
        posicion (xi,y4);
        printf ("c)1.08x10^9 km/h");



        switch(k){
            case'a':
                y1 = 70;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,y1);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    y1++;
                }
                return 2;
            case 'b':
                y1 = 70;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,y1);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    y1++;
                }
                return 2;
            case 'c':
                y1 = 70;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,y1);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    y1++;
                }
                return 1;
        }
    }
    return 3;
}

int composicion(int x, int y){
    char k;
    int xi=102, y1=70, y2=71, y3=72, y4=73, i, j;



    if(x<88 && x>82 && y<70 && y>65){
        posicion (xi,y1);
        printf ("Elemento que compone las estrellas principalmente:");
        scanf("%c",&k);
        posicion (xi,y2);
        printf ("a)Nitrogeno");
        posicion (xi,y3);
        printf ("b)Hidrogeno");
        posicion (xi,y4);
        printf ("c)Helio");



        switch(k){
            case'a':
                y1 = 70;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,y1);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    y1++;
                }
                return 2;
            case 'b':
                y1 = 70;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,y1);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    y1++;
                }
                return 1;
            case 'c':
                y1 = 70;
                for(i = 0; i<50; i++){
                    xi = 102;
                    posicion(xi,y1);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xi++;
                    }
                    printf("\n");
                    y1++;
                }
                return 2;
        }
    }
    return 3;
}

int recordar_numero(int x, int y){
    int i, j, n = 69420, r = 0, xl = 120, yl = 50;
        if(x<35 && x>30 && y<87 && y>83){
            posicion(xl,yl);
            printf("%i", n);
            yl++;
            posicion(xl,yl);
            printf("Memoriza los numeros: ");
            Sleep(5000);
            //Borra los mensajes anteriores
            yl--;
            posicion(xl,yl);
            printf("      ");
            yl++;
            posicion(xl,yl);
            printf("                              ");
            //Pide los números de vuelta
            posicion(xl,yl);
            printf("Escribe el codigo:  \n");
            yl++;
            posicion(xl,yl);
            scanf("%i", &r);
            //Comprueba la respuesta
            if(n == r){
                yl = 50;
                for(i = 0; i<20; i++){
                    xl = 120;
                    posicion(xl,yl);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xl++;
                    }
                    printf("\n");
                    yl++;
                }
                return 1;
            }
            else{
                yl = 50;
                for(i = 0; i<20; i++){
                    xl = 120;
                    posicion(xl,yl);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xl++;
                    }
                    printf("\n");
                    yl++;
                }
                return 2;
            }
        }
    return 3;
}

int codigo_secreto(int x, int y){
    int i, j, xl = 120, yl = 50;
    char respuesta[12], codigo[12] = "HELLO-WORLD";
        if(x<70 && x>60 && y<87 && y>83){
            posicion(xl,yl);
            printf("Traduce este codigo a un lenguaje que puedas entender (pista: sumale 2): 6 3 10 10 13 - 21 13 16 10");
            yl++;
            posicion(xl,yl);
            scanf("%11s", respuesta);
            if(strcmp(respuesta, codigo) == 0){
                yl = 50;
                for(i = 0; i<20; i++){
                    xl = 120;
                    posicion(xl,yl);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xl++;
                    }
                    printf("\n");
                    yl++;
                }
                return 1;
            }
            else{
                yl = 50;
                for(i = 0; i<20; i++){
                    xl = 120;
                    posicion(xl,yl);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xl++;
                    }
                    printf("\n");
                    yl++;
                }
                return 2;
            }
        }
    return 3;
}

int decision_final(int x, int y){
    int xl = 120, yl = 70, i, j;
    char k;
    if((x<10 && x>0 && y<100 && y>90) || (x<100 && x>90 && y<100 && y>90)){
        posicion (xl,yl);
        printf ("Estas en un tren sin control, delante las vias se separan y debes decidir que camino seguir:  ");
        yl++;
        posicion (xl,yl);
        printf ("a)Giras a la derecha atropellando a una madre con sus tres hijos recién nacidos");
        yl++;
        posicion (xl,yl);
        printf ("b)Giras a la izquierda atropellando a tu padre");
        yl++;
        posicion (xl,yl);
        printf ("c)Sigues recto llegando al final de la via y acabas muriendo");
        yl++;
        posicion(xl,yl);
        scanf("%c", &k);
        switch(k){
            case'a':
                yl = 70;
                for(i = 0; i<50; i++){
                    xl = 120;
                    posicion(xl,yl);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xl++;
                    }
                    printf("\n");
                    yl++;
                }
                return 2;
            case 'b':
                yl = 70;
                for(i = 0; i<50; i++){
                    xl = 120;
                    posicion(xl,yl);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xl++;
                    }
                    printf("\n");
                    yl++;
                }
                return 1;
            case 'c':
                yl = 70;
                for(i = 0; i<50; i++){
                    xl = 120;
                    posicion(xl,yl);
                    for(j = 0; j<100; j++){
                            printf(" ");
                            xl++;
                    }
                    printf("\n");
                    yl++;
                }
                return 2;
        }
    }
return 3;
}

void recopilatorio_jugadores(datos_jugador jugador){
    FILE *fDatos;
    fDatos = fopen("Datos.txt","a");
    if(fDatos == NULL){
        printf("Error al abrir el fichero.Datos\n");
    }
    else{
        fprintf(fDatos, "/n%s %s %i;%i;%i", jugador.nombre, jugador.apellido, jugador.fecha.day, jugador.fecha.month, jugador.fecha.year);
    }
    fclose(fDatos);
}

void juego(int e[ESCENARIO_FILAS][ESCENARIO_COLUMNAS]){

    int x = 50, y = 2, p, f = 1;
    posicion(x,y);
    printf("(o_o)");

    while(f != 0){
        Sleep(200); //Ralentiza el bucle
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
        p = ahorcado(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x -= 11;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = laberinto(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x += 7;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = planetas(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = buscar_interrogaciones(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = gravedad(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = satelites(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x -= 11;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = agua(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x += 12;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = estrella(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = velocidad(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = composicion(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 6;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = recordar_numero(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x -= 11;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = codigo_secreto(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            x += 12;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        p = decision_final(x,y);
        if(p == 1){
            posicion(x,y);
            printf("     ");
            y += 10;
            posicion(x,y);
            printf("(o_o)");
        }
        if(p == 2){
            posicion(x,y);
            printf("     ");
            x = 50;
            y = 2;
            posicion(x,y);
            printf("(o_o)");
        }
        if(y>110){
            f = 0;
        }
    }
}
