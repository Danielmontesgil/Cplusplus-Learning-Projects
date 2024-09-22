#include "GameController.h"
#include "IWinnerObserver.h"
#include <cctype>

void GameController::attach(IWinnerObserver* observer)
{
    observer_list.push_back(observer);
}

void GameController::detach(IWinnerObserver* observer)
{
    observer_list.remove(observer);
}

void GameController::notify()
{
    auto iterator = observer_list.begin();

    while (iterator != observer_list.end())
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
