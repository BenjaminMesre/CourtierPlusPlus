#include "Superman.hh"

void Superman::move(const Joueur& joueur, std::list<Ennemi*> ennemi){
	if (_visible == true){
		
		_pos.x -= _vit;
		
		//Si un ordi s'arrête
		if (_vit <= 0){
			_vit = 8 + rand() % 5;
			_visible = false;
		}
		
		//Lorsque le bonus arrive au bout de l'ecran
		if (_pos.x <= 0){
			_pos.x = 1024;
			_pos.y = rand() % 768;
			_vit = 8 + rand() % 5;
			_visible = false;
		}
		// Le moment de la collision avec le joueur
		if ((_pouvoirSuperman == false) && (collision(joueur))){
			//Le "pouvoir" du bonus
			joueur.pouvoir_superman(ennemi);
			//On le réinitialise à sa place 
			_debut_bonus = SDL_GetTicks();
			_pouvoirSuperman = true;
			_pos.x = 1024;
			_pos.y = rand() % 768;
			_vit = 8 + rand() % 5;
			_visible = false;
		}
		//Collision avec les ennemi
		for (std::list<Ennemi*>::iterator it = ennemi.begin() ; it != ennemi.end() ; it++){
			if (collision(*(*it))){
				_pos.x -= 1;
				set_vit((*it)->get_vit() + 1);
				if ((*it)->get_vit() > 2){
					(*it)->set_vit((*it)->get_vit() - 1);
				}
			}
		}
	}
	else {
		test_visible();
	}
	// Le pouvoir est actif pendant 3 sec
	if (_pouvoirSuperman == true){
		if (SDL_GetTicks() - _debut_bonus > 3000){
			_pouvoirSuperman = false;
		}
		else{
			joueur.pouvoir_superman(ennemi);
		}
	}
}

void Superman::test_visible()
{
	int test1 = rand() % 1000;
	int test2 = rand() % 1000;
	if ((test1 == test2) && _pouvoirSuperman == false){
		_visible = true;
	}
}
