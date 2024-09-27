#pragma once
#include <vector>

class GameModelBase
{
public:
    virtual std::vector<int> get_game_status() = 0;
    virtual bool process_input(char player_input, int player);
    virtual bool check_winner() const;
    virtual bool is_moves_left() const;
    virtual ~GameModelBase() = default;

protected:
    std::vector<int> player_moves;
};
