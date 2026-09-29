#pragma once

#include "Layer.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Text.h"
#include "Audio.h"
#include "Space.h" // importar
#include "Tile.h"

#include <fstream> // Leer ficheros
#include <sstream> // Leer líneas / String
#include <list>

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
	void loadMap(string name);
	void loadMapObject(char character, float x, float y);
	void calculateScroll();
	float scrollX;
	int mapWidth;
	list<Tile*> tiles;
	Audio* audioBackground;
	Text* textPoints;
	Space* space;
	int points;
	int newEnemyTime = 0;

	Player* player;
	Background* background;
	Actor* backgroundPoints;
	bool controlShoot = false;

	int controlMoveY = 0;
	int controlMoveX = 0;

	list<Enemy*> enemies;
	list<Projectile*> projectiles;

};
