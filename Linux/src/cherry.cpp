#include <ncurses.h>

#include "game_engine.hpp"
#include "input.hpp"
#include "chars_stats.hpp"
#include "enemy_characters.hpp"
#include "ally_characters.hpp"

// Top libs for cpp functions 
// Bottom libs for personal functions 

// Version: 0.2b.8a
// Producer: Qubit Games 
// Date Started:           06 | 27 | 19 
// Date Actual:            08 | 17 | 19 
// Date Finished Expected: 10 | 04 | 19
// Programmers: Nico M

// Make sure every file has one class 
 
int main(void)
{
    starts(); // username and instructions input function 
    
    // ncurses starts
    
    initscr();
    noecho();
    cbreak();
    timeout(0);
    curs_set(0);
    keypad(stdscr, true);
   
    Game_Engine game; // class 
    Image flea_image; // class 
    Image img; // class for username print
    Image paragraph; // class for introduction paragraph 
    
    WINDOW *window = newwin(LINES, COLS, 0, 0);

    flea_image.load("flea");
    img.load("username");
    paragraph.load("paragraph");
    
    while (true) // Start 
    {
        game.clear();
       
        game.draw_image(COLS / 2 - flea_image.getWidth() / 2, 16, flea_image);
        
        game.draw_string(COLS / 2 - flea_image.getWidth() / 2 - 1, 23, "A Plague Based Text Adventure");
        game.draw_string(COLS / 2 - flea_image.getWidth() / 2 + 4, 25, "Made by Qubit Games");
        game.draw_string(COLS / 2 - flea_image.getWidth() / 2 + 5.3, 35, "Version: 0.2b.5a");
        game.draw_string(COLS / 2 - flea_image.getWidth() / 2 + 2.8, 50, "Press enter to continue");
        
        if ('\n' == getch()) {break;}
        
        game.render(window, LINES, COLS);
       
        wrefresh(window);
    }
    
    game.clear();
    
    while (true) // Welcome 
    {
        game.clear();
        
        game.draw_string(COLS / 2 - flea_image.getWidth() / 2 + 8, 25, "Welcome ");
        game.draw_image(COLS / 2 - flea_image.getWidth() / 2 + 17.5, 25, img);
        
        if ('\n' == getch()) {break;}
        
        game.render(window, LINES, COLS);
        
        wrefresh(window);
    }
    
    while (true) // Intro 
    {
        game.clear();
        
        game.draw_image(COLS / 2 - flea_image.getWidth() / .65, 30 - 7, paragraph);
        
        if ('\n' == getch()) {break;}
        
        game.render(window, LINES, COLS);
        
        wrefresh(window);
    }
    
    endwin();
    
    // ncurses ends 
   
    return (0);
}
