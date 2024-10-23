#pragma once
#include "GameControllerBase.h"

// Controller than handles the game flow for two players
class TwoPlayerGameController : public GameControllerBase
{
public:
    TwoPlayerGameController(const std::shared_ptr<GameModelBase> &game_model_param, const std::shared_ptr<GameBoardBase> &game_board_param)
        : GameControllerBase(game_model_param, game_board_param) {}
    // Handles the game flow for 2 Players
    virtual void init_game() override;
    virtual ~TwoPlayerGameController() override = default;
};
