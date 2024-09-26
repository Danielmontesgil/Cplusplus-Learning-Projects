#include <cctype>
#include "AIGameModel.h"

bool AIGameModel::process_input(char player_input, int player)
{
    if(player == 1)
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

    int best_val {-1000};
    int best_move {0};

    for(size_t i{0}; i < player_moves.size(); i++)
    {
        if(player_moves[i] == -1)
        {
            player_moves[i] = 2;

            int moveVal = minimax(0, false);

            player_moves[i] = -1;

            if(moveVal > best_val)
            {
                best_move = i;
                best_val = moveVal;
            }
        }
    }
    
    player_moves[best_move] = 2;

    return true;
}

bool AIGameModel::check_winner() const
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
        if (player_moves[combination[0]] == player_moves[combination[1]] &&
            player_moves[combination[0]] == player_moves[combination[2]] &&
            player_moves[combination[0]] != -1) {
            return true;
            }
    }

    return false;
}

bool AIGameModel::is_moves_left() const
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

int AIGameModel::minimax(int depth, bool is_max)
{
    bool winner = check_winner();

    if(winner && is_max)
    {
        return -10;
    }

    if(winner && !is_max)
    {
        return 10;
    }

    if(!is_moves_left())
    {
        return 0;
    }
    
    if(is_max)
    {
        int best {-1000};

        for(size_t i{0}; i < player_moves.size(); i++)
        {
            if(player_moves[i] == -1)
            {
                player_moves[i] = 2;

                best = std::max(best, minimax(depth+1, !is_max));

                player_moves[i] = -1;
            }
        }

        return best;
    }
    
    int best {1000};

    for (size_t i{0}; i < player_moves.size(); i++)
    {
        if(player_moves[i] == -1)
        {
            player_moves[i] = 1;

            best = std::min(best, minimax(depth+1, !is_max));

            player_moves[i] = -1;
        }
    }

    return best;
}
