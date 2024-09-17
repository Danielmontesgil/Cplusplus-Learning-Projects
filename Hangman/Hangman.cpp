#include <string>
#include <cstdlib>
#include <iostream>
#include "GameBoard.h"
#include "GameController.h"

enum class GameMode
{
    Classic,
    Hardcore
};

int main(int argc, char* argv[])
{
    GameControllerBase* game_controller = {};
    int mode_selection {};

    while(game_controller == nullptr)
    {
        std::cout << "1. Classic\n";
        std::cout << "2. Hardcore\n";
        std::cout << "Enter your preferred mode: ";
        std::cin >> mode_selection;
        
        switch (mode_selection)
        {
        case 1:
            game_controller = new GameController();
            break;
        case 2:
            std::cout << "This mode is not implemented yet\n";
            game_controller = nullptr;
            break;
        default:
            game_controller = nullptr;
            break;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    auto is_playing {true};
    auto game_board = GameBoard();
    std::string letter {};

    game_controller->init_game();

    while (is_playing)
    {
        if(game_controller->get_player_word().empty())
        {
            is_playing = false;
            std::cout << "The word is empty";
        }
        
        system("cls");
        game_board.display_game_board(game_controller->get_player_word());
        std::cout << "Enter a letter: ";
        std::cin >> letter;

        game_controller->process_input(letter, [&is_playing, &game_controller] ()
        {
            system("cls");
            std::cout << "Player wins\n";
            game_controller->display_mistakes(true);
            std::cout << "\n";
            is_playing = false;
        }, [&is_playing, &game_controller] ()
        {
            system("cls");
            std::cout << "Player loses\n";
            game_controller->display_mistakes();
            std::cout << "\n";
            is_playing = false;
        });

        game_board.update_board(game_controller->get_fails());
        
        if(!is_playing)
        {
            game_board.display_game_board(game_controller->get_player_word());
            std::string input;
            std::cout << "\nDo you want to play again? (Y/N): ";
            std::cin >> input;
            if(std::toupper(input[0]) == 'Y')
            {
                is_playing = true;
                game_controller->init_game(true);
                game_board.update_board(game_controller->get_fails());
            }
        }
    }

    delete game_controller;
    
    return 0;
}

// añadir interfaces para permitir otros modos de juego donde se puedan cambiar las reglas