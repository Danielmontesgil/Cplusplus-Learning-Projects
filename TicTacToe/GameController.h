#pragma once
#include <vector>

class GameController
{
public:

    // GameController methods
    GameController() : player_moves(10,-1){}
    std::vector<int> get_game_status() { return player_moves; }
    bool process_input(char player_input, int player);
    bool check_winner() const;
    virtual ~GameController() = default;
    
private:
    std::vector<int> player_moves;
};
