#pragma once
#include<string>
#include<functional>

// Interface to create different game modes
class GameModeBase
{
public:
    // Initializes the game. If 'play_again' is true, it resets the game for a new round.
    virtual void init_game(bool play_again = false) = 0;

    // Returns the number of mistakes the player has made so far.
    virtual int get_fails() const = 0;

    // Retrieves the current state of the player's guessed word, showing correctly guessed letters and hidden ones.
    virtual std::string get_player_word() const = 0;

    // Processes the player's input, either a letter or a full word. 
    // If the player wins or loses, the appropriate callback is executed.
    virtual void process_input(std::string &input, const std::function<void()> &win_callback, const std::function<void()> &lose_callback) = 0;

    // Displays the player's incorrect guesses and, if the player has lost, the correct word.
    virtual void display_mistakes(bool player_won = false) const = 0;

    // Virtual destructor to allow proper cleanup in derived classes.
    virtual ~GameModeBase() = default;
};

