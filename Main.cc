#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>

#include "Context.hh"


// -------------- MAIN

int main(int argc,char** argv)
{
	srand((unsigned int)time(NULL));
	Input in; 	  								// Instanciation d'une class Input, et initialisation : tous les champs à 0
	//Debut de la partie
	Context C(1024, 768);
	while(!in.Key(SDLK_ESCAPE) && !in.Quit())
	{
		unsigned int elapsed;
		unsigned int lasttime = SDL_GetTicks();
		in.Update();
		C.Evolue(in);
		C.Render();
		C.Flip();
		elapsed = SDL_GetTicks()-lasttime;  	// ici, je calcule le temps écoulé depuis la dernière frame
		if (elapsed<20)							// s'il ne s'est pas encore passé 20 millisecondes, j'attends.
			SDL_Delay(20-elapsed);			   	// ainsi, je synchronise mon application à 50 FPS (20*50 = 1000).
	}
	return 0;
}
