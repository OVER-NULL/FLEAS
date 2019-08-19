#include <iostream> 

// Version: 0.2b.5a
// Producer: Qubit Games 
// Date Started:           06 | 27 | 19 
// Date Actual:            08 | 14 | 19 
// Date Finished Expected: 10 | 04 | 19
// Programmers: Nico M

class priest : public NPC
{
    public:
        
        virtual void defend()
        {
        }
        
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

class plague_doctor : public NPC
{
    public:
        
        virtual void defend()
        {
        }
        
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

class protagonist : public NPC 
{
    public:
        
        virtual void defend()
        {
        }
        
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

class good_peasant : public NPC
{
    public:
        
        virtual void defend()
        {
        }
        
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

class knight : public NPC 
{
    public:
        
        void defend()
        {
            std::cout << "    o|       o|       o|" << '\n';
            std::cout << " <7O|=    <7O|=    <7O|=     <7__" << '\n';
            std::cout << " (<( }-.  (< (}-.  ( <(}-.   (_( }-." << '\n';
            std::cout << "  ||//     ||//     ||//      ||//" << '\n';
        }
        
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
