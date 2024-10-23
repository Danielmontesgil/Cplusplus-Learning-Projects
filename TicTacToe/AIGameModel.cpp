#include "AIGameModel.h"
#include <memory>
#include "Minimax.h"

bool AIGameModel::process_input(char player_input, const int player)
{
    if(player == 1)
    {
        return GameModelBase::process_input(player_input, player);
    }

    std::unique_ptr<Minimax> minimax {new Minimax()};
    
    player_moves[check(minimax, player)] = 2;

    delete minimax;
    return true;
}

bool AIGameModel::draw_check(const int player_playing)
{
    std::unique_ptr<Minimax> minimax {new Minimax()};

    check(minimax, player_playing);

    const auto draw = minimax->get_is_draw();
    delete minimax;
    return draw;
}

int AIGameModel::check(const std::unique_ptr<Minimax> &minimax, const int player_playing)
{
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

    return best_move;
}
