#include <iostream>
#include "GameBoardBase.h"
#include "GameModelBase.h"
#include "TwoPlayerGameController.h"

void TwoPlayerGameController::init_game()
{
    bool finished {false};
    int player_playing {1};

    system("cls");

    game_board->display_board();

    while(!finished)
    {
        char input{};
        const int player {player_playing % 2 != 0 ? 1 : 2};
        std::cout << "Player " << (player == 1 ? "1(X)" : "2(O)") << " enter your movement: ";
        std::cin >> input;

        if(game_model->process_input(input, player))
        {
            system("cls");
            game_board->display_board(game_model->get_game_status());
            if(player_playing >= 5)
            {
                finished = game_model->check_winner();
            }
            player_playing++;
        }
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
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
