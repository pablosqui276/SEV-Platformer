#include "Projectile.h"

Projectile::Projectile(float x, float y, float velocityX, Actor* owner, Game* game) :
    Actor("res/disparo_jugador2.png", x, y, 20, 20, game) {
    vx = velocityX;
    vy = 0; // Si es un disparo recto, o ajusta la gravedad según necesites
    this->owner = owner;
}

void Projectile::update() {
	vy = vy - 1; // La gravedad suma 1 en cada actualización restamos para anularla 
}
