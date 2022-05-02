#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    char tablero[8][8];

    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            if(i==1)
            {
                tablero[i][j]= 'p'; //Peones negros
            }
            else if(i==6)
            {
                tablero[i][j]= 'P'; //Peones blancos
            }
            else if(i==0 && j==0 || i==0 && j==7)
            {
                tablero[i][j]= 't'; //Torres negras
            }
            else if(i==7 && j==0 || i==7 && j==7)
            {
                tablero[i][j]= 'T'; //Torres blancas
            }
            else if(i==0 && j==1 || i==0 && j==6)
            {
                tablero[i][j]= 'c'; //Caballos negros
            }
            else if(i==7 && j==1 || i==7 && j==6)
            {
                tablero[i][j]= 'C'; //Caballos blancos
            }
            else if(i==0 && j==2 || i==0 && j==5)
            {
                tablero[i][j]= 'a'; //Alfiles negros
            }
            else if(i==7 && j==2 || i==7 && j==5)
            {
                tablero[i][j]= 'A'; //Alfiles blancos
            }
            else if(i==0 && j==3)
            {
                tablero[i][j]= 'd'; //Dama negra
            }
            else if(i==7 && j==3)
            {
                tablero[i][j]= 'D'; //Dama blanca
            }
            else if(i==0 && j==4)
            {
                tablero[i][j]= 'r'; //Ret negro
            }
            else if(i==7 && j==4)
            {
                tablero[i][j]= 'R'; //Rey blanco
            }
            else
            {
                tablero[i][j]= '\0';
            }

        }
    }

    for(i=0; i<8; i++)
    {
        printf("\n");
        for(j=0; j<8; j++)
        {
            printf("%c", tablero[i][j]);
        }
    }

    return 0;
}
