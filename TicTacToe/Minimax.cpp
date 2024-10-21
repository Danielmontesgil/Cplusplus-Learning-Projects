#include "Minimax.h"
#include "GameModel.h"

int Minimax::find_move(int depth, bool is_max, const GameModelBase *game_model)
{
    player_moves = game_model->get_game_status();
    return minimax(depth, is_max, game_model);
}

int Minimax::minimax(int depth, bool is_max, const GameModelBase* game_model)
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

                max = std::max(max, minimax(depth+1, !is_max, game_model));

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

            min = std::min(min, minimax(depth+1, !is_max, game_model));

            player_moves[i] = -1;
        }
    }

    return min;
}