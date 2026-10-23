#ifndef GAME_H
#define GAME_H

#include <vector>
#include <set>
#include "RPG.h"

using namespace std;

class Game
{
    public:
        // Constructor
        Game();

        void generatePlayers(int n); // RPG players created
        void endRound(RPG *winner, RPG *loser, int loserIndex); // winner/loser handling
        void battleRound(); // runs battle
        void gameLoop(); // battle remains running until one player left
        void printFinalResults(); // final stats

        // Destructor
        ~Game();

    private:
        // Pointers for every RPG player
        vector<RPG *> players;

        // Index of players alive
        set<int> live_players;
};

#endif