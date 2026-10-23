#include "RPG.h"
#include <cstdlib>
#include <random>

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

// Part Two of the Lab
void RPG::setName(string name)
{
    this->name = name;
}

void RPG::updateExpLevel()
{
    exp += 50;

    if (exp >=100)
    {
        level = level + 1;
        exp = 0;
        luck += 0.1;
    }
}

void RPG::attack(RPG *opponent)
{
    random_device rd;
    mt19937 gen(rd()); // seed with random
    uniform_real_distribution<double> dis(0.0, 1.0);

    float random_num = dis(gen);

    // Create a bool called hit
    // hit is true if random_num > HIT_factor * opponent's luck
    bool hit = false;

    if (random_num > HIT_FACTOR * (*opponent).getLuck())
    {
        hit = true;
    }

    // If hit is true, the opponent's hits_taken will increase by 1
    if (hit)
    {
        (*opponent).setHitsTaken((*opponent).getHitsTaken() + 1);
    }
}

void RPG::printStats()
{
    printf("Name: %s\t Hits Taken: %d\t Luck: %f\t Exp: %f\t Level: %d\t Status: %s\n",
        name.c_str(),
        hits_taken,
        luck,
        exp,
        level,
        isAlive() ? "Alive" : "Dead");
}