#include <iostream>
#include "GameBoardBase.h"
#include "GameModelBase.h"
#include "SinglePlayerGameController.h"

#include <random>

void SinglePlayerGameController::init_game()
{
    bool finished {false};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 1);
    int player_playing {distr(gen)};
    
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
                finished = game_model->check_winner(game_model->get_game_status());
            }
            player_playing++;
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
        else if(!game_model->is_moves_left())
        {
            game_board->display_winner(0);
            finished = true;
        }
    }
}
