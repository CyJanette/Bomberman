#include<iostream>
#include<thread>
#include<fstream>
#include<string>
#include <SDL2/SDL.h>
#include "game.h"
using namespace std;
using namespace ftxui;

int main(int argc, char* argv[]) {
    Game game;
    if (!game.init()) {
        return -1;
    }
    game.run();
    game.clean();
    return 0;
}
