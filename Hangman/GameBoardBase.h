#pragma once
#include<string>

// GameBoardBase is an interface for managing the visual representation of the game board.
class GameBoardBase
{
public:
    // Displays the current state of the game board based on the player's guessed word.
    virtual void display_game_board(const std::string &player_word) const = 0;

    // Updates the game board according to the number of failed attempts.
    virtual void update_board(int fails) = 0;

    // Virtual destructor for cleanup in derived classes.
    virtual ~GameBoardBase() = default;

protected:
    virtual std::string format_word_to_show(const std::string& player_word) const = 0;
};

