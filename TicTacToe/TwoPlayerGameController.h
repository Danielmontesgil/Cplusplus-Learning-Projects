#pragma once

class GameModel;
class GameBoard;

class TwoPlayerGameController
{
public:
    TwoPlayerGameController(GameModel* model, GameBoard* board):
        model(model), board(board){}
    void init_game();

private:
    GameModel* model;
    GameBoard* board;
};
