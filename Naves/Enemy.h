#pragma once

#include "Actor.h"
#include "Animation.h" 

class GameLayer;

class Enemy : public Actor
{
public:
	Enemy(float x, float y, Game* game);
	void draw(float scrollX = 0) override; // Va a sobrescribir
	void update(GameLayer* gameLayer);
	void impacted(); // Recibe impacto y pone animación de morir

	float vxIntelligence;
	int state;

	void changeDyingAnimation(string animationPath, float fileWidth, float fileHegiht, int updateFrecuency, int totalFrames, bool loop);
	void changeMovingAnimation(string animationPath, float fileWidth, float fileHegiht, int updateFrecuency, int totalFrames, bool loop);
	virtual void calculateMovement(GameLayer* gameLayer);


	Animation* aDying;
	Animation* aMoving;
	Animation* animation; // Referencia a la animación mostrada
};
