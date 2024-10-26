#include "Minimax.h"
#include "GameModel.h"

int Minimax::find_move(const int depth, const bool is_max, const int player_playing)
{
    int best_val {-1000};
    int best_move {0};

    for(size_t i{0}; i < player_moves.size(); i++)
    {
        if(player_moves[i] == -1)
        {
            player_moves[i] = player_playing % 2 == 0 ? 2 : 1;

            int moveVal = minimax(depth, is_max);

            player_moves[i] = -1;

            if(moveVal > best_val)
            {
                best_move = static_cast<int>(i);
                best_val = moveVal;
            }
        }
    }

    return best_move;
}

int Minimax::minimax(int depth, bool is_max)
{
    bool winner = game_model->check_winner(player_moves);

    if(winner && is_max)
    {
        is_draw = false;
        return -10;
    }

    if(winner && !is_max)
    {
        is_draw = false;
        return 10;
    }

    if(!game_model->is_moves_left(player_moves))
    {
        return 0;
    }
    
    if(is_max)
    {
        int max {-1000};

        for(size_t i{0}; i < player_moves.size(); i++)
        {
            if(player_moves[i] == -1)
            {
                player_moves[i] = 2;

                max = std::max(max, minimax(depth+1, !is_max));

                player_moves[i] = -1;
            }
        }

        return max;
    }
    
    int min {1000};

    for (size_t i{0}; i < player_moves.size(); i++)
    {
        if(player_moves[i] == -1)
        {
            player_moves[i] = 1;

            min = std::min(min, minimax(depth+1, !is_max));

            player_moves[i] = -1;
        }
    }

    return min;
}