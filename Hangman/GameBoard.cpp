#include <iostream>
#include "GameBoard.h"
#include <iomanip>

void GameBoard::display_game_board(const std::string &player_word) const
{
    auto value = player_word.length() + 3;
    std::cout << std::setw(value + 3 + line1.length()) << line1;
    std::cout << std::setw(value + 3 + line2.length()) << line2;
    std::cout << std::setw(value + 3 + line3.length()) << line3;
    std::cout << std::setw(value + 3 + line4.length()) << line4;
    std::cout << std::setw(value + 3 + line5.length()) << line5;
    std::cout << "   " << player_word << "   " << line6;
}

void GameBoard::update_board(int fails)
{
    if(fails == 0)
    {
        line1 = " -----  \n";
        line2 = " |   |  \n";
        line3 = "     |  \n";
        line4 = "     |  \n";
        line5 = "     |  \n";
        line6 = "     |  \n";
    }
    if(fails >= 1)
    {
        line3[1] = 'O';
    }
    if(fails >= 2)
    {
        line4[0] = '/';
    }
    if(fails >= 3)
    {
        line4[1] = '|';
    }
    if(fails >= 4)
    {
        line4[2] = '\\';
    }
    if(fails >= 5)
    {
        line5[1] = '|';
    }
    if(fails >= 6)
    {
        line6[0] = '/';
    }
    if(fails >= 7)
    {
        line6[2] = '\\';
    }
    if(fails >= 8)
    {
        std::cout << "Number of fails not handled";
    }
}
