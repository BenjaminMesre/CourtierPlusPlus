#ifndef Context_HH
	#define Context_HH
	#include <SDL/SDL.h>
	#include <list>
	#include <string>
	#include "Input.hh"
	#include "Joueur.hh"
	#include "Terrain.hh"
	#include "Sprite.hh"
	#include "Bonus.hh"
	#include "Ennemi.hh"
	#include "Superman.hh"
	#include "Billet.hh"
	
	/**
	 * @brief Contexte du jeu qui en contient tout les éléments pour le faire avancer
	 *
	 * 	@param _ecran SDL_Surface* La surface de l'ecran.
	 *	@param _w int Largeur de la fenêtre
	 *	@param _h int Hauteur de la fenêtre
	 *	@param _terrain Terrain Le terrain
	 *	@param _joueur Joueur Le joueur
 	 *	@param _list_ordi std::list<Ennemi*> Les ennemis
 	 *	@param _superman Superman Le bonus superman
	 *	@param _billet Billet Le bonus billet
	 *	@param _gameOver bool Indique si la partie est terminée ou non 
	 * 
	**/
	class Context
	{
	public:
		/**
		* @brief Constructeur du contexte
		*
		* @param w Largeur de l'écran
		* @param h Hauteur de l'écran
		**/
		Context(int w, int h);
		
		
		/**
		* @brief Destructeur du contexte
		*
		**/
		~Context();
		
		
		/**
		* @brief Fais évoluer d'une frame à une autre en gérant les évènement
		*
		* @param  in Input contenant les infos sur quels events sont actifs
		* @return void
		**/
		void Evolue(const Input& in);
		
		
		/**
		* @brief Affiche les différents personnages sur l'écran
		*
		* @return void
		**/
		void Render();
		
		
		/**
		 * @brief Règle la synchro si la carte graphique n'est pas prête à blitter
		 *
		 * @return void
		 **/
		void Flip();
		
		
	protected:
		SDL_Surface* _ecran;    		// La surface de l'ecran.
		int _w,_h;   					// résolution de la fenêtre
		Terrain _terrain;				// Le terrain
		Joueur _joueur;   				// Le joueur
		std::list<Ennemi*> _list_ordi;	// Les ordinateurs
		Superman _superman;				// Le bonus superman
		Billet _billet; 				// Le bonus billet
		bool _gameOver;
		
	private:
		bool uneFois;
	};
#endif
