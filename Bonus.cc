#include "Bonus.hh"

void Bonus::decoupeSprite()
{
	//On coupe la feuille de sprite
		SDL_Rect R;
		
		R.x = 0;
		R.y = 0;
		R.w = _largeurPerso ;
		R.h = _hauteurPerso;
		_clips.push_back(R);
}
