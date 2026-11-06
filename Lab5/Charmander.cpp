#include <iostream>
#include <stdio.h>
#include "Charmander.h"

// Constructor
Charmander::Charmander() : Pokemon(){
    type.push_back("Fire");
    skills.push_back("Growl");
    skills.push_back("Scratch");

    cout << "Default Constructor (Charmander)\n";
}

// Overloaded constructor
Charmander::Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s)
Pokemon(name, hp, att, def, t){
    type = t;
    skills = s;
    cout << "Overloaded Constructor (Charmander)\n";
}
