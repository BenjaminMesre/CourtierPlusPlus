#ifndef Sprite_HH
	#define Sprite_HH
	#include <SDL/SDL.h>
	#include <vector>
	/**
	 * @brief Definit les caractéristiques basiques des différents personnage du jeu 
	 *
	 * @param _img SDL_Surface* L'image du personnage
	 * @param _pos SDL_Rect La position actuel de l'image
	 * @param _oldPos SDL_Rect L'ancienne position de l'image
	 * @param _clips std::vector<SDL_Rect> Tableau comportant les portions d'image des personnages
	 * @param _frame int La partie de l'image à afficher 
	 * @param _dir int La direction du déplacement du personnage
	 * @param _vit int La vitesse de déplacement du personnage
	 * @param _largeurPerso int La largeur de l'image du personnage
	 * @param _hauteurPerso int La hauteur de l'image du personnage
	 * @param _nbImg int Le nombre d'image contenu dans la feuille de sprite
	 * 
	**/
	class Sprite
	{
	public:
		/**
		 * @brief Constructeur par défaut d'un sprite (feuille d'images d'un personnage)
		 *
		 * @param x Coordonnée horizontale où apparaitra le sprite
		 * @param y Coordonnée verticale où apparaitra le sprite
		 **/
		Sprite(int x, int y){
				_pos.x = _oldPos.x = x;
				_pos.y = _oldPos.y = y;
				_frame = 0;
				_dir = 0;
		}
		
		
		/**
		 * @brief Destructeur du sprite
		 *
		 **/
		~Sprite(){SDL_FreeSurface(_img);}	
		
		
		/**
		 * @brief Surcharge de l'operateur () qui indique l'état de l'évènement dont la clé est passée en paramètre
		 *
		 * @param i Clé de l'évènement
		 * @return const char& Evènement activé si 1, 0 sinon
		 **/
		virtual int operator()(const char& dir) const;
		
		
		/**
		 * @brief Efface le personnage de l'ecran
		 *
		 * @param screen Ecran
		 * @param image_fond Image du terrain pour effacer
		 * @return void
		 **/
		void efface(SDL_Surface* screen, SDL_Surface* image_fond);
		
		
		/**
		 * @brief Affiche le personnage à l'écran
		 *
		 * @param screen Ecran
		 * @return void
		 **/
		void affiche(SDL_Surface* screen);

		
		/**
		 * @brief Indiques s'il y a collision entre le personnage courant et le personnage autre
		 *
		 * @param autre Personnage avec qui on considère la collision
		 * @return bool Collision entre le personnage courant et le personnage autre?
		 **/
		bool collision(const Sprite& autre) const;

		
	// Getters & Setters
		/**
		 * @brief Setter de la position de l'image
		 *
		 * @param x Nouvelle position horizontale
		 * @param y Nouvelle position verticale
		 * @return void
		 **/
		inline void set_pos(int x,int y){
			_pos.x = x;
			_pos.y = y;
		}
		
		
		/**
		 * @brief Getter de la position horizontale de l'image
		 *
		 * @return int La position horizontale de l'image
		 **/
		inline int get_x() const{return _pos.x;}
		
		
		/**
		 * @brief Setter de la position horizontale de l'image
		 *
		 * @param x Nouvelle position horizontale de l'image
		 * 
		 * @return void
		 **/
		inline void set_x(int x){ _pos.x = x;}
		
		
		/**
		 * @brief Getter de la position verticale de l'image
		 *
		 * @return int La position verticale de l'image
		 **/
		inline int get_y() const{return _pos.y;}
		
		
		/**
		 * @brief Setter de la position verticale de l'image
		 *
		 * @param y Nouvelle position verticale de l'image
		 * 
		 * @return void
		 **/
		inline void set_y(int y){ _pos.y = y;}
		
		
		/**
		 * @brief Getter de la vitesse de l'image
		 *
		 * @return int La vitesse de l'image
		 **/
		inline int get_vit() const{return _vit;}
		

		
		/**
		 * @brief Setter de la vitesse de l'image
		 *
		 * @param vit Nouvelle vitesse de l'image
		 * 
		 * @return void
		 **/
		inline void set_vit(int vit){ _vit = vit;}
		
		
		/**
		 * @brief Getter de la largeur de l'image
		 *
		 * @return int La largeur de l'image
		 **/
		inline int get_largeur() const{return _largeurPerso;}
		
		
		/**
		 * @brief Getter de la hauteur de l'image
		 *
		 * @return int La hauteur de l'image
		 **/
		inline int get_hauteur() const{return _hauteurPerso;}
		
		
		/**
		 * @brief Getter du rayon de l'image
		 *
		 * @return int Le rayon de l'image
		 **/
		inline int get_rayon() const{return _largeurPerso / 2;}
		
		
	protected:
		SDL_Surface* _img;
		SDL_Rect _pos, _oldPos;
		std::vector<SDL_Rect> _clips;
		int _frame;
		int _dir;
		int _vit;
		int _largeurPerso;
		int _hauteurPerso;
		int _nbImg;
		
		/**
		 * @brief Eleve le paramètre au carré
		 *
		 * @param x Valeur d'entrée
		 * @return int La valeur d'entrée au carré
		 **/
		inline int carre(int x) const{return x * x;}
		
		
		/**
		 * @brief Découpes la feuille de sprite du personnage
		 *
		 * @return void
		 **/
		virtual void decoupeSprite() = 0;
	
	};
#endif
