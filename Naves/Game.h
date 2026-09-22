#pragma once

// Todas las librerias de SDL y otras utilidades
#include <iostream>
#include <string>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map> 

// Valores generales
// Constantes
#define WIDTH 480
#define HEIGHT 320

// Recordemos el problema de las referencias cruzadas. Entra en buble infinito.
// Cuando dos clases se referencian entre sí, el programa falla, pues va a buscar la clase cada vez que lee el #include de uno en el otro. 
// Por eso incluimos la clase Layer y Game en sus respectivos archivos de cabecera, haciendo que el compilador vea que existe sin que necesite buscarla.
#include "Layer.h"
class Layer;

class Game
{
public:
	Game();
	void loop();
	void scale();
	SDL_Texture* getTexture(string filename);
	map<string, SDL_Texture*> mapTextures; // map - cache
	TTF_Font* font;
	bool scaledToMax = false;
	float scaleLower = 1;
	SDL_Window* window; // ventana
	SDL_Renderer* renderer; // renderizador
	bool loopActive; // Juego activo
	Layer* gameLayer;
};

