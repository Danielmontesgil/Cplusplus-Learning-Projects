#pragma once
#include <memory>
#include <vector>
#include "GameModelBase.h"
#include "Minimax.h"

// Classic Tic Tac Toe for two players
class GameModel : public GameModelBase
{
public:
    // Inits the classic 3x3 board
    GameModel() { player_moves = std::vector<int>(9,-1); }
    // Returns the status of the game
    virtual std::vector<int> get_game_status() const override { return player_moves; }

    virtual bool draw_check(int player_playing) override;
    virtual ~GameModel() override = default;
};

inline bool GameModel::draw_check(const int player_playing)
{
    const std::unique_ptr<Minimax> minimax {new Minimax(shared_from_this(), player_moves)};
    minimax->find_move(0, false, player_playing);

    return minimax->get_is_draw();
}
