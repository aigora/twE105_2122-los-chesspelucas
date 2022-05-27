#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <math.h>



#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define CASILLA 100



void inicializar_tablero(int fi, int co, int cas[8][8]);
void crear_tablero(int f, int c, SDL_Renderer *rend, int color[8][8]);
void inicializar_piezas(SDL_Renderer *rend, int n);
void peon_n(SDL_Renderer *rend, int x, int y);
void peon_b(SDL_Renderer *rend, int x, int y);
void torre_n (SDL_Renderer *rend, int x, int y);
void torre_b (SDL_Renderer *rend, int x, int y);
void alfil_n (SDL_Renderer *rend, int x, int y);
void alfil_b (SDL_Renderer *rend, int x, int y);
void rey_n (SDL_Renderer *rend, int x, int y);
void rey_b (SDL_Renderer *rend, int x, int y);
void reina_n (SDL_Renderer *rend, int x, int y);
void reina_b (SDL_Renderer *rend, int x, int y);
void caballo_n (SDL_Renderer *rend, int x, int y);
void caballo_b (SDL_Renderer *rend, int x, int y);



int main(int argc, char *argv[])
{
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Event event;
        int casillas [8][8];
        int x , y, xa = 0, ya = 0, fila = 0, columna = 0, cx = 0, cy = 100;
        const int FILAS = 8;
        const int COLUMNAS = 8;




        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "No se pudo inicializar SDL: %s", SDL_GetError());
                return 3;
        }
        window = SDL_CreateWindow("Ventana principal",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
        renderer = SDL_CreateRenderer(window, -1, 0);



        inicializar_tablero(FILAS, COLUMNAS, casillas);
        crear_tablero(FILAS, COLUMNAS, renderer, casillas);
        inicializar_piezas(renderer, 0);


        while (1) {
                SDL_PollEvent(&event);
                if(event.type == SDL_QUIT)
                    break;
                else if(event.type == SDL_MOUSEBUTTONDOWN){
                    if(event.button.x>cx && event.button.x<cx+100 && event.button.y>cy && event.button.y<cy+100){
                        printf("Ingrese casillas que desea desplazarse: abajo(-arriba) derecha(-izquierda)\n");
                        scanf("%i %i", &columna, &fila);
                        x = (fila*100)+xa;
                        y = (columna*100)+ya;
                        xa = x;
                        ya = y;
                        SDL_RenderClear(renderer);
                        crear_tablero(FILAS, COLUMNAS, renderer, casillas);
                        inicializar_piezas(renderer, 7);
                        peon_n(renderer, x, y);
                        cx = 0+x;
                        cy = 100+y;
                    }
                }
        }



        SDL_DestroyRenderer(renderer);
        SDL_Quit();



        return 0;
}



void inicializar_tablero(int fi, int co, int cas[8][8]){
    for (int i = 0; i<fi; i += 1){
            for (int j = 0; j<co; j += 1){
                    if((i+j)%2 == 0){
                        cas[i][j] = 1;
                    }
                    else if((i+j)!= 0){
                        cas[i][j] = 0;
                    }
            }
    }
}

void crear_tablero(int f, int c, SDL_Renderer *rend, int color[8][8]){
    int x, y;
    SDL_Rect fillrect;
    fillrect.w = CASILLA;
    fillrect.h = CASILLA;
    for (int i = 0; i<f; i += 1){
            for (int j = 0; j<c; j += 1){
                    x = j*100;
                    y = i*100;
                    fillrect.x = x;
                    fillrect.y = y;
                    if(color[i][j] == 1){
                        SDL_SetRenderDrawColor(rend, 192, 192, 192, 255);
                    }
                    else if(color[i][j] == 0){
                        SDL_SetRenderDrawColor(rend, 0, 128, 128, 255);
                    }
            SDL_RenderFillRect(rend, &fillrect);
            SDL_RenderPresent(rend);
            }
    }
}

void peon_n(SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderDrawLine(rend, 20+x, 180+y, 80+x, 120+y);
    SDL_RenderDrawLine(rend, 80+x, 180+y, 20+x, 120+y);
    SDL_RenderPresent(rend);
}

void peon_b(SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 220, 250, 250, 255);
    SDL_RenderDrawLine(rend, 20+x, 620+y, 80+x, 680+y);
    SDL_RenderDrawLine(rend, 20+x, 680+y, 80+x, 620+y);
    SDL_RenderPresent(rend);
}
void torre_n (SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderDrawLine(rend, 20+x, 20+y, 80+x, 20+y);
    SDL_RenderDrawLine(rend, 20+x, 20+y, 20+x, 80+y);
    SDL_RenderDrawLine(rend, 80+x, 80+y, 80+x, 20+y);
    SDL_RenderDrawLine(rend, 80+x, 80+y, 20+x, 80+y);
    SDL_RenderPresent(rend);
}
void torre_b (SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 250, 250, 250, 255);
    SDL_RenderDrawLine(rend, 20+x, 720+y, 80+x, 720+y);
    SDL_RenderDrawLine(rend, 20+x, 720+y, 20+x, 780+y);
    SDL_RenderDrawLine(rend, 80+x, 780+y, 80+x, 720+y);
    SDL_RenderDrawLine(rend, 80+x, 780+y, 20+x, 780+y);
    SDL_RenderPresent(rend);
}
void alfil_n (SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderDrawLine(rend, 220+x, 80+y, 280+x, 80+y);
    SDL_RenderDrawLine(rend, 220+x, 80+y, 250+x, 20+y);
    SDL_RenderDrawLine(rend, 280+x, 80+y, 250+x, 20+y);
    SDL_RenderPresent(rend);
}
void alfil_b (SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 250, 250, 250, 255);
    SDL_RenderDrawLine(rend, 220+x, 780+y, 280+x, 780+y);
    SDL_RenderDrawLine(rend, 220+x, 780+y, 250+x, 720+y);
    SDL_RenderDrawLine(rend, 280+x, 780+y, 250+x, 720+y);
    SDL_RenderPresent(rend);
}
void rey_n (SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderDrawLine(rend, 450+x, 20+y, 450+x, 80+y);
    SDL_RenderDrawLine(rend, 420+x, 50+y, 480+x, 50+y);
    SDL_RenderDrawLine(rend, 420+x, 50+y, 420+x, 20+y);
    SDL_RenderDrawLine(rend, 480+x, 50+y, 480+x, 20+y);
    SDL_RenderPresent(rend);
}
void rey_b (SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 250, 250, 250, 255);
    SDL_RenderDrawLine(rend, 450+x, 720+y, 450+x, 780+y);
    SDL_RenderDrawLine(rend, 420+x, 750+y, 480+x, 750+y);
    SDL_RenderDrawLine(rend, 420+x, 750+y, 420+x, 720+y);
    SDL_RenderDrawLine(rend, 480+x, 750+y, 480+x, 720+y);
    SDL_RenderPresent(rend);
}
void reina_n (SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderDrawLine(rend, 320+x, 20+y, 380+x, 20+y);
    SDL_RenderDrawLine(rend, 320+x, 20+y, 350+x, 80+y);
    SDL_RenderDrawLine(rend, 380+x, 20+y, 350+x, 80+y);
    SDL_RenderDrawLine(rend, 340+x, 20+y, 350+x, 80+y);
    SDL_RenderDrawLine(rend, 360+x, 20+y, 350+x, 80+y);
    SDL_RenderPresent(rend);
}
void reina_b (SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 250, 250, 250, 255);
    SDL_RenderDrawLine(rend, 320+x, 720+y, 380+x, 720+y);
    SDL_RenderDrawLine(rend, 320+x, 720+y, 350+x, 780+y);
    SDL_RenderDrawLine(rend, 380+x, 720+y, 350+x, 780+y);
    SDL_RenderDrawLine(rend, 340+x, 720+y, 350+x, 780+y);
    SDL_RenderDrawLine(rend, 360+x, 720+y, 350+x, 780+y);
    SDL_RenderPresent(rend);
}
void caballo_n (SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderDrawLine(rend, 120+x, 20+y, 180+x, 80+y);
    SDL_RenderDrawLine(rend, 150+x, 50+y, 120+x, 80+y);
    SDL_RenderPresent(rend);
}
void caballo_b (SDL_Renderer *rend, int x, int y){
    SDL_SetRenderDrawColor(rend, 250, 250, 250, 255);
    SDL_RenderDrawLine(rend, 120+x, 720+y, 180+x, 780+y);
    SDL_RenderDrawLine(rend, 150+x, 750+y, 120+x, 780+y);
    SDL_RenderPresent(rend);
}


void inicializar_piezas(SDL_Renderer *rend, int n){
    if(n != 7){
        for(int i = 0; i<8; i++){
            peon_n(rend, CASILLA*i, 0);
            peon_b(rend, CASILLA*i, 0);
        }
    }
    torre_n (rend,0,0);
    torre_n (rend,700,0);
    torre_b (rend, 0,0);
    torre_b (rend, 700,0);
    alfil_n (rend, 0,0);
    alfil_n (rend, 300,0);
    alfil_b (rend, 0,0);
    alfil_b (rend, 300,0);
    rey_n (rend, 0, 0);
    rey_b (rend, 0, 0);
    reina_n (rend, 0, 0);
    reina_b (rend, 0, 0);
    caballo_n (rend, 0, 0);
    caballo_n (rend, 500, 0);
    caballo_b (rend, 0, 0);
    caballo_b (rend, 500, 0);
}

