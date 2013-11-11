#ifndef Superman_HH
	#define Superman_HH
	#include <SDL/SDL.h>
	#include <list>
	#include <iostream>
	#include "Bonus.hh"
	#include "Joueur.hh"
	#include "Ennemi.hh"
	/**
	 * @brief Un Bonus qui éloigne les ennemis du joueur
	 *
	 * @param _pouvoirSuperman bool Indique si le pouvoir de Superman est actif ou non 
	 * 
	**/
	class Superman : public Bonus
	{
	public:
		/**
		 * @brief Constructeur par défaut
		 *
		 * @param x Coordonnée horizontale où apparaitra Superman
		 * @param y Coordonnée verticale où apparaitra Superman
		 **/
		Superman(int x, int y) : Bonus(x, y){
				_img = SDL_LoadBMP("images/hero.bmp");
				SDL_SetColorKey(_img, SDL_SRCCOLORKEY, SDL_MapRGB(_img->format, 0, 255, 0));
				_pouvoirSuperman = false;
				decoupeSprite();
		}
		
		
		/**
		 * @brief Déplaces Superman
		 *
		 * @param joueur Joueur
		 * @param ordi Liste des ordinateurs
		 * @return void
		 **/
		void move(const Joueur& joueur, std::list< Ennemi* > ennemi);
	
		
	protected :
		bool _pouvoirSuperman;
		void test_visible();
	};
#endif
