#pragma once
#include "GameControllerBase.h"

// Controller than handles the game flow for two players
class TwoPlayerGameController : public GameControllerBase
{
public:
    TwoPlayerGameController(GameModelBase* game_model, GameBoardBase* game_board)
        : GameControllerBase(game_model, game_board) {}
    // Handles the game flow for 2 Players
    virtual void init_game() override;
    virtual ~TwoPlayerGameController() override = default;
};
