#pragma once
#include "GameControllerBase.h"

// Controller than handles the game flow for a Player and AI
class SinglePlayerGameController : public GameControllerBase
{
public:
    SinglePlayerGameController(std::shared_ptr<GameModelBase> game_model, const std::shared_ptr<GameBoardBase> &game_board_param)
        : GameControllerBase(game_model, game_board_param) {}
    // Handles the game flow for a Single player
    virtual void init_game() override;
    virtual ~SinglePlayerGameController() override = default;
};
