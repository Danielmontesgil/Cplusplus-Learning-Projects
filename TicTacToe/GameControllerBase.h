#pragma once

class GameBoardBase;
class GameModelBase;

class GameControllerBase
{
public:
    GameControllerBase(GameModelBase* game_model, GameBoardBase* game_board)
        : game_model(game_model), game_board(game_board){}
    virtual void init_game() = 0;
    virtual ~GameControllerBase() = default;

protected:
    GameModelBase* game_model;
    GameBoardBase* game_board;
};
