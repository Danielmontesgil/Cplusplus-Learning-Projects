#include "Minimax.h"
#include "GameModel.h"

std::vector<int> Minimax::player_moves;

int Minimax::find_move(int depth, bool is_max, const GameModelBase *game_model)
{
    player_moves = game_model->get_game_status();
    return minimax(depth, is_max, game_model);
}

int Minimax::minimax(int depth, bool is_max, const GameModelBase* game_model)
{
    bool winner = game_model->check_winner();

    if(winner && is_max)
    {
        return -10 + depth;
    }

    if(winner && !is_max)
    {
        return 10 - depth;
    }

    if(!game_model->is_moves_left())
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

                best = std::max(best, minimax(depth+1, !is_max, game_model));

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

            best = std::min(best, minimax(depth+1, !is_max, game_model));

            player_moves[i] = -1;
        }
    }

    return best;
}

