#pragma once
#include <memory>
#include <vector>

class GameModelBase;

class Minimax
{
public:
    Minimax(const std::shared_ptr<GameModelBase> &game_model_param, const std::vector<int> &board)
        : game_model(game_model_param), player_moves(board){}
    int find_move(int depth, bool is_max, int player_playing);
    bool get_is_draw() const { return is_draw; }

private:
    std::shared_ptr<GameModelBase> game_model;
    std::vector<int> player_moves;
    bool is_draw {true};

    
    int minimax(int depth, bool is_max);
};
