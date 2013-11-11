#ifndef Ennemi_HH
	#define Ennemi_HH
	#include <SDL/SDL.h>
	#include <list>
	#include "Sprite.hh"
	/**
	 * @brief Les ennemis qui tentent de pousser le joueur à la crise
	 * 
	**/
	class Ennemi : public Sprite
	{
	public:
		/**
		 * @brief Constructeur par défaut d'un ennemi
		 *
		 * @param x Coordonnée horizontale où apparaitra l'ennemi
		 * @param y Coordonnée verticale où apparaitra l'ennemi
		 **/
		Ennemi(int x, int y) : Sprite(x, y){
				_img = SDL_LoadBMP("images/ennemi.bmp");
				SDL_SetColorKey(_img, SDL_SRCCOLORKEY, SDL_MapRGB(_img->format, 0, 255, 0));
				_vit = 1 + rand() % 8;
				_nbImg = 6;
				_largeurPerso = 40;
				_hauteurPerso = 80;
				decoupeSprite();
		}
		
		
	//Methodes
		/**
		 * @brief Déplace l'ennemi
		 *
		 * @param joueur Joueur
		 * @param ordi Liste des ordinateurs
		 * @return void
		 **/
		void move(Sprite& joueur, std::list<Ennemi*> autre);
		
		
	protected:
		void decoupeSprite();
	};
#endif
