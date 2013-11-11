#include "Ennemi.hh"

void Ennemi::move(Sprite& joueur, std::list<Ennemi*> autre){
	_pos.x -= _vit;
	
	//Si un ordi s'arrête
	if (_vit == 0){
		_vit = 1 + rand() % 8;
	}
	
	//Lorsque l'ordi arrive au bout de l'ecran
	if (_pos.x < 0){
		_pos.x = 1024 + rand() % 300;
		_pos.y = rand() % 768;
	}
	
	//On gère les collisions
	for (std::list<Ennemi*>::iterator it = autre.begin() ; it != autre.end() ; it++){
		// Collision entre ordi
		if (((collision(*(*it))) && ((*it) != this))){
			_pos.x -= 1;
			_vit = (*it)->_vit + 1;
			
			if ((*it)->_vit > 8){
				(*it)->_vit = 1 + rand() % 8;
			}
			else if ((*it)->_vit > 2){
				(*it)->_vit -= 1;
			}
			
			if (_vit > 8){
				_vit = 1 + rand() % 8;
			}
		}
		//collision ordi/joueur
		if (collision(joueur)) {
			// Collision à droite
			if( joueur('E') >= _pos.x
			&& joueur('E') <= _pos.x + _largeurPerso){
				joueur.set_x(joueur.get_x() - joueur.get_vit());
			}
			// Collision à gauche
			else if( joueur('O') >= _pos.x 
			&& joueur('O') <= _pos.x + _largeurPerso){
				joueur.set_x(joueur.get_x() + joueur.get_vit());
			}
			// Collision en haut
			else if( joueur('S') >= _pos.y 
			&& joueur('S') <= _pos.y + _hauteurPerso){
				joueur.set_y(joueur.get_y() - joueur.get_vit());
			}
			// Collision en bas
			else if( joueur('N') >= _pos.y 
			&& joueur('N') <= _pos.y + _hauteurPerso){
				joueur.set_y(joueur.get_y() + joueur.get_vit());
			}
		}
	}
	
}


void Ennemi::decoupeSprite()
{
	//On coupe la feuille de sprite
	for(int i = 0; i < _nbImg; ++i) {
		SDL_Rect R;
		
		R.x = _largeurPerso  * i;
		R.y = 0;
		R.w = _largeurPerso ;
		R.h = _hauteurPerso;
		_clips.push_back(R);
	}
}
