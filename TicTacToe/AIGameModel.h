#pragma once
#include "GameModelBase.h"

class AIGameModel : public GameModelBase
{
public:
    AIGameModel() { player_moves = std::vector<int>(9,-1); }
    virtual std::vector<int> get_game_status() override { return player_moves; }
    virtual bool process_input(char player_input, int player) override;
    virtual bool check_winner() const override;
    virtual ~AIGameModel() override = default;

private:
    bool is_moves_left() const;
    int minimax(int depth, bool is_max);
};
