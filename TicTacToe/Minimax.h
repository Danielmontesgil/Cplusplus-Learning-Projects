#pragma once
#include <vector>

class GameModelBase;

class Minimax
{
public:
    Minimax(const std::vector<int> &board) : player_moves(board){}
    int find_move(int depth, bool is_max, const GameModelBase* game_model, int player_playing);
    bool get_is_draw() const { return is_draw; }

private:
    std::vector<int> player_moves;
    bool is_draw {true};
    int minimax(int depth, bool is_max, const GameModelBase* game_model);
};
