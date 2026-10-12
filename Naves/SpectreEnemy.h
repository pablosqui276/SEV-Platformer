#pragma once

#include "Enemy.h"

class SpectreEnemy : public Enemy
{
public:
	SpectreEnemy(float x, float y, Game* game);
	void calculateMovement(GameLayer* gameLayer) override;

	int timeSinceLastShot = 0;
	int shootingInterval = 100;
};
