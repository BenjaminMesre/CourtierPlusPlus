#include "Context.hh"
#include <list>
#include <iostream>

Context::Context(int w, int h) : _w(w), _h(h), 
									_terrain((char *) "images/fond.bmp", w, h),
									_joueur(w / 2, h / 3), 
									_superman(w, h * rand()),
									_billet(w, h * rand())
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "Erreur d'initialisation de la SDL : "
					<< SDL_GetError() << std::endl; 
		exit(EXIT_FAILURE);
	}
	
	_ecran = SDL_SetVideoMode(w, h, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	if (_ecran == NULL){
		std::cout << "Impossible de charger le mode vidéo : "
					<< SDL_GetError() << std::endl; 
		exit(EXIT_FAILURE);
	}
	
	//affcihe le menu
	SDL_Surface * img_menu = SDL_LoadBMP((char *)"images/menu.bmp");
	SDL_Rect position_fond_menu;
	SDL_Event event;
	position_fond_menu.x = 0;
	position_fond_menu.y = 0;
	SDL_BlitSurface(img_menu, NULL, _ecran, &position_fond_menu);
	while (SDL_PollEvent(&event) && event.type != SDLK_n){}
	SDL_FreeSurface(img_menu);
	
	// Dessines le terrain
	SDL_Rect position_fond;
	position_fond.x = 0;
	position_fond.y = 0;
	SDL_BlitSurface(_terrain.get_img(), NULL, _ecran, &position_fond);
	
	//Creation des ennemis
	for (int i = 0 ; i < 40 ; i++){
		Ennemi  *ordi = new Ennemi(
					_terrain.get_xMax() + rand() % _terrain.get_xMax(), 
					_terrain.get_yMax() + rand() % _terrain.get_yMax());
		_list_ordi.push_front(ordi);
	}
	_gameOver = false;
	uneFois = false;
}



void Context::Evolue(const Input& in)
{
	// Si il y a GameOver
	if (_gameOver){
		if (in(SDLK_SPACE)){
			//repositionnement du joueur
			_joueur.set_pos(_w / 2, _h / 3);
			//repositionnement des ennemis
			for (std::list<Ennemi*>::iterator it = _list_ordi.begin() ; it != _list_ordi.end() ; it++){
				(*it)->set_pos(_terrain.get_xMax() + rand() % _terrain.get_xMax(), 
								_terrain.get_yMax() + rand() % _terrain.get_yMax());
			}
			//on enlève l'affichage du gameover
			SDL_Rect position_fond;
			position_fond.x = 0;
			position_fond.y = 0;
			SDL_BlitSurface(_terrain.get_img(), NULL, _ecran, &position_fond);
			uneFois = false;
		}
	}
	// Deplacement du joueur
	else
	{ 
		if (in(SDLK_UP) || in(SDLK_DOWN) || in(SDLK_RIGHT) || in(SDLK_LEFT)){
		_joueur.move(_terrain.get_xMin(), _terrain.get_xMax(), 
					_terrain.get_yMin(), _terrain.get_yMax(),
					in(SDLK_UP), in(SDLK_DOWN), 
					in(SDLK_RIGHT), in(SDLK_LEFT));
		}
					
		//Deplacement des bonus
		_superman.move(_joueur, _list_ordi);
		_billet.move(_joueur, _list_ordi);
		
		//Deplacement des ennemis
		for (std::list<Ennemi*>::iterator it = _list_ordi.begin() ; it != _list_ordi.end() ; it++){
			(*it)->move(_joueur, _list_ordi);
		}
	}
	// Mise a jour de GameOver selon la nouvelle position du joueur
	_gameOver = _joueur.checkGameover(_terrain.get_xMin());
}



void Context::Render()
{
	if (_gameOver){
		if(!uneFois){
			// Affiche le GameOver
			SDL_Surface* img = SDL_LoadBMP("images/gameover.bmp");
			SDL_Rect posImg;
			posImg.x = 0;
			posImg.y = 0;
			SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 255, 0));
			SDL_BlitSurface(img, NULL, _ecran, &posImg);
			uneFois = true;
		}
	}
	else{
	 	//Le joueur relance la partie après un game over
		_joueur.efface(_ecran, _terrain.get_img());
		_superman.efface(_ecran, _terrain.get_img());
		_billet.efface(_ecran, _terrain.get_img());
		for (std::list<Ennemi*>::iterator it = _list_ordi.begin() ; it != _list_ordi.end() ; it++){
			(*it)->efface(_ecran, _terrain.get_img());
		}
		for (std::list<Ennemi*>::iterator it = _list_ordi.begin() ; it != _list_ordi.end() ; it++){
			(*it)->affiche(_ecran);
		}
		_superman.affiche(_ecran);
		_billet.affiche(_ecran);
		_joueur.affiche(_ecran);
	}
}



void Context::Flip()
{
	while(SDL_Flip(_ecran)!=0)  // si la carte graphique n'est pas prête à blitter...
		SDL_Delay(1);			   // on attend un peu avant de réessayer : on reste ainsi synchro avec le balayage vertical
}



Context::~Context()
{
	for (std::list<Ennemi*>::iterator it = _list_ordi.begin() ; it != _list_ordi.end() ; it++){
		delete (*it);
	}
	SDL_FreeSurface(_ecran);
	SDL_Quit();
}
