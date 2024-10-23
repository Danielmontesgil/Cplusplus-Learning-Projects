#pragma once

class GameBoardBase;
class GameModelBase;

// Interface for GameControllers implementation allowing different game modes
class GameControllerBase
{
public:
    GameControllerBase(const std::shared_ptr<GameModelBase> &game_model_param, const std::shared_ptr<GameBoardBase> &game_board_param)
        : game_model(game_model_param), game_board(game_board_param){}
    // Pure method to start the game based on each implementation rules
    virtual void init_game() = 0;
    virtual ~GameControllerBase() = default;

protected:
    std::shared_ptr<GameModelBase> game_model;
    std::shared_ptr<GameBoardBase> game_board;
};
