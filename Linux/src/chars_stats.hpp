#include <iostream>

// Version: 0.2b.5a
// Producer: Qubit Games 
// Date Started:           06 | 27 | 19 
// Date Actual:            08 | 14 | 19 
// Date Finished Expected: 10 | 04 | 19
// Programmers: Nico M

// class for in-game chars 

class character
{
    public:
        
        void defend()
        {
            std::cout << "A knight 1" << '\n';
        }
};

class NPC : public character 
{
    public:
        
        void stats(int health) 
        {
        }
    
        virtual void defend()
        {
            std::cout << "A knight 2" << '\n';
        }
    
        void attack(int attack_points)
        {
        }
        
        void move()
        {
        }
};
