#pragma once
#include <string>

class GameBoard
{
public:
    void display_board(int player = 1, int input = -1) const;

private:
    const std::string row_separator {"-----------"};
    constexpr static char colum_separator {'|'};
    constexpr static int board_width {3};
    constexpr static char player_1_symbol{'X'};
    constexpr static char player_2_symbol{'O'};
};
