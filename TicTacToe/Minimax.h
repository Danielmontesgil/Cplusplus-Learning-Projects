#pragma once
#include <vector>

class GameModelBase;

class Minimax
{
public:
    int find_move(int depth, bool is_max, const GameModelBase* game_model);
    bool get_is_draw() { return is_draw; }

private:
    std::vector<int> player_moves;
    bool is_draw {true};
    int minimax(int depth, bool is_max, const GameModelBase* game_model);
};
