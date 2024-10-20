#include <cctype>
#include "GameModelBase.h"

bool GameModelBase::process_input(char player_input, int player)
{
    if(isdigit(player_input))
    {
        const auto vector_index = player_input - '0' - 1;
        if(player_moves.at(vector_index) == -1)
        {
            player_moves[vector_index] = player;
            return true;
        }
    }

    return false;
}

bool GameModelBase::check_winner(std::vector<int> board_to_check) const
{
    const std::vector<std::vector<int>> winning_combinations = {
        {0, 1, 2}, 
        {3, 4, 5}, 
        {6, 7, 8}, 
        {0, 3, 6}, 
        {1, 4, 7}, 
        {2, 5, 8}, 
        {0, 4, 8}, 
        {2, 4, 6}  
    };

    for (const auto& combination : winning_combinations) {
        if (board_to_check[combination[0]] == board_to_check[combination[1]] &&
            board_to_check[combination[0]] == board_to_check[combination[2]] &&
            board_to_check[combination[0]] != -1) {
            return true;
            }
    }

    return false;
}

bool GameModelBase::is_moves_left() const
{
    for (int position : player_moves)
    {
        if(position == -1)
        {
            return true;
        }
    }
    return false;
}