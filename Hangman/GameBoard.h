#pragma once
#include "GameBoardBase.h"

class GameBoard : public GameBoardBase
{
public:
    virtual void display_game_board(const std::string &player_word) const override;
    virtual void update_board(int fails) override;

private:
    std::string line1 {" -----  \n"};
    std::string line2 {" |   |  \n"};
    std::string line3 {"     |  \n"};
    std::string line4 {"     |  \n"};
    std::string line5 {"     |  \n"};
    std::string line6 {"     |  \n"};
};
