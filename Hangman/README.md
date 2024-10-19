# Hangman

A console-based classic **Hangman** game where the player has limited chances to guess a hidden word. This version keeps
the familiar rules while adding some unique twists for an engaging gameplay experience.

### Rules:
- **Random Word Selection**: A word is randomly chosen from the `words.txt` file, which contains 165 gaming-related words.
Feel free to expand the file by adding more words!
- **7 Chances**: You have 7 attempts to guess the word correctly. Each incorrect guess counts as a failure.
- **Flexible Inputs**: You can try guessing any character, including numbers and special characters. However, incorrect
guesses will count towards your failures (Note: the default word list doesn't contain numbers or special characters).
- **Full Word Guessing**: You may attempt to guess the entire word, but be warned: an incorrect full-word guess will cost
you 3 fails!
- **Replay & Non-Repetitive Words**: After each game, you’ll be asked if you’d like to play again. The game guarantees that
no word will be repeated until all words in the file have been played.

### C++ Concepts Used:
- **File Handling**: Dynamic word loading using `fstream`.
- **Raw Pointers**: Leveraged for memory management.
- **Abstract Classes**: Used to create flexible, reusable code.
- **Dynamic Binding**: Achieved through inheritance, allowing for extendable game logic.
- **Standard Library (STL)**: Utilized containers and algorithms for efficient word management.
- **Stream Manipulation**: Controlled input/output using various stream manipulators.
