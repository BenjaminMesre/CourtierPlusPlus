#ifndef Bonus_HH
	#define Bonus_HH
	#include <SDL/SDL.h>
	#include <list>
	#include "Sprite.hh"
	
	/**
	 * @brief Définit les caractéristiques basiques des bonus
	 *
	 *	@param _visible bool Indique si le bonus est visible ou non
	 *	@param _debut_bonus Uint32 Instant d'activation du bonus 
	 *	@param _temps_actuel Uint32 Instant courant
	 * 
	**/
	class Bonus : public Sprite
	{
	public:
		/**
		 * @brief Constructeur par défaut
		 *
		 * @param x Coordonnée horizontale où apparaitra le bonus
		 * @param y Coordonnée verticale où apparaitra le bonus
		 **/
		Bonus(int x, int y) : Sprite(x, y){
				_vit = 3 + rand() % 10;
				_nbImg = 1;
				_largeurPerso = 50;
				_hauteurPerso = 50;
				_debut_bonus = 0;
				_temps_actuel = 0;
				_visible = false;
		}
		
	
	protected :
		bool _visible;  
		Uint32 _debut_bonus;
		Uint32 _temps_actuel;
		/**
		 * @brief Détermines si le bonus est visible ou non
		 *
		 * @return void
		 **/
		virtual void test_visible() = 0;
		virtual void decoupeSprite();
	  
	};
#endif
