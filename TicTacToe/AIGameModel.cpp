#include "AIGameModel.h"
#include <memory>

#include "GameBoardBase.h"
#include "Minimax.h"

bool AIGameModel::process_input(char player_input, const int player)
{
    if(player == 1)
    {
        return GameModelBase::process_input(player_input, player);
    }

    const std::unique_ptr<Minimax> minimax {new Minimax(shared_from_this(), player_moves)};
    
    player_moves[minimax->find_move(0, false, player)] = 2;

    return true;
}

bool AIGameModel::draw_check(const int player_playing)
{
    const std::unique_ptr<Minimax> minimax {new Minimax(shared_from_this(), player_moves)};

    minimax->find_move(0, false, player_playing);

    const auto draw = minimax->get_is_draw();
    return draw;
}
