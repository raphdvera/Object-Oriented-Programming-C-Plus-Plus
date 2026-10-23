#include <iostream>
#include "RPG.h"
#include "Game.h"

using namespace std;

int main()
{
    // Creates game object
    Game my_game;

    // Number of RPG players
    int num_players = 10;

    // Generates all RPG players
    my_game.generatePlayers(num_players);

    // Battles until one player remains
    my_game.gameLoop();

    // Final stats printed
    my_game.printFinalResults();
    
    return 0;
}