#pragma once

#include "Actor.h"

class Projectile : public Actor
{
public:
	Projectile(float x, float y, float velocityX, Actor* owner, Game* game);
	void update();

	Actor* owner;
};
