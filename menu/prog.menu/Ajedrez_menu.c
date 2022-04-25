#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main ()
{
    char e_menu;
    int n_aleatorio;
    do
    {
        printf ("Si desea jugar pulse: c, si desea salir pulse: x\n");
        scanf ("%c", &e_menu);
    }
    while (e_menu != 99 && e_menu != 67 && e_menu != 120 && e_menu != 88);
    //valores ASCII para c, C, x, X
    if (e_menu != 120 && e_menu != 88)
    {
        switch (e_menu)
        {
            case 'c':
            case 'C':
                printf ("Si quiere que la elección del color de las piezas sea aleatorio pulse: a, en caso contrario pulse: s\n");
                scanf ("%c", &e_menu);
                switch (e_menu)
                {
                    case 'a':
                    case 'A':
                        srand(time(NULL));
                        n_aleatorio = rand() %2 + 1;
                        if (n_aleatorio = 1)
                        //juegas blancas
                        else
                        //juegas negras
                    case 's':
                    case 'S':
                        printf ("Si quiere blancas pulse: b, si quiere negras pulse: n\n");
                        scanf ("%c", &e_menu);
                        switch (e_menu)
                        {
                            case 'b':
                            case 'B':
                            case 'n':
                            case 'N':
                        }
                }
        }
    }
    else
    return 0;
}
