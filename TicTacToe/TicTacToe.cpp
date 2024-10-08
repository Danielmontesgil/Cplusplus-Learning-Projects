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
    const auto game_board {new GameBoard()};
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
                const auto game_model {new AIGameModel()};
                const auto game_controller {new SinglePlayerGameController(game_model, game_board)};
                game_controller->init_game();
                game_mode_selected = true;
                delete game_model;
                delete game_controller;
            }
            else if(val == 2)
            {
                const auto game_model {new GameModel()};
                const auto game_controller {new TwoPlayerGameController(game_model, game_board)};
                game_controller->init_game();
                game_mode_selected = true;
                delete game_model;
                delete game_controller;
            }
        }

        if(!game_mode_selected)
        {
            system("cls");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    delete game_board;
    
    return 0;
}
