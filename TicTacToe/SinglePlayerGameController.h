#pragma once
#include "GameControllerBase.h"

// Controller than handles the game flow for a Player and AI
class SinglePlayerGameController : public GameControllerBase
{
public:
    SinglePlayerGameController(GameModelBase* game_model, GameBoardBase* game_board)
        : GameControllerBase(game_model, game_board) {}
    // Handles the game flow for a Single player
    virtual void init_game() override;
    virtual ~SinglePlayerGameController() override = default;
};
