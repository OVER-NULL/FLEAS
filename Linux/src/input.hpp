#include <iostream>
#include <string>
#include <fstream>

// Version: 0.2b.5a
// Producer: Qubit Games 
// Date Started:  06 | 27 | 19
// Date Finished: 10 | 04 | 19
// Programmers: Nico M

class file_info
{
    public:
        
        void write_file(std::string file_username)
        {
            std::ofstream file_u;
            std::string username;
            
            std::cout << ("\nHi and welcome to the username selector for FLEAS\n");
            std::cout << ("\nPlease enter a username: ");
            
            std::getline(std::cin, username);
            
            file_u.open(file_username);
            file_u << username;
            file_u.close();
        }
        
        void instructions(std::string instructions_pdf)
        {
            std::string readline;
            std::string instruk;
            std::ifstream read_instruc;
            
            read_instruc.open("instruk");
            
            std::cout << ("\nType instruc for instructions: ");
            std::cin >> instruk;
            std::cout << '\n';
            
            if (instruk == "instruc")
            {
                
                if (read_instruc.is_open())
                {
                    
                    while (std::getline(read_instruc, readline))
                    {
                        std::cout << readline << '\n';
                    }
                    
                    read_instruc.close();
                }
                
                std::cin.get();
            }
            
            else
            {
                std::cout << ("Proceeding to game startup :)");
                std::cout << ("\033[2J\033[1;1H");
            }
        }
};

int starts(void)
{
    std::string in;
    
    file_info fi;
    
    std::cout << ("Welcome to Fleas!\n");
    std::cout << ("\nWould you like to enter a username or proceed to instructions\n");
    std::cout << ("\n(i) for instructions (u) for username: ");
    std::cin >> in;
    std::cin.get();
    
    if (in == "i")
    {
         fi.instructions("instruk");
         std::cout << ("\nPress enter to continue to USERNAME: ");
         std::cin.get();
         
         std::cout << ("\033[2J\033[1;1H");
         
         fi.write_file("username");
    }
        
    else if (in == "u")
    {
        fi.write_file("username");
    }
        
    else
    {
        std::cout << ("Sorry no input matches");
        std::cout << ("\nPlease try again");
        std::cout << ("\033[2J\033[1;1H");
        
        starts(); 
    }
    
    std::cout << ("\nPress enter to continue");
    
    std::cin.get();
    
    std::cout << ("\033[2J\033[1;1H");
    
    return (0);
}
