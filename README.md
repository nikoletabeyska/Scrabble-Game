# Scrabble-Game
   
          Scrabble

Scrabble is a game in which the user is given random combination of letters with which he should make a valid word.
The game has 10 rounds with 10 available letters each. Their number can be changed at the discretion of the player.
Each correct word gives points which equal the number of the word's letters.

           Usage

 You will be shown a MENU with 5 options:

* Option 1 is to start a new game. At the beginning of every game you will be displayed your highest score.
  During the game you should enter a word each round. 

  Your word is invalid if:
- It contains letters different from the given
- The word is longer than the number of the given letters
- The word isn't in the dictionary

  If you input an invalid letter you will be given the opportunity to try again, see a possible word and refresh the round
  or exit the game and return to the menu.:
- You should enter '0' to see a possible word and refresh the round with different letters.
- You should enter 'M' to exit the game and return to the menu.

 After the last round you will be shown your total points and be returned to the menu.

* Option 2 is settings. You have 2 options:
 'a'- To change the number of letters. The new number is valid until you change it again or you close the program.
 'b'- To change the number of rounds. The new number is valid until you change it again or you close the program.

* Option 3 is to add a new word to the dictionary:
- The program would add it only if it consists only of letters and if it's not present in the dictionary.
- Else you will be given an opportunity to enter a word again or return to the menu:
  - You should enter '1' to return to the menu.

* Option 4 is to exit the game.

* Option 5 is to display the rules of the game in short as they are written in here.

 Note: Scrabble.cpp, Helping_Functions.cpp, Helping_Functions.h, Dictionary.txt should be in the same folder.   
