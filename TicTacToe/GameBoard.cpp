#include <iostream>
#include <sstream>
#include <iomanip>
#include "GameBoard.h"

void GameBoard::display_board() const
{
    display_board({});
}


void GameBoard::display_board(const std::vector<int> &game_status) const
{
    for (int i = 0; i < board_width; ++i)
    {
        const int row_num {board_width * i};
        for (int j = 0; j < board_width; ++j)
        {
            std::stringstream ss;
            if (!game_status.empty() && game_status[row_num + j] != -1) {
                ss << (game_status[row_num + j] == 1 ? player_1_symbol : player_2_symbol);
            } else {
                ss << row_num + j + 1;
            }
            std::cout << std::setw(2) << ss.str() << " " << (j < board_width-1 ? colum_separator : '\n');
        }
        std::cout << row_separator << '\n';
    }
}

void GameBoard::display_winner(const int winner) const
{
    std::cout << "Player " << winner << " won the match";
}
