#pragma once
#include <string>
#include <vector>

class GameBoard
{
public:
    void display_board() const;
    void display_board(const std::vector<int> &game_status) const;
    void display_winner(int winner) const;

private:
    std::string row_separator {"-----------"};
    constexpr static char colum_separator {'|'};
    constexpr static int board_width {3};
    constexpr static char player_1_symbol{'X'};
    constexpr static char player_2_symbol{'O'};
};
