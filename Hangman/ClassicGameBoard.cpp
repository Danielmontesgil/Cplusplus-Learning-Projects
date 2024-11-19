#include <iostream>
#include "ClassicGameBoard.h"
#include <iomanip>

void ClassicGameBoard::display_game_board(const std::string &player_word) const
{
    auto value = player_word.length() * 2 - 1 + line_spacing;
    std::cout << std::setw(value + line_spacing + line1.length()) << line1;
    std::cout << std::setw(value + line_spacing + line2.length()) << line2;
    std::cout << std::setw(value + line_spacing + line3.length()) << line3;
    std::cout << std::setw(value + line_spacing + line4.length()) << line4;
    std::cout << std::setw(value + line_spacing + line5.length()) << line5;
    std::cout << "   " << format_word_to_show(player_word) << "   " << line6;
}

std::string ClassicGameBoard::format_word_to_show(const std::string &player_word) const
{
    std::string formatted_word;
    for (size_t i = 0; i < player_word.size(); ++i) {
        formatted_word += player_word[i];
        if (i < player_word.size() - 1) {
            formatted_word += ' ';
        }
    }

    return formatted_word;
}

void ClassicGameBoard::update_board(int fails)
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
        line4[1] = '|';
    }
    if(fails >= 3)
    {
        line4[0] = '/';
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
}
