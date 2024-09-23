#pragma once
#include <vector>
#include "GameModelBase.h"

class GameModel : public GameModelBase
{
public:
    GameModel() { player_moves = std::vector<int>(10,-1); }
    virtual std::vector<int> get_game_status() override { return player_moves; }
    virtual bool process_input(char player_input, int player) override;
    virtual bool check_winner() const override;
    virtual ~GameModel() override = default;
};
