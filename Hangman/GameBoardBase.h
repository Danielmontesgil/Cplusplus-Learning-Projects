#pragma once
#include<string>

class GameBoardBase
{
public:
    virtual void display_game_board(const std::string &player_word) const = 0;
    virtual void update_board(int fails) = 0;
    virtual ~GameBoardBase() = default;
};
