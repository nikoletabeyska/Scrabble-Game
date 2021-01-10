// Scrabble.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/**
*
* Solution to course project # 8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Nikoleta Beyska
* @idnumber 62540
* @compiler VC
*
* <file with main cpp file>
*
*/

#include <iostream>
#include<iomanip>
#include<limits>
#include "Helping_Functions.h"
using namespace std;

// Executes if you start a new game
void Main_Game(int& numberofletters, int& numberofrounds,int& highest_score) {
	string word;
	string letters;
	string existing_word;
	bool fail = 0;
	int failed_round = 0;
	bool returntoMENU = 0;
	int points = 0;
	cout << endl;
	for (int i = 1; i <= numberofrounds; i++) {
		// Executes if the user has chosen to refresh the round with different combination of letters
		if (fail) {
			i = failed_round;
			fail = 0;
		}
		cout << setw(10) << " Round " << i << endl;
		cout << " Available letters: ";
		GenerateRandomLetters(numberofletters, letters,existing_word);
		cout << endl;
		cout << " Enter your word: ";
		cin >> word;
		// If true, shows the user a possible word and continues the loop, refreshing the round
		if (word[0] == '0') {
			// Displays a possible word and erases the word string and the letters string
			ShowPossibleWord(word, letters, existing_word);
			// Boolean value changes as an indicator for a failed round
			fail = 1;
			// Stores the number of the failed round
			failed_round = i;
			continue;
		}
		// If true, breaks the loop and exits the function, then displays the menu again
		if (word[0] == 'M') {
			cout << endl;
			break;
		}
		// Continues until a valid word is entered or the input is either '0' or 'M' 
		while (!Word_Check(letters, word)) {
			// Erasing the word string every loop
			word.erase();
			cout << endl;
			cout << " Invalid word. Try again with: ";
			for (int i = 0; i < letters.length(); i++) cout << letters[i] << " ";
			cout << endl;
			cout << " Enter your word: ";
			cin >> word;
			// If true, shows the user a possible word and exits the while case
			if (word[0] == '0') {
				// Displays a possible word and erases the word string and the letters string
				ShowPossibleWord(word, letters, existing_word);
			    // Boolean value changes as an indicator for a failed round
				fail = 1;
				// Stores the number of the failed round
				failed_round = i;
				break;
			}
			// If true, exits the while case
			if (word[0] == 'M') {
				// Boolean value changes as an indicator for wanted exit of the game
				returntoMENU = 1;
				break;
			}
		}
		// If the user has choosen to refresh the round the loop continues
		if (fail) {
			continue;
		}
		// If the user has choosen to return to the menu the loop breaks
		if (returntoMENU) {
			cout << endl;
			break;
		}
		// Calculating the points
		points += word.length();
		// Displays the curent points until the last possible round
		if (i != numberofrounds) {
			cout << " Your points so far are: " << points << endl;
		}
		// Erases the letters string each round
		letters.erase();
		// Erases the word string each round
		word.erase();
		cout << endl;
	}
	//Displays after the last round
	cout << "--->";
	cout << "Your total points are: " << points<<endl;
	cout << endl;
	if (points > highest_score) {
		highest_score = points;
		cout << " You have new highest score!" << endl;
		cout << endl;
	}
	cout << " *Returning to MENU*" << endl;
	cout << endl;
}

int main()
{
	int choice = 0;
	int numberofletters = 10;
	int numberofrounds =10;
	int highest_score = 0;
	// Initializes the random number generator
	srand((unsigned int)time(NULL));
	cout << "----------------------" << endl;
	cout << "     SCRABBLE" << endl;
	cout << "----------------------"<< endl;
	cout << endl;
	do {
		// Displays the menu
		Menu_output(numberofrounds,numberofletters);
		cin >> choice;
		switch (choice) {
		case 1:
			cout << endl;
			cout << endl;
			cout << " Your highest score so far is " << highest_score << " points." << endl;
			cout << "        Let's change that!" << endl;
			cout << endl;
			Main_Game(numberofletters, numberofrounds,highest_score);
			break;

		case 2:
			char settingchoice;
			cout << " Choose a setting you want to change (a/b): ";
			do {
				cin >> settingchoice;
				if (settingchoice == 'a') {
					// Changes the number of letters
					NumberofLetters(numberofletters);
				}
				else if (settingchoice == 'b') {
					// Changes the number of rounds
					NumberofRounds(numberofrounds);
				}
				else {
					cout << " Incorrect choice" << endl;
					cout << " Choose a setting you want to change (a/b): ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} while (settingchoice != 'a' && settingchoice != 'b');

			break;

		case 3:
		{
	      string new_word;
		  cout << " Enter new word to the dictionary: ";
		  cin >> new_word;
		// Checks if the new word contains only letters
		  while(!isWord(new_word)) {
			  new_word.erase();
			  cout << " This is not a word." << endl;
			  cout << " Enter a valid new word to the dictionary: ";
			  cin >> new_word;
		  }
		// Adds a new word to the dictionary if it doesn't exist yet
		   AppendtoDictionary(new_word);
		}
			break;

		case 4: 
			cout << "\n Hope to see you again! :)" << endl;
		    break;

		case 5:
			cout << endl;
			cout << "      How to play: " << endl;
			cout << "- You will be given a combination of letters from which you should make a valid word." << endl;
			cout << "- If you can't make a word, during one of the rounds, enter '0' to see a possible word." << endl;
			cout << "  Then you will automatically refresh the round with another combination of letters." << endl;
			cout << "- If you want to return to the MENU during the game, enter 'M'." << endl;
			cout << "- At the end of the game your total points will be displayed. One point equals to one letter of your word each round." << endl;
			cout << "- Your highest score will be shown at the beginning of every game." << endl;
			cout << "  Have fun! :)" << endl;
			cout << endl;
			break;

		default:
			cout << endl;
			cout << " Incorrect choice." << endl;
			cout << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	} while (choice != 4);
	  return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
