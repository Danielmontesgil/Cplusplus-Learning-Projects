#include "GameController.h"
#include <cctype>

bool GameController::process_input(char player_input, int player)
{
    if(isdigit(player_input))
    {
        (*iterator)->update();
        ++iterator;
    }
}

bool GameController::validate_input(char player_input)
{
    const auto digit = isdigit(player_input);
    if(digit > 0)
    {
        if(player_moves.at(digit) == -1)
        {
            player_moves[digit] = digit;
            return true;
        }
    }

    return false;
}
