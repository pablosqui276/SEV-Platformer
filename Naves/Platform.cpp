#include "Platform.h"
#include "GameLayer.h"

Platform::Platform(float x, float y, Game* game)
	: Actor("res/bloque_tierra.png", x, y, 40, 32, game) {

	animation = NULL;
	initAction = false;
}

void Platform::update() {
	if (animation != NULL && initAction) {
		bool end = animation->update();
		if (end) {
			initAction = false;            
			animation->currentFrame = 0;
		}
	}
}

void Platform::changeActionAnimation(string animationPath, float fileWidth, float fileHeight, int updateFrecuency, int totalFrames, bool loop) {
	aAction = new Animation(animationPath, Actor::width, Actor::height,
		fileWidth, fileHeight, updateFrecuency, totalFrames, loop, Actor::game);
}

void Platform::draw(float scrollX) {
	if (animation != NULL && initAction) {
		animation->draw(x - scrollX, y);
	}
	else {
		Actor::draw(scrollX);
	}
}

void Platform::action(GameLayer* gameLayer) {

}


