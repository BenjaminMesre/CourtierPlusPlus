#ifndef Billet_HH
	#define Billet_HH
	#include <SDL/SDL.h>
	#include <list>
	#include "Bonus.hh"
	#include "Joueur.hh"
	#include "Ennemi.hh"
	/**
	 * @brief Un Bonus qui attire les ennemis lorsqu'il est touché par le joueur
	 *
	 * @param _activationPosx int Position horizontale ou le joueur a touché le billet
	 * @param _activationPosy int Position vertical ou le joueur a touché le billet
	 * @param _pouvoirBillet bool Indique si le pouvoir du billet est actif ou non 
	 * 
	**/
	class Billet : public Bonus
	{
	public:
		/**
		 * @brief Constructeur par défaut
		 *
		 * @param x Coordonnée horizontale où apparaitra le billet
		 * @param y Coordonnée verticale où apparaitra le billet
		 **/
		Billet(int x, int y) : Bonus(x, y){
				_img = SDL_LoadBMP("images/billet.bmp");
				SDL_SetColorKey(_img, SDL_SRCCOLORKEY, SDL_MapRGB(_img->format, 0, 255, 0));
				_pouvoirBillet = false;
				_activationPosx = 0;
				_activationPosy = 0;
				decoupeSprite();
		}
		
		
	//Methodes
		/**
		 * @brief Déplace le billet
		 *
		 * @param joueur Joueur
		 * @param ordi Liste des ordinateurs
		 * @return void
		 **/
		void move(const Joueur& joueur, std::list<Ennemi*> ordi);
		
		
		/**
		 * @brief Actives le pouvoir du billet
		 *
		 * @param ordi Liste des ordinateurs
		 * @return void
		 **/
		void pouvoir_billet(std::list<Ennemi*> ordi);
		
		
	//Getters
		/**
		 * @brief Getter de la position horizontale du billet
		 *
		 * @return int La position horizontale du billet
		 **/
		inline int get_activationPosx() const{return _activationPosx;}
		
		
		/**
		 * @brief Getter de la position verticale du billet
		 *
		 * @return int La position verticale du billet
		 **/
		inline int get_activationPosy() const{return _activationPosy;}
		
	
	protected :
		bool _pouvoirBillet;
		int _activationPosx;
		int _activationPosy;
		/**
		 * @brief Indique si le bonus billet est visible ou non
		 *
		 * @return void
		 **/
		void test_visible();
	};
#endif
