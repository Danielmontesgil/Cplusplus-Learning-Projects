﻿#pragma once
#include <memory>
#include <vector>

// Abstract class that offers basic implementation for different GameModes
class GameModelBase : public std::enable_shared_from_this<GameModelBase>
{
public:
    // Returns the status of the game
    virtual std::vector<int> get_game_status() const = 0;
    // Process the input and make the move if it is possible
    virtual bool process_input(char player_input, int player);
    // Returns true if a player won the game
    virtual bool check_winner(std::vector<int> board_to_check) const;
    virtual bool draw_check(int player_playing) = 0;
    // Returns true if there are available moves in the board
    virtual bool is_moves_left(const std::vector<int> &board_to_check) const;
    virtual ~GameModelBase() = default;

protected:
    std::vector<int> player_moves;
};
