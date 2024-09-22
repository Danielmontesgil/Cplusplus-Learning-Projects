#include <iostream>
#include "GameBoard.h"
#include "GameController.h"

int main(int argc, char* argv[])
{
    bool is_playing {true};
    auto game_controller {GameController()};
    auto game_board {GameBoard()};
    game_board.display_board();

    while(is_playing)
    {
        int input{};
        std::cout << "Player 1 (X) enter your movement: ";
        std::cin >> input;

        // if(game_controller.validate_input(input))
        // {
            system("cls");
            game_board.display_board(1, input);
        // }
        // else
        // {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //continue;
        //}

        std::cout << "Player 2 (O) enter your movement: ";
        std::cin >> input;
        
        // if(game_controller.validate_input(input))
        // {
            system("cls");
            game_board.display_board(2, input);
        // }
        // else
        // {
        //     continue;
        // }
        
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Win condition, maybe implement the model here
        // How should manage the input?
        
        //is_playing = false;
    }
    
    return 0;
}
