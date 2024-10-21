#pragma once
#include "GameModelBase.h"

// Class that models the game between a Player and AI
class AIGameModel : public GameModelBase
{
public:
    // Inits the classic 3x3 board
    AIGameModel() { player_moves = std::vector<int>(9,-1); }
    // Returns the status of the game
    virtual std::vector<int> get_game_status() const override { return player_moves; }
    // Process the input and make the move if it is possible
    virtual bool process_input(char player_input, int player) override;

    virtual bool draw_check(int player_playing) override;
    virtual ~AIGameModel() override = default;
};
