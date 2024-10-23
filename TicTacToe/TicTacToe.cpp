#include <iostream>
#include "AIGameModel.h"
#include "GameBoard.h"
#include "GameModel.h"
#include "SinglePlayerGameController.h"
#include "TwoPlayerGameController.h"

enum class GameMode
{
    SinglePlayer,
    TwoPlayers
};

int main(int argc, char* argv[])
{    
    const std::shared_ptr<GameBoardBase> game_board {new GameBoard()};
    bool game_mode_selected {false};

    while(!game_mode_selected)
    {
        char input;
        std::cout << "1. Single Player\n" << "2. Two Players\n" << "Select a Game Mode: ";
        std::cin >> input;

        if(isdigit(input))
        {
            const int val = input - '0';
            if(val == 1)
            {
                const std::shared_ptr<GameModelBase> game_model {new AIGameModel()};
                const std::unique_ptr<GameControllerBase> game_controller {new SinglePlayerGameController(game_model, game_board)};
                game_controller->init_game();
                game_mode_selected = true;
            }
            else if(val == 2)
            {
                const std::shared_ptr<GameModelBase> game_model {new GameModel()};
                const std::unique_ptr<GameControllerBase> game_controller {new TwoPlayerGameController(game_model, game_board)};
                game_controller->init_game();
                game_mode_selected = true;
            }
        }

        if(!game_mode_selected)
        {
            system("cls");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    return 0;
}
