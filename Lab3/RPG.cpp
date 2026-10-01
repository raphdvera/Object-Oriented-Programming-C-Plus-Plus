#include "RPG.h"

// Default constructor
RPG::RPG()
{
    name = "NPC";
    hits_taken = 0;
    luck = 0.1;
    exp = 50.0;
    level = 1; 
}

// Overloaded constructor
RPG::RPG(string name, int hits_taken, float luck, float exp, int level)
{
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}

// Destructor
RPG::~RPG()
{
}

// Sets hits_taken
void RPG::setHitsTaken(int new_hits)
{
    hits_taken = new_hits;
}

// Returns true if player has fewer than 3 hits
bool RPG::isAlive() const
{
    return hits_taken < MAX_HITS_TAKEN;
}

// Accessor functions
string RPG::getName() const
{
    return name;
}

int RPG::getHitsTaken() const
{
    return hits_taken;
}

float RPG::getLuck() const
{
    return luck;
}

float RPG::getExp() const
{
    return exp;
}

int RPG::getLevel() const
{
    return level;
}

