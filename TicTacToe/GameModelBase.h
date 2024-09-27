#pragma once
#include <vector>

// Abstract class that offers basic implementation for different GameModes
class GameModelBase
{
public:
    // Returns the status of the game
    virtual std::vector<int> get_game_status() = 0;
    // Process the input and make the move if it is possible
    virtual bool process_input(char player_input, int player);
    // Returns true if a player won the game
    virtual bool check_winner() const;
    // Returns true if there are available moves in the board
    virtual bool is_moves_left() const;
    virtual ~GameModelBase() = default;

protected:
    std::vector<int> player_moves;
};
