#include "DestructiblePlatform.h"
#include "GameLayer.h"

DestructiblePlatform::DestructiblePlatform(float x, float y, Game* game)
    : Platform(x, y, game) {
    timer = 0;
	limitTicks = 33;

	int numberOfFrames = 11;
	int duration = limitTicks / numberOfFrames;

	Actor::changeTexture("res/plataforma_destructible.png", 40, 32);
	Platform::changeActionAnimation("res/plataforma_destructible_animacion.png", 440, 32, duration, numberOfFrames, false);
}

void DestructiblePlatform::update() {
	Platform::update();

	if (timer == limitTicks) {
		forDestruct = true;
	}

	if (initAction == true) {
		timer++;
	}
}

void DestructiblePlatform::action(GameLayer* gameLayer) {
	if (!initAction && aAction != NULL) {
		initAction = true;
		animation = aAction;
		if (animation != NULL) {
			animation->currentFrame = 0;
		}
	}
}