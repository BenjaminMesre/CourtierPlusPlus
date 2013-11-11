#include "Billet.hh"

void Billet::move(const Joueur& joueur, std::list<Ennemi*> ennemi){
	if (_visible == true){
		
		_pos.x -= _vit;
		
		//Si un bonus s'arrête
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
		if ((_pouvoirBillet == false) && (collision(joueur))){
			//Le "pouvoir" du bonus
			_activationPosx = _pos.x;
			_activationPosy = _pos.y;
			pouvoir_billet(ennemi);
			//Puis on le réinitialise à sa place 
			_debut_bonus = SDL_GetTicks();
			_pouvoirBillet = true;
			_pos.x = 1024;
			_pos.y = rand() % 768;
			_vit = 8 + rand() % 5;
			_visible = false;
		}
	}
	else {
		test_visible();
	}
	// Le pouvoir est actif pendant 3 sec
	if (_pouvoirBillet == true){
		if (SDL_GetTicks() - _debut_bonus > 3000){
			_pouvoirBillet = false;
		}
		else{
			pouvoir_billet(ennemi);
		}
	}
}

void Billet::pouvoir_billet(std::list<Ennemi*> ennemi)
{
	for (std::list<Ennemi*>::iterator it = ennemi.begin() ; it != ennemi.end() ; it++){
		// Les ennemis du haut se rapprochent du billet
		if (((*it)->get_y() < get_activationPosy()) 
		&& ((*it)->get_x() > get_activationPosx())
		&& ((*it)->get_x() < get_activationPosx() + 250)){
			(*it)->set_y((*it)->get_y() + 5);
		}
		// Les ennmis du bas se rapprochent du billet
		else if (((*it)->get_y() > get_activationPosy()) 
		&& ((*it)->get_x() > get_activationPosx())
		&& ((*it)->get_x() < get_activationPosx() + 250)){
			(*it)->set_y((*it)->get_y() - 5);
		} 
	}
}

void Billet::test_visible()
{
	int test1 = rand() % 1000;
	int test2 = rand() % 1000;
	if ((test1 == test2) && _pouvoirBillet == false){
		_visible = true;
	}
}
