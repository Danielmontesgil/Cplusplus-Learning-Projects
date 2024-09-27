#pragma once
#include <vector>
#include "GameModelBase.h"

class GameModel : public GameModelBase
{
public:
    GameModel() { player_moves = std::vector<int>(9,-1); }
    virtual std::vector<int> get_game_status() override { return player_moves; }
    virtual ~GameModel() override = default;
};
