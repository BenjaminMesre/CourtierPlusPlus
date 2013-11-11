#include "Joueur.hh"

void Joueur::move(int xMin, int xMax, int yMin, int yMax, 
					const char& N, const char& S, 
					const char& E, const char& O){
	if(N && !S){
		if(E && !O){		//NE (x+, y-)
			if (_pos.x + _vit < xMax - _largeurPerso){
				_pos.x += 0.7071067812 * _vit;
				_dir = EST;
			}
			if (_pos.y + _vit > yMin){
				_pos.y -= 0.7071067812 * _vit;
				_dir = NORD;
			}
			
		}
		else if(O && !E){	//NO (x-, y-)
			if (_pos.x + _vit > xMin){
				_pos.x -= 0.7071067812 * _vit;
				_dir = OUEST;
			}
			if (_pos.y + _vit > yMin){
				_pos.y -= 0.7071067812 * _vit;
				_dir = NORD;
			}
		}
		else{	//N (x, y-)
			if(_pos.y + _vit > yMin){
				_pos.y -= _vit;
				_dir = NORD;
			}
				
		}
	} else if(S && !N){
		if(E && !O){		//SE (x+, y+)
			if (_pos.x + _vit < xMax - _largeurPerso)
			{
				_pos.x += 0.7071067812 * _vit;
				_dir = EST;
			}
			if (_pos.y + _vit < yMax - _hauteurPerso){
				_pos.y += 0.7071067812 * _vit;
				_dir = SUD;
			}
		}
		else if(O && !E){	//SO (x-, y+)
			if (_pos.x + _vit > xMin){
				_pos.x -= 0.7071067812 * _vit;
				_dir = OUEST;
			}
			if (_pos.y + _vit < yMax - _hauteurPerso){
				_pos.y += 0.7071067812 * _vit;
				_dir = SUD;
			}
		}
		else{	//S (x, y+)
			if(_pos.y + _vit < yMax - _hauteurPerso){
				_pos.y += _vit;
				_dir = SUD;
			}
		}
	} else if(E && !O){	//E (x+, y)
		if(_pos.x + _vit < xMax - _largeurPerso){
			_pos.x += _vit;
			_dir = EST;
		}
	} else if(O && !E){	//O (x-, y)
		if(_pos.x + _vit > xMin){
			_pos.x -= _vit;
			_dir = OUEST;
		}
	}				
}


void Joueur::pouvoir_superman(std::list<Ennemi*> ennemi) const
{
	for (std::list<Ennemi*>::iterator it = ennemi.begin() ; it != ennemi.end() ; it++){
		// Les ennemis sont pousés vers le haut
		if (((*it)->get_y() <= _pos.y) 
			&& ((*it)->get_y() >= _pos.y - 3 * get_hauteur() / 2) 
			&& ((*it)->get_x() > _pos.x) 
			&& ((*it)->get_x() < _pos.x + 250)){
			(*it)->set_y((*it)->get_y() - ((*it)->get_vit()));
		}
		// Les ennemis sont poussés vers le bas
		else if (((*it)->get_y() < (_pos.y + get_hauteur())) 
				&& ((*it)->get_y() > _pos.y) 
				&& ((*it)->get_x() > _pos.x) 
				&& ((*it)->get_x() < _pos.x + 250)){
			(*it)->set_y((*it)->get_y() + ((*it)->get_vit()));
		} 
	}
}


void Joueur::decoupeSprite()
{
	//On coupe la feuille de sprite
	for(int k = 0; k < 4; ++k){
		for(int i = 0; i < _nbImg; ++i) {
			SDL_Rect R;
			
			R.x = _largeurPerso * i;
			R.y = _hauteurPerso * k;
			R.w = _largeurPerso;
			R.h = _hauteurPerso;
			_clips.push_back(R);
		}
	}
}
