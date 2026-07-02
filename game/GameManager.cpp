#include "GameManager.hpp"
#include "time.h"

GameManager::GameManager()
{
    srand(time(NULL));
    InitWindow(1920, 1080, "Chemistry Game");
    SetTargetFPS(60);
    InitAudioDevice();
    game = new Game();
}

GameManager::~GameManager()
{
#ifndef PLATFORM_WEB
    game->highscore.open("highscore.txt", std::ios::out);
    game->highscore << std::to_string(game->highestStreak);
    game->highscore.close();
#endif
    delete game;
    CloseWindow();
}

void GameManager::runOneFrame()
{
    BeginDrawing();
    game->loop();
    EndDrawing();
}

void GameManager::drawMainLoop()
{
    while (!WindowShouldClose())
    {
        runOneFrame();
    }
}