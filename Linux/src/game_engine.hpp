#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>

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
