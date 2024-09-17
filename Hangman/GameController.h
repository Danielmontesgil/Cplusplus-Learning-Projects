#pragma once
#include <string>
#include <vector>
#include <functional>
#include "GameControllerBase.h"

class GameController : public GameControllerBase
{
public:
    virtual void init_game(bool play_again = false) override;
    int get_fails() const {return fails;}
    std::string get_player_word() const {return player_word;}
    virtual void process_input(const std::string &input, const std::function<void()> &win_callback,
        const std::function<void()> &lose_callback) override;
    virtual void display_mistakes(bool player_won = false) const override;
    
private:
    std::vector<std::string> words_vector;
    std::string word {};
    std::string player_word {};
    int fails {0};
    std::vector<char> player_tries {};

    void select_word();
    void process_file();
};
