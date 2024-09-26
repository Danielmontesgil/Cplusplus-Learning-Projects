#include <iostream>
#include "GameBoardBase.h"
#include "GameModelBase.h"
#include "SinglePlayerGameController.h"

void SinglePlayerGameController::init_game()
{
    bool finished {false};
    int player_playing {1};
    
    system("cls");
    
    game_board->display_board();
    
    while(!finished)
    {
        char input{};
        const int player {player_playing % 2 != 0 ? 1 : 2};
        if(player == 1)
        {
            std::cout << "Player (X) enter your movement: ";
            std::cin >> input;
        }
    
        if(game_model->process_input(input, player))
        {
            system("cls");
            game_board->display_board(game_model->get_game_status());
            if(player_playing >= 5)
            {
                finished = game_model->check_winner();
            }
        }

        if(player == 1)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        
        if(finished)
        {
            game_board->display_winner(player);
        }
        else if(player_playing >= 9)
        {
            game_board->display_winner(0);
            finished = true;
        }
    
        player_playing++;
    }
}
