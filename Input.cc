#include "Input.hh"

Input::Input()
{
	memset(this,0,sizeof(*this));
}

void Input::Update()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			_key[event.key.keysym.sym]=1;
			break;
		case SDL_KEYUP:
			_key[event.key.keysym.sym]=0;
			break;
		case SDL_QUIT:
			_quit = 1;
			break;
		default:
			break;
		}
	}
}
