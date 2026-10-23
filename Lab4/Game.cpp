#include "Game.h"
#include <random>
#include <iterator>
#include <string>
#include <cstdio>

using namespace std;

// Constructor
Game::Game()
{
}

// Creation for RPG pointer and updates names
// with ordering. Additionally, live_players populated
// from 0 to n - 1 as players are alive initially

void Game::generatePlayers(int n)
{
    for (int i = 0; i < n; i++)
    {
        // RPG player with pointer
        players.push_back(new RPG());

        // Rename players as NPC_0 to NPC_#
        string new_name = "NPC_" + to_string(i);
        players[i]->setName(new_name);

        // Player index of living players
        live_players.insert(i);
    }
}

// Randomly selects player from alive players, live_players
// return int index for vector, players

int Game::selectPlayer()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, live_players.size() - 1);

    // Picks random position
    int randomIndex = dist(gen);

    // Advances iterator to said position
    set<int>::iterator it = live_players.begin();
    advance(it, randomIndex);

    // Player index stored
    int selectedIndex = *it;

    return selectedIndex;
}

// Brief ends curent battle round, resets hits,
// removes loser, upadtes winner's experience, prints result.
// Param winner pointer to winning RPG, loser pointer to losing RPG
// loserIndex Index of losing player

void Game::endRound(RPG *winner, RPG *loser, int loserIndex)
{
    // Resets winner's hits to 0
    (*winner).setHitsTaken(0);
    
    // Removes losing player
    live_players.erase(loserIndex);

    // Updates winner's experience and level
    (*winenr).updateExpLevel();

    // Prints results
    printf("%s won against %s\n"),
        (*winner).getName().c_str(),
        (*loser).getName().c_str();
}

// Selects two random living players and makes them
// battle until one loses.

void Game::battleRound()
{
    // Selects two living players
    int playerIndex1 = selectPlayer();
    int playerIndex2 = selectPlayer();

    // If same player selected twice, restarts round and chooses again
    if (playerIndex1 == playerIndex2)
    {
        battleRound();
        return;
    }

    // Pointers to two selected RPG players
    RPG *player1 = players[playerIndex1];
    RPG *player2 = players[playerIndex2];

    // Fights while both players are alive
    while (player1->isAlive() && player2->isAlive())
    {
        // Player 1 attacks player 2
        player1->attack(player2);

        // Vice-versa
        player2->attack(player1);
    }

    // Finds which player won
    if (player1->isAlive())
    {
        // Player 1 wins
        endRound(player1, player2, playerIndex2);
    }
    else
    {
        // Player 2 wins
        endRound(player2, player1, playerIndex1);
    }
}