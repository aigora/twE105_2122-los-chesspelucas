#include <stdio.h>
#include <stdlib.h>

int main(){
    int escenario[100][100];
    int i, j, x = 9, y = 7;
    for(i = 0; i<100; i++){
        for(j = 0; j<100; j++)
            escenario[i][j] = 1;
    }
    for(i = 1; i<99; i++){
        for(j = 1; j<99; j++)
            escenario[i][j] = 0;
    }
    escenario[y][x] = 2;
    for(i = 0; i<100; i++){
        for(j = 0; j<100; j++){
            if(escenario[i][j] == 1){
                printf("|");
            }
            else if(escenario[i][j] == 0){
                printf(" ");
            }
            else if(escenario[i][j] == 2){
                printf("R");
            }
        }
    printf("\n");
    }
    return 0;
}
