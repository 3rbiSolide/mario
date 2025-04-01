#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

#include "file.h"
#include "game.h"

//ligne de compilation gcc main.c file.c game.c event.c charactere.c -o mario -lSDL2main -lSDL2_image -lSDL2


int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {														// si la cretion de la fenetre bug ca return
        printf("Erreur d'initialisation de SDL: %s\n", SDL_GetError());
        return 1;
    }


	SDL_Window *window = SDL_CreateWindow("Mario inschala pour bientot",  // crée la fenetre 
         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,                                 
			  640, 480,							 
              SDL_WINDOW_SHOWN);                            


	  if (!window) {
        printf("Erreur lors de la création de la fenêtre: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	
	SDL_Texture * menu = loadImage
	("img/menu.jpg",renderer);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, menu, NULL, NULL);//////// affiche le menu mario
    SDL_RenderPresent(renderer);

    int continuer = 1;
    SDL_Event event; 
    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_1){
                jouer(renderer);
            }
            if(event.key.keysym.sym == SDLK_2){
                SDL_Texture * credit = loadImage
	            ("img/credit.png",renderer);
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, credit, NULL, NULL);//////// affiche le menu mario
                SDL_RenderPresent(renderer);
            }
        }
    }
   
    SDL_DestroyWindow(window); 					// clean

SDL_DestroyTexture(menu);

	return 0;
} 

