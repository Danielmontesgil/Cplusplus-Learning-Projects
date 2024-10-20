#pragma once
#include <vector>

class GameModelBase;

class Minimax
{
public:
    static int find_move(int depth, bool is_max, const GameModelBase* game_model);

private:
    static std::vector<int> player_moves;
    static int minimax(int depth, bool is_max, const GameModelBase* game_model);
};
