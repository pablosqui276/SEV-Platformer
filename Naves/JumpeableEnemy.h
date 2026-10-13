#include "Enemy.h"

class JumpeableEnemy : public Enemy
{
public:
	JumpeableEnemy(float x, float y, Game* game);
	int timeSinceLastShot = 0;
	int shootingInterval = 100;
};
