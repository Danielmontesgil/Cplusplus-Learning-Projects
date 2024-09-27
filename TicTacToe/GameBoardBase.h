#pragma once
#include <vector>

// Interface to display the board on the console
class GameBoardBase
{
public:
    // Parameterless version assumes the board is at initial state
    virtual void display_board() const = 0;
    // Takes the game status and shows the board on the console
    virtual void display_board(const std::vector<int> &game_status) const  = 0;
    // Displays a text when a player won the game, pass 0 to display a draw game
    virtual void display_winner(int winner) const = 0;
    virtual ~GameBoardBase() = default;
};
