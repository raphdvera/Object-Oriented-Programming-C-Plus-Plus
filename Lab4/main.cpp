#include <iostream>
#include <cstdio>
#include "RPG.h"

using namespace std;

int main()
{
    // Using overloaded constructor
    RPG p1 = RPG("Wiz", 0, 0.2, 60, 1);
    // Using default constructor 
    RPG p2 = RPG();

    // Displays player 1's current statistics
    printf("%s Current Stats\n", p1.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n",
        p1.getHitsTaken(), p1.getLuck(), p1.getExp(), p1.getLevel());
        
    // Displays player 2's current statistics
    printf("%s Current Stats\n", p2.getName().c_str());
    printf("Hits Taken: %i\t Luck: %f\t Exp: %f\t Level: %i\n",
        p2.getHitsTaken(), p2.getLuck(), p2.getExp(), p2.getLevel());

    // Make p2 take 3 hits
    p2.setHitsTaken(3);

    // Displays player 2's updated number of hits
    cout << "\nP2 hits taken " << p2.getHitsTaken() << endl;

    cout << "0 is dead, 1 is alive" << endl;
    
    // Check to see whether or not each player is still alive
    cout << "P1 " << p1.isAlive() << endl;
    cout << "P2 " << p2.isAlive() << endl;

    return 0;
}