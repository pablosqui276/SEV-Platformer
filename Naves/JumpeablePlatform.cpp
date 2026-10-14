#include "JumpeablePlatform.h"
#include "GameLayer.h"

JumpeablePlatform::JumpeablePlatform(float x, float y, Game* game)
	: Platform(x, y, game) {

	Actor::changeTexture("res/plataforma_saltable.png", 40, 32);
	Platform::changeActionAnimation("res/plataforma_saltable_animacion.png", 320, 32, 3, 8, false);
}

void JumpeablePlatform::action(GameLayer* gameLayer) {
	if (aAction != NULL) {
		initAction = true;
		animation = aAction;
		gameLayer->player->vy = -22;
		animation->currentFrame = 0;
	}
}

