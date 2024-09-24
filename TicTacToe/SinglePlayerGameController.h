#pragma once
#include "GameControllerBase.h"

class SinglePlayerGameController : public GameControllerBase
{
public:
    SinglePlayerGameController(GameModelBase* game_model, GameBoardBase* game_board)
        : GameControllerBase(game_model, game_board) {}
    virtual void init_game() override;
    virtual ~SinglePlayerGameController() override = default;
};
