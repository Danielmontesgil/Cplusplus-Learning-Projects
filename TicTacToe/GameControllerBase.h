#pragma once

class GameBoardBase;
class GameModelBase;

// Interface for GameControllers implementation allowing different game modes
class GameControllerBase
{
public:
    GameControllerBase(GameModelBase* game_model, GameBoardBase* game_board)
        : game_model(game_model), game_board(game_board){}
    // Pure method to start the game based on each implementation rules
    virtual void init_game() = 0;
    virtual ~GameControllerBase() = default;

protected:
    GameModelBase* game_model;
    GameBoardBase* game_board;
};
