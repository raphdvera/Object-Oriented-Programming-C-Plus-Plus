#include <iostream>
#include "Pokemon.h"
using namespace std;

// Constructor
Pokemon::Pokemon()
{
    // Values for Pokemon
    name = "unidentified";
    hp = 0;
    attack = 0;
    defense = 0;
    cout << "Default Constructor (Pokemon)\n";
}

// Constructing a Pokemon
Pokemon::Pokemon(string name, int hp, int att, int def,
vector<string> type)
{
    // Assign parameter values to Pokemon
    this->name = name;
    this->hp = hp;
    attack = att;
    defense = def;
    this->type = type;
    cout << "Overloaded Constructor (Pokemon)\n";
}

// Says whatever the Pokemon says
void Pokemon::speak()
{
    cout << "...\n";
}

void Pokemon::printStats(){
    printf("Name:%s\t HP: %i\t DEF: %i\t ATT: %i\n", name.c_str(), hp, defense, attack);
    cout << "Type: ";
    for(int i = 0; i < type.size(); i++){
        cout << type[i] << "\t";
    }
    cout << endl;
}