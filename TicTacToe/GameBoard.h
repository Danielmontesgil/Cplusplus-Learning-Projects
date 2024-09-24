#pragma once
#include <string>
#include <vector>
#include "GameBoardBase.h"

class GameBoard : public GameBoardBase
{
public:
    virtual void display_board() const override;
    virtual void display_board(const std::vector<int> &game_status) const override;
    virtual void display_winner(int winner) const override;
    virtual ~GameBoard() override = default;

private:
    std::string row_separator {"-----------"};
    constexpr static char colum_separator {'|'};
    constexpr static int board_width {3};
    constexpr static char player_1_symbol{'X'};
    constexpr static char player_2_symbol{'O'};
};
