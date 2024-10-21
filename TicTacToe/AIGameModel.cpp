#include "AIGameModel.h"
#include "Minimax.h"

bool AIGameModel::process_input(char player_input, int player)
{
    if(player == 1)
    {
        return GameModelBase::process_input(player_input, player);
    }

    Minimax* minimax = new Minimax();
    int best_val {-1000};
    int best_move {0};

    for(size_t i{0}; i < player_moves.size(); i++)
    {
        if(player_moves[i] == -1)
        {
            player_moves[i] = 2;

            int moveVal = minimax->find_move(0, false, this);

            player_moves[i] = -1;

            if(moveVal > best_val)
            {
                best_move = static_cast<int>(i);
                best_val = moveVal;
            }
        }
    }
    
    player_moves[best_move] = 2;

    return true;
}

bool AIGameModel::draw_check(int player_playing)
{
    Minimax* minimax = new Minimax();
    int best_val {-1000};
    int best_move {0};

    for(size_t i{0}; i < player_moves.size(); i++)
    {
        if(player_moves[i] == -1)
        {
            player_moves[i] = player_playing % 2;

            int moveVal = minimax->find_move(0, false, this);

            player_moves[i] = -1;

            if(moveVal > best_val)
            {
                best_move = static_cast<int>(i);
                best_val = moveVal;
            }
        }
    }

    return minimax->get_is_draw();
}

