#pragma once
#include<string>
#include<functional>

class GameControllerBase
{
public:
    virtual void init_game(bool play_again = false) = 0;
    virtual int get_fails() const = 0;
    virtual std::string get_player_word() const = 0;
    virtual void process_input(const std::string &input, const std::function<void()> &win_callback, const std::function<void()> &lose_callback) = 0;
    virtual void display_mistakes(bool player_won = false) const = 0;
    virtual ~GameControllerBase() = default;
};
