#ifndef Input_HH
	#define Input_HH
	#include <SDL/SDL.h>
	/**
	 * @brief Définit les caractéristiques basiques des bonus
	 *
	 *	@param _key char[] Tableau indiquant quels évènements sont actifs
	 *	@param _quit char Indique si l'on doit quitter le jeu ou non 
	 * 
	**/
	class Input
	{
	public:
		/**
		* @brief Constructeur par défaut
		*
		**/
		Input();
		
		
		/**
		* @brief Destructeur de l'input
		*
		**/
		~Input(){}
		
		
		/**
		 * @brief Surcharge de l'operateur () qui indique l'état de l'évènement dont la clé est passée en paramètre
		 *
		 * @param i Clé de l'évènement
		 * @return const char& Evènement activé si 1, 0 sinon
		 **/
		const char& operator()(int i) const{
				return Key(i);
		}
		
		
		/**
		 * @brief Mets à jour les valeurs du tableau d'évènements
		 *
		 * @return void
		 **/
		void Update();
		
		
		/**
		 * @brief Indique l'état de l'évènement dont la clé est passée en paramètre
		 *
		 * @param i Clé de l'évènement
		 * @return const char& Evènement activé si 1, 0 sinon
		 **/
		inline const char& Key(int i) const{return _key[i];}
		
		
		/**
		 * @brief Getter du signal de fermeture du programme
		 *
		 * @return int Si 1: fermeture de l'application demandée, 0 sinon
		 **/
		inline int Quit(){return _quit;}
		
	protected:
		char _key[SDLK_LAST];
		char _quit;
	
	};
#endif
