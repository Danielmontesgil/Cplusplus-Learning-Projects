#pragma once
#include <string>
#include <vector>
#include <functional>
#include "GameModeBase.h"

// Classic game mode that implements GameModeBase
class ClassicGameMode : public GameModeBase
{
public:
    // Initializes the game. If 'play_again' is true, it resets the game for a new round.
    virtual void init_game(bool play_again = false) override;
    // Returns the number of mistakes the player has made so far.
    virtual int get_fails() const override {return fails;}
    // Retrieves the current state of the player's guessed word, showing correctly guessed letters and hidden ones.
    virtual std::string get_player_word() const override {return player_word;}
    // Processes the player's input, either a letter or a full word. 
    // If the player wins or loses, the appropriate callback is executed.
    virtual void process_input(std::string &input, const std::function<void()> &win_callback,
        const std::function<void()> &lose_callback) override;
    // Displays the player's incorrect guesses and, if the player has lost, the correct word.
    virtual void display_mistakes(bool player_won = false) const override;
    
private:
    std::vector<std::string> words_vector;
    std::string word {};
    std::string player_word {};
    int fails {0};
    std::vector<std::string> player_tries {};

    int fails_per_word {3};
    int max_fails {7};

    void select_word();
    void process_file();
};
