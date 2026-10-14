#pragma once
#include "Platform.h"

class JumpeablePlatform : public Platform
{
public:
	JumpeablePlatform(float x, float y, Game* game);
	void action(GameLayer*) override;
};

