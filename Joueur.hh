#ifndef Joueur_HH
	#define Joueur_HH
	#include <SDL/SDL.h>
	#include "Sprite.hh"
	#include "Ennemi.hh"
	/**
	 * @brief Le joueur qui doit survivre à la crise
	 * 
	**/
	class Joueur : public Sprite
	{
	public:
		/**
		 * @brief Constructeur par défaut du joueur
		 *
		 * @param x Coordonnée horizontale où apparaitra le joueur
		 * @param y Coordonnée verticale où apparaitra le joueur
		 **/
		Joueur(int x, int y) : Sprite(x, y){
				_img = SDL_LoadBMP("images/joueur.bmp");
				SDL_SetColorKey(_img, SDL_SRCCOLORKEY, SDL_MapRGB(_img->format, 0, 255, 0));
				_nbImg = 4;
				_pos.x = _oldPos.x = x/3;
				_pos.y = _oldPos.y = y/2;
				_largeurPerso = _img->w / _nbImg;
				_hauteurPerso = _img->h / _nbImg;
				decoupeSprite();
				_vit = VIT_NORM;
		}
		
		
		/**
		 * @brief Déplace le joueur
		 *
		 * @param xMin Limite de déplacement vers l'ouest
		 * @param xMax Limite de déplacement vers l'est
		 * @param yMin Limite de déplacement vers le nord
		 * @param yMax Limite de déplacement vers le sud
		 * @param N Deplacement vers le Nord si à 1
		 * @param S Deplacement vers le Sud si à 1
		 * @param E Deplacement vers l'Est si à 1
		 * @param O Deplacement vers l'Ouest si à 1
		 * @return void
		 **/
		void move(int xMin, int xMax, int yMin, int yMax, 
					const char& N, const char& S, 
					const char& E, const char& O);
					
		/**
		 * @brief Fonction vérifiant si le joueur a perdu ou non
		 *
		 * @param xMin Bord Gauche du terrain que le joueur ne doit pas dépasser
		 * 
		 * @return bool Booleen indiquant si le joueur a perdu ou non
		**/
		inline bool checkGameover(int xMin){
			return (_pos.x + _largeurPerso < xMin);
		}
		
		/**
		 * @brief Pouvoir écartant tous les ennemis du joueur pendant 3 secondes
		 *
		 * @param ennemi Liste de tous les ennemis
		 * @return void
		 **/
		void pouvoir_superman(std::list<Ennemi*> ennemi) const;
	
				
	protected:
		static const int VIT_NORM = 10;
		static const int SUD = 0;
		static const int OUEST = 1;
		static const int EST = 2;
		static const int NORD = 3;
		void decoupeSprite();
	};
	
#endif
