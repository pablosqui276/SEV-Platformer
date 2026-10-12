#include "SpectreEnemy.h"
#include "Projectile.h"
#include "GameLayer.h"
#include "Game.h"

SpectreEnemy::SpectreEnemy(float x, float y, Game* game)
	: Enemy(x, y, game) {
	Enemy::changeMovingAnimation("res/new_enemigo_movimiento.png", 160, 32, 6, 5, true);
	Enemy::changeDyingAnimation("res/new_enemigo_muerte.png", 256, 32, 6, 8, false);
}

void SpectreEnemy::calculateMovement(GameLayer* gameLayer) {
    // Patrulla de izquierda a derecha
    Enemy::calculateMovement(gameLayer);

    // Lógica de disparo
    timeSinceLastShot++;
    if (timeSinceLastShot >= shootingInterval) {
        timeSinceLastShot = 0; // Reiniciamos el contador

        // Creamos el proyectil disparado hacia la izquierda
        Projectile* newProjectile = new Projectile(x, y, -3, this, game);
        newProjectile->changeTexture("res/disparo_enemigo.png", 20, 20);
        gameLayer->space->addDynamicActor(newProjectile);
        gameLayer->projectiles.push_back(newProjectile);
    }
}