#pragma once
#include "Actor.h"
#include "Animation.h"

class Collectable : public Actor
{
public:
	Collectable(float x, float y, Game* game);
	void update();
	void draw(float scrollX);

	Animation* animation;

};

