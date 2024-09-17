#include <fstream>
#include <vector>
#include <random>
#include <iostream>
#include "GameController.h"

void GameController::init_game(bool play_again)
{
    fails = 0;
    player_tries = {};
    if(!play_again)
    {
        process_file();
    }
    select_word();
}

void GameController::process_file()
{
    std::ifstream words_file {"words.txt"};
    std::string line;
    if(words_file)
    {
        while (std::getline(words_file, line))
        {
            words_vector.push_back(line);
        }
    }
    else
    {
        std::cout << "words_vector is empty";
    }
}

void GameController::select_word()
{
    if(!words_vector.empty())
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0, static_cast<int>(words_vector.size()) - 1);
        int random_index = distr(gen);

        word = words_vector[random_index];
        player_word = word;
        words_vector.erase(words_vector.begin() + random_index);
        std::transform(player_word.cbegin(), player_word.cend(), player_word.begin(), [] (char a) {return '_';});
    }
}

void GameController::process_input(const std::string &input, const std::function<void()>& win_callback, const std::function<void()>& lose_callback)
{
    bool success {false};

    if(input.size() > 1)
    {
        if(input == word)
        {
            player_word = word;
            win_callback();
            return;
        }
    }
    
    for (size_t i = 0; i < word.size(); ++i)
    {
        if(input[0] == word[i])
        {
            player_word[i] = input[0];
            success = true;

            if(word == player_word)
            {
                win_callback();
            }
        }
    }

    if(!success)
    {
        fails = input.size() > 1 ? fails + 3 : fails + 1;
        player_tries.push_back(input[0]);
        if(fails >= 7)
        {
            lose_callback();
        }
    }
}

void GameController::display_mistakes(bool player_won) const
{
    if(player_tries.empty())
    {
        return;
    }
    std::cout << "Your mistakes: "; 
    for (auto letter : player_tries)
    {
        std::cout << letter << " ";
    }
    std::cout << "\n";
    if(!player_won)
    {
        std::cout << "The correct word was : " << word << "\n";
    }
}
