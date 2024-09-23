#pragma once
#include <vector>

class GameController
{
public:
    GameController() : player_moves(10,-1){}
    bool validate_input(char player_input);
private:
    std::vector<int> player_moves;
};
