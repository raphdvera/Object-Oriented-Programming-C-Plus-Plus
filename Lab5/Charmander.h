#ifndef CHARMANDER_H
#define CHARMANDER_H

#include <string>
#include <vector>
#include "Pokemon.h"

using namespace std;

// Derived class
class Charmander : public Pokemon
{
public:
    // Constructors
    Charmander();
    Charmander(string name, int hp, int att, int def,
    vector<string> t, vector<string> s);

    // Mutator functions
    void speak() override;
    void printStats() override;
   
private:
        vector<string> skills;
};
#endif


