#include "Sprite.hh"


int Sprite::operator()(const char& dir) const{
			switch(dir){
				case 'N':
						return _pos.y;
						break;
				case 'S':
						return _pos.y + _hauteurPerso;
						break;
				case 'E':
						return _pos.x + _largeurPerso;
						break;
				case 'O':
						return _pos.x;
						break;
				default:
					return -1;
			}
}
		

void Sprite::efface(SDL_Surface* screen, SDL_Surface* image_fond)
{
	SDL_Rect R;
	R.x = _pos.x;
	R.y = _pos.y;
	R.w = R.h = 0;
	// Definition du clipper a l'ancienne position du joueur
	SDL_Rect clipper;
	clipper.x = _oldPos.x;
	clipper.y = _oldPos.y;
	clipper.h = _hauteurPerso;
	clipper.w = _largeurPerso;
	
	// Efface l'ancienne position du joueur
	SDL_BlitSurface(image_fond, &clipper, screen, &_oldPos);
	_oldPos.x = _pos.x;
	_oldPos.y = _pos.y;
}

void Sprite::affiche(SDL_Surface* screen)
{
	int indexFrame;
	SDL_Rect R;
	R.x = _pos.x;
	R.y = _pos.y;
	R.w = R.h = 0;
	
	// Affiche le perso
	indexFrame = _dir * _nbImg + (++_frame) % (_nbImg * _vit) / _vit;
	SDL_BlitSurface(_img, &_clips[indexFrame], screen, &R);
}

bool Sprite::collision(const Sprite& autre) const
{
   if((autre('O') >= _pos.x + _largeurPerso)      		// trop à droite
	|| (autre('E') <= _pos.x) 	// trop à gauche
	|| (autre('N') >= _pos.y + _hauteurPerso) 			// trop en bas
	|| (autre('S') <= _pos.y))  	// trop en haut
          return false; 
   else
          return true; 
}

