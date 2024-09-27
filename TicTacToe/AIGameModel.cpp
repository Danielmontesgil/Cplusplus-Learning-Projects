#include "AIGameModel.h"

bool AIGameModel::process_input(char player_input, int player)
{
    if(player == 1)
    {
        return GameModelBase::process_input(player_input, player);
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

int AIGameModel::minimax(int depth, bool is_max)
{
    bool winner = check_winner();

    if(winner && is_max)
    {
        return -10 + depth;
    }

    if(winner && !is_max)
    {
        return 10 - depth;
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
