#include <SDL.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

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
        for (int i=0; i<1000; i= i+200){
            for (int j=0; j<1000; j=j+200){
                r.x=i;
                r.y=j;
                SDL_SetRenderTarget(renderer, texture);
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 250);
                SDL_RenderDrawRect(renderer,&r);
                SDL_SetRenderDrawColor(renderer, 250, 250, 250, 250);
                SDL_RenderFillRect(renderer, &r);
                SDL_SetRenderTarget(renderer, NULL);
                SDL_RenderCopy(renderer, texture, NULL, NULL);
                SDL_RenderPresent(renderer);
        }
        }
        for (int i=100; i<1000; i= i+200){
            for (int j=100; j<1000; j=j+200){
                r.x=i;
                r.y=j;
                SDL_SetRenderTarget(renderer, texture);
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 250);
                SDL_RenderDrawRect(renderer,&r);
                SDL_SetRenderDrawColor(renderer, 250, 250, 250, 250);
                SDL_RenderFillRect(renderer, &r);
                SDL_SetRenderTarget(renderer, NULL);
                SDL_RenderCopy(renderer, texture, NULL, NULL);
                SDL_RenderPresent(renderer);
        }
        }
        }
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
        return 0;
}
