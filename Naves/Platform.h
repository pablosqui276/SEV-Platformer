#pragma once
#include "Tile.h"
#include "Animation.h"

class GameLayer;

class Platform : public Tile
{
public:
	Platform(float x, float y, Game* game);
	void draw(float scrollX = 0) override; // Va a sobrescribir
	virtual void update();
	virtual void action(GameLayer* gameLayer);

	void changeActionAnimation(string animationPath, float fileWidth, float fileHegiht, int updateFrecuency, int totalFrames, bool loop);

	Animation* animation; // Referencia a la animación mostrada
	Animation* aAction;
	bool initAction;
	bool forDestruct;
};

