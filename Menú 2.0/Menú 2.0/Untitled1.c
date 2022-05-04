
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char eleccionmenu(char f);

int main ()
{
    char e_menu, eleccion_f;
    do
    {
        printf ("Si desea jugar pulse: c, si desea salir pulse: x, si desea abrir las reglas pulse: r\n");
        scanf ("%c", &e_menu);
    }
    while (e_menu != 99 && e_menu != 67 && e_menu != 120 && e_menu != 88 && e_menu != 114 && e_menu !=82);
    //valores ASCII para c, C, x, X

    if (e_menu == 114 || e_menu ==82 )
    {
        FILE *reglas = NULL;
        reglas=fopen("ficheroajedrez.txt", "r");  
        char regla[50];

        while (fscanf(reglas, "%[^\n]%c", regla) !=EOF){ 
                printf("%s\n",regla);
        }
        fclose(reglas);
    }
    if (e_menu != 120 && e_menu != 88)
    {
       eleccion_f = eleccionmenu(e_menu);
    }
    if (eleccion_f = 66)
    {

        //Jugador 1 blancas
    }
    else
    {
        //Jugador 1 negras
    }
    return 0;
}
char eleccionmenu(char f)
{
    int n_aleatorio;
    switch (f)
        {
            case 'c':
            case 'C':
                printf ("Si quiere que la elección del color de las piezas sea aleatorio pulse: a, en caso contrario pulse: s\n");
                scanf ("%c", &f);
                switch (f)
                {
                    case 'a':
                    case 'A':
                        srand(time(NULL));
                         n_aleatorio = rand() %2 + 1;
                        if (n_aleatorio = 1)
                        return 66;//juegas blancas
                        else
                        return 2;//juegas negras
                    break;
                    case 's':
                    case 'S':
                        printf ("Si quiere blancas pulse: b, si quiere negras pulse: n\n");
                        scanf ("%c", &f);
                        switch (f)
                        {
                            case 'b':
                            case 'B':
                                return 66;
                            break;
                            case 'n':
                            case 'N':
                                return 2;
                            break;
                        }
                    break;
                }
        }
}
