#include <iostream>
#include "GameBoard.h"
#include "GameModel.h"
#include "TwoPlayerGameController.h"

void TwoPlayerGameController::init_game()
{
    bool finished {false};
    int player_playing {1};

    system("cls");

    board->display_board();

    while(!finished)
    {
        char input{};
        const int player {player_playing % 2 != 0 ? 1 : 2};
        std::cout << "Player " << (player == 1 ? "1(X)" : "2(O)") << " enter your movement: ";
        std::cin >> input;

        if(model->process_input(input, player))
        {
            system("cls");
            board->display_board(model->get_game_status());
            if(player_playing >= 5)
            {
                finished = model->check_winner();
            }
        }
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if(finished)
        {
            board->display_winner(player);
        }
        else if(player_playing >= 9)
        {
            board->display_winner(0);
            finished = true;
        }

        player_playing++;
    }
}
