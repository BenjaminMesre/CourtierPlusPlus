#ifndef Terrain_HH
	#define Terrain_HH
	#include <SDL/SDL.h>
	/**
	 * @brief Les caractéristiques du terrain
	 *
	 * @param _img SDL_Surface* L'image du terrain
	 * @param _w int Largeur du terrain
	 * @param _h int Hauteur du terrain
	 * @param _xMin int Limite Ouest du terrain
	 * @param _xMax int Limite Est du terrain
	 * @param _yMin int Limite Nord du terrain
	 * @param _yMax int Limite Sud du terrain
	 * 
	**/
	class Terrain
	{
	public:
		/**
		* @brief Constructeur par défaut
		*
		* @param nomImg Nom du fichier image du terrain
		* @param xMax Largeur de l'image
		* @param yMax Hauteur de l'image
		**/
		Terrain(char* nomImg, int xMax, int yMax) : 
			      _img(SDL_LoadBMP(nomImg)), 
			      _xMin(168),_xMax(xMax), 
			      _yMin(0), _yMax(yMax){}
			
			
		/**
		* @brief Destructeur du terrain
		*
		**/	
		~Terrain(){SDL_FreeSurface(_img);}
		
		
		/**
		* @brief Getter de l'image du terrain
		*
		* @return SDL_Surface* L'image du terrain
		**/
		SDL_Surface* get_img() const{
			return _img;
		}
		
		
		/**
		 * @brief Getter de la limite ouest du terrain
		 *
		 * @return int
		 **/
		inline int get_xMin() const{return _xMin;}
		
		
		/**
		 * @brief Getter de la limite est du terrain
		 *
		 * @return int
		 **/
		inline int get_xMax() const{return _xMax;}
		
		
		/**
		 * @brief Getter de la limite nord du terrain
		 *
		 * @return int
		 **/
		inline int get_yMin() const{return _yMin;}
		
		
		/**
		 * @brief Getter de la limite sud du terrain
		 *
		 * @return int
		 **/
		inline int get_yMax() const{return _yMax;}
		
		
	protected:
		SDL_Surface* _img;
		int _w, _h, _xMin, _xMax, _yMin, _yMax;

	};
#endif
