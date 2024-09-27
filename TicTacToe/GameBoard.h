#pragma once
#include <string>
#include <vector>
#include "GameBoardBase.h"

// Handle the view of the board and any state
class GameBoard : public GameBoardBase
{
public:
    // Parameterless version assumes the board is at initial state
    virtual void display_board() const override;
    // Takes the game status and shows the board on the console
    virtual void display_board(const std::vector<int> &game_status) const override;
    // Displays a text when a player won the game, pass 0 to display a draw game
    virtual void display_winner(int winner) const override;
    virtual ~GameBoard() override = default;

private:
    std::string row_separator {"-----------"};
    constexpr static char colum_separator {'|'};
    constexpr static int board_width {3};
    constexpr static char player_1_symbol{'X'};
    constexpr static char player_2_symbol{'O'};
};
