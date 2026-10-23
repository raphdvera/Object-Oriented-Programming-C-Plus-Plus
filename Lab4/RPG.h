// RPG.h
#ifndef RPG_H
#define RPG_H

#include <string>
using namespace std;

const int INVENTORY_SIZE = 10;
const float HIT_FACTOR = 0.05;
const int MAX_HITS_TAKEN = 3;

class RPG
{
    public:
        // Constructors
        RPG();
        RPG(string name, int hits_taken, float luck, float exp, int level);

         // Destructor
        ~RPG();

        // Checks if RPG is alive
        bool isAlive() const;
        void setHitsTaken(int new_hits);

        // Accessors
        string getName() const;
        int getHitsTaken() const;
        float getLuck() const;
        float getExp() const;
        int getLevel() const;
    
        // PART TWO

        void setName(string name);
        void updateExpLevel();
        void attack(RPG *opponent);
        void printStats();
        
    private:
        string name;
        int hits_taken;
        float luck;
        float exp;
        int level;
};

#endif
