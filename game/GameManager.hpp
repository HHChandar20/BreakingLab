#pragma once
#include "Game.hpp"
#include "raylib.h"

class GameManager
{
public:
    GameManager();
    ~GameManager();
    void drawMainLoop();
    void runOneFrame();
private:
    Game* game;
};