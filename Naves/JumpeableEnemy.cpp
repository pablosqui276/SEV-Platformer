#include "JumpeableEnemy.h"
#include "GameLayer.h"
#include "Game.h"

JumpeableEnemy::JumpeableEnemy(float x, float y, Game* game)
    : Enemy(x, y, game) {
    Enemy::changeMovingAnimation("res/new_enemigo_saltable_movimiento.png", 160, 32, 6, 5, true);
    Enemy::changeDyingAnimation("res/new_enemigo_saltable_muerte.png", 192, 32, 1, 6, false);
}