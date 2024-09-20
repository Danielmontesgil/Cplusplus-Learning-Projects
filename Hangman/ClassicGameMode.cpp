#include <fstream>
#include <vector>
#include <random>
#include <iostream>
#include "ClassicGameMode.h"

void ClassicGameMode::init_game(bool play_again)
{
    fails = 0;
    player_tries = {};
    if(!play_again)
    {
        process_file();
    }
    select_word();
}

void ClassicGameMode::process_file()
{
    std::ifstream words_file {"words.txt"};
    std::string line;
    if(words_file)
    {
        // Handles (BOM) code
        if (words_file.peek() == 0xEF) {
            words_file.get(); // 0xEF
            words_file.get(); // 0xBB
            words_file.get(); // 0xBF
        }
        std::getline(words_file, line);
        std::cout << line;
        while (std::getline(words_file, line))
        {
            std::transform(line.cbegin(), line.cend(), line.begin(), std::toupper);
            words_vector.push_back(line);
        }
    }
    else
    {
        std::cout << "words_vector is empty";
    }
}

void ClassicGameMode::select_word()
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

void ClassicGameMode::process_input(std::string &input, const std::function<void()>& win_callback, const std::function<void()>& lose_callback)
{
    bool success {false};
    std::transform(input.cbegin(), input.cend(), input.begin(), std::toupper);

    if(input.size() > 1)
    {
        if(input == word)
        {
            player_word = word;
            win_callback();
            return;
        }
    }
    else
    {
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
    }
    
    if(!success)
    {
        fails = input.size() > 1 ? fails + fails_per_word : ++fails;
        player_tries.push_back(input);
        if(fails >= max_fails)
        {
            lose_callback();
        }
    }
}

void ClassicGameMode::display_mistakes(const bool player_won) const
{
    if(player_tries.empty())
    {
        return;
    }
    std::cout << "Your mistakes: "; 
    for (const auto &letter : player_tries)
    {
        std::cout << letter << " ";
    }
    std::cout << "\n";
    if(!player_won)
    {
        std::cout << "The correct word was : " << word << "\n";
    }
}
