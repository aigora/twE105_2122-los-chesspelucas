#include <SDL.h>
#include <stdio.h>



#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define FILAS 800
#define COLUMNAS 800



void crear_tablero(int x, int y, SDL_Renderer *rend, SDL_Texture *t, SDL_Rect rec);



int main(int argc, char *argv[])
{
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_Texture *texture;
        SDL_Event event;
        SDL_Rect r;



        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "No se pudo inicializar SDL: %s", SDL_GetError());
                return 3;
        }
        window = SDL_CreateWindow("SDL_CreateTexture",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_RESIZABLE);
        r.w = 100;
        r.h = 100;
        renderer = SDL_CreateRenderer(window, -1, 0);
        texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WINDOW_WIDTH, WINDOW_HEIGHT);



        while (1) {
                SDL_PollEvent(&event);
                if(event.type == SDL_QUIT)
                        break;
        crear_tablero(FILAS, COLUMNAS, renderer, texture, r);
        }
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        return 0;
}



void crear_tablero(int x, int y, SDL_Renderer *rend, SDL_Texture *t, SDL_Rect rec){
    for (int i = 0; i<x; i += 200){
            for (int j = 0; j<y; j += 200){
                rec.x=i;
                rec.y=j;
                SDL_SetRenderTarget(rend, t);
                SDL_SetRenderDrawColor(rend, 0, 0, 0, 250);
                SDL_RenderDrawRect(rend,&rec);
                SDL_SetRenderDrawColor(rend, 250, 250, 250, 250);
                SDL_RenderFillRect(rend, &rec);
                SDL_SetRenderTarget(rend, NULL);
                SDL_RenderCopy(rend, t, NULL, NULL);
                SDL_RenderPresent(rend);
            }
    }
    for (int i = 100; i<x; i += 200){
            for (int j = 100; j<y; j += 200){
                rec.x=i;
                rec.y=j;
                SDL_SetRenderTarget(rend, t);
                SDL_SetRenderDrawColor(rend, 0, 0, 0, 250);
                SDL_RenderDrawRect(rend,&rec);
                SDL_SetRenderDrawColor(rend, 250, 250, 250, 250);
                SDL_RenderFillRect(rend, &rec);
                SDL_SetRenderTarget(rend, NULL);
                SDL_RenderCopy(rend, t, NULL, NULL);
                SDL_RenderPresent(rend);
            }
    }
}
