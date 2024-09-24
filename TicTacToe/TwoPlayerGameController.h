#pragma once
#include "GameControllerBase.h"

class TwoPlayerGameController : public GameControllerBase
{
public:
    TwoPlayerGameController(GameModelBase* game_model, GameBoardBase* game_board)
        : GameControllerBase(game_model, game_board) {}
    virtual void init_game() override;
    virtual ~TwoPlayerGameController() override = default;
};
