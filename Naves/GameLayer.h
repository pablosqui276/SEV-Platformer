#pragma once

#include "Layer.h"
#include "Player.h"
#include "Background.h"
#include "Projectile.h"
#include "Text.h"
#include "Audio.h"
#include "Space.h" // importar
#include "Tile.h"
#include "Collectable.h"

#include <fstream> // Leer ficheros
#include <sstream> // Leer líneas / String
#include <list>

#include "Pad.h"

class Enemy;
class Platform;

// Herencia en c++
class GameLayer : public Layer
{
public:
	GameLayer(Game* game);
	// Sobreescritura de un método en c++
	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;
	void keysToControls(SDL_Event event);
	void mouseToControls(SDL_Event event); // USO DE MOUSE
	void gamePadToControls(SDL_Event event); // USO DE GAMEPAD
	void loadMap(string name);
	void loadMapObject(char character, float x, float y);
	void calculateScroll();

	Actor* message;
	bool pause;
	float scrollX;
	int mapWidth;
	list<Tile*> tiles;
	Audio* audioBackground;
	Text* textPoints;
	Text* textCollectables;
	Space* space;
	int points;
	int newEnemyTime = 0;
	int nCollectables = 0;

	Player* player;
	Background* background;
	Actor* backgroundPoints;
	Actor* backgroundCollectables;
	bool controlContinue = false;
	bool controlShoot = false;

	int controlMoveY = 0;
	int controlMoveX = 0;

	list<Enemy*> enemies;
	list<Projectile*> projectiles;
	list<Collectable*> collectables;
	list<Platform*> platforms;

	// Elementos de interfaz
	SDL_GameController* gamePad;
	Pad* pad;
	Actor* buttonJump;
	Actor* buttonShoot;

	Tile* cup; // Elemento de final de nivel

};
