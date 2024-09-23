#pragma once
#include <vector>

class GameBoardBase
{
public:
    virtual void display_board() const = 0;
    virtual void display_board(const std::vector<int> &game_status) const  = 0;
    virtual void display_winner(int winner) const = 0;
};
