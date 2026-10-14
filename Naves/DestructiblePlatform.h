#pragma once
#include "Platform.h"

class DestructiblePlatform : public Platform {
public:
    DestructiblePlatform(float x, float y, Game* game);
    void update() override; 
    void action(GameLayer* gameLayer) override;

    int timer;
    int limitTicks;
};