#include <iostream>
#include "GameBoard.h"
#include "GameController.h"

int main(int argc, char* argv[])
{
    bool finished {false};
    auto game_controller {GameController()};
    const auto game_board {GameBoard()};
    int player_playing {1};
    
    game_board.display_board();

    while(!finished)
    {
        char input{};
        const int player {player_playing % 2 != 0 ? 1 : 2};
        std::cout << "Player " << (player == 1 ? "1(X)" : "2(O)") << " enter your movement: ";
        std::cin >> input;

        if(game_controller.process_input(input, player))
        {
            system("cls");
            player_playing++;
            game_board.display_board(game_controller.get_game_status());
            finished = game_controller.check_winner();
        }
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if(finished)
        {
            game_board.display_winner(player);
        }
    }
    
    return 0;
}
