#include <string>
#include <iostream>
#include <ncurses.h>
#include <fstream>
#include <vector>
#include <thread> 
#include <chrono>
#include <cstring>
#include <algorithm>
#include "input.hpp"
#include "chars_stats.hpp"
#include "e_chars.hpp"
#include "a_chars.hpp"
 
// Version: 0.2b.0a
// Producer: Qubit Games 
// Date Started:  06 | 27 | 19
// Date Finished: 10 | 04 | 19
// Programmers: Nico M

// Game engine

class Image
{
    private:
        
        std::vector<std::string> data;
        int width;
        int height;
 
    public:
       
        void load(std::string path)
        {
            std::ifstream file;
            file.open(path);
           
            auto offset = 0;
           
            width  = 0;
            height = 0;
           
            while (!file.eof())
            {
                std::string line;
                std::getline(file, line);
               
                data.push_back(line);
                width = std::max(width, (int)line.size());
               
                offset += 1;
            }    
            file.close();
 
            height = data.size();
        }

        std::vector<std::string> getData()
        {
            return data;
        }
   
        int getWidth(void)
        {
            return width;
        }
 
        int getHeight(void)
        {
            return height;
        }
};
 
class Game_Engine // Its a piston engine ^_^
{
    public:
       
        bool do_render = false;
       
        Game_Engine(void)
        {
            clear();
        }
       
        void put_char(int x, int y, char c)
        {
            grid[y][x] = c;
        }        
       
        void draw_string(int x, int y, std::string string)
        {
            for (auto i = 0; i < string.length(); ++i)
            {
                put_char(x + i, y, string[i]);
            }
        }
       
        void draw_image(int x, int y, Image image)
        {
            for (auto i = 0; i < image.getHeight(); ++i)
            {
                draw_string(x, y + i, image.getData()[i]);
            }
        }
       
        void clear(void)
        {
            for (auto y = 0; y < 1000; ++y)
            {
                for (auto x = 0; x < 1000; ++x)
                {
                    grid[y][x] = ' ';
                }
            }
        }
 
        void render(WINDOW *window, int rows, int cols)
        {
            for (auto y = 0; y < rows; ++y)
            {
                for (auto x = 0; x < cols; ++x)
                {
                    if (last_grid[y][x] != grid[y][x])
                    {
                        mvwaddch(window, y, x, grid[y][x]);
                    }
                }
            }
           
            std::memcpy(last_grid, grid, 1000 * 1000 * sizeof(char));
        }
   
        char last_grid[1000][1000];
        char grid[1000][1000];
       
        int x, y, length;
};
 
// Game engine
 
int main(void)
{
    starts();
    
    initscr();
    noecho();
    cbreak();
    timeout(0);
    curs_set(0);
    keypad(stdscr, true);
   
    Game_Engine game; // class 
    Image flea_image; // class 
    Image img; // class for username print 
    
    WINDOW *window = newwin(LINES, COLS, 0, 0);

    flea_image.load("flea");
    img.load("username");
    
    while (true)
    {
        game.clear();
       
        //Center this one based on the image width
        game.draw_image(COLS / 2 - flea_image.getWidth() / 2, 16, flea_image);
        
        game.draw_string(COLS / 2 - flea_image.getWidth() / 2 - 1, 23, "A Plague Based Text Adventure");
        game.draw_string(COLS / 2 - flea_image.getWidth() / 2 - 1, 25, "Made by Qubit Games");
        game.draw_string(COLS / 2 - flea_image.getWidth() / 2 + 5, 35, "Version: 0.2b.0a");
        game.draw_string(COLS / 2 - flea_image.getWidth() / 2 + 2.8, 50, "Press enter to continue");
        
        if ('\n' == getch())
        {
            break;
        }
        
        game.render(window, LINES, COLS);
       
        wrefresh(window);
    }
    
    game.clear();
    
    while (true)
    {
        game.clear();
        
        game.draw_string(COLS / 2 - flea_image.getWidth() / 2 + 8, 25, "Welcome ");
        game.draw_image(COLS / 2 - flea_image.getWidth() / 2 + 17, 25, img);
        
        if ('\n' == getch())
        {
            break;
        }
        
        game.render(window, LINES, COLS);
        
        wrefresh(window);
    }
    
    endwin();
   
    return (0);
}
