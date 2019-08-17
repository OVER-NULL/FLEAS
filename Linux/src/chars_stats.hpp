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
        
        int health = 100;
        
        virtual void attack(int attack_points)
        {
        }
        
        virtual void move()
        {
        }
        
        virtual void stats(int health)
        {
        }
}; 

class NPC : public character
{
    public:
        
        virtual void stats(int health) 
        {
        }
};
