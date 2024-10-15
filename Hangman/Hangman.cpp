#include <string>
#include <cstdlib>
#include <iostream>
#include "ClassicGameBoard.h"
#include "ClassicGameMode.h"

enum class GameMode
{
    Classic,
    Hardcore
};

int main(int argc, char* argv[])
{
    GameModeBase* game_mode = {};
    int mode_selection {};

    while(game_mode == nullptr)
    {
        std::cout << "1. Classic\n";
        std::cout << "2. Hardcore\n";
        std::cout << "Enter your preferred mode: ";
        std::cin >> mode_selection;
        
        switch (mode_selection)
        {
        case 1:
            game_mode = new ClassicGameMode();
            break;
        case 2:
            std::cout << "This mode is not implemented yet\n";
            game_mode = nullptr;
            break;
        default:
            game_mode = nullptr;
            break;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    auto is_playing {true};
    auto game_board = ClassicGameBoard();
    std::string letter {};

    game_mode->init_game();

    while (is_playing)
    {
        if(game_mode->get_player_word().empty())
        {
            is_playing = false;
            std::cout << "The word is empty";
        }
        
        system("cls");
        game_board.display_game_board(game_mode->get_player_word());
        std::cout << "Enter a letter: ";
        std::cin >> letter;
    
        game_mode->process_input(letter, [&is_playing, &game_mode] ()
        {
            system("cls");
            std::cout << "Player wins\n";
            game_mode->display_mistakes(true);
            std::cout << "\n";
            is_playing = false;
        }, [&is_playing, &game_mode] ()
        {
            system("cls");
            std::cout << "Player loses\n";
            game_mode->display_mistakes();
            std::cout << "\n";
            is_playing = false;
        });
    
        game_board.update_board(game_mode->get_fails());
        
        if(!is_playing)
        {
            game_board.display_game_board(game_mode->get_player_word());
            std::string input;
            std::cout << "\nDo you want to play again? (Y/N): ";
            std::cin >> input;
            if(std::toupper(input[0]) == 'Y')
            {
                is_playing = true;
                game_mode->init_game(true);
                game_board.update_board(game_mode->get_fails());
            }
        }
    }

    delete game_mode;
    
    return 0;
}
