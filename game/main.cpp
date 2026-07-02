#include <raylib.h>
#include "GameManager.hpp"

#ifdef PLATFORM_WEB
#include "emscripten/emscripten.h"
static GameManager* gManager = nullptr;
static void WebFrame() { gManager->runOneFrame(); }
#endif

int main()
{
    GameManager* game = new GameManager;

#ifdef PLATFORM_WEB
    gManager = game;
    emscripten_set_main_loop(WebFrame, 0, 1);
#else
    game->drawMainLoop();
    delete game;
#endif
    return 0;
}