#pragma once
#include "GameBoardBase.h"

// Classic Game board that implements GameBoardBase
class ClassicGameBoard : public GameBoardBase
{
public:
    // Displays the current state of the game board based on the player's guessed word.
    virtual void display_game_board(const std::string &player_word) const override;
    // Updates the game board according to the number of failed attempts.
    virtual void update_board(int fails) override;

private:
    std::string line1 {" -----  \n"};
    std::string line2 {" |   |  \n"};
    std::string line3 {"     |  \n"};
    std::string line4 {"     |  \n"};
    std::string line5 {"     |  \n"};
    std::string line6 {"     |  \n"};
};
