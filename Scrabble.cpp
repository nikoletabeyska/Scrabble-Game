// Scrabble.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
#include "Helping_Functions.h"
using namespace std;

void Main_Game(int& numberofletters, int& numberofrounds) {
	string word;
	string letters;
	string existing_word;
	bool fail = 0;
	int failed_round = 0;
	int points = 0;
	cout << endl;
	
	cout << endl;
	for (int i = 1; i <= numberofrounds; i++) {
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
		if (word[0] == '0') {
			cout << endl;
			cout << "A possible word is: " << existing_word << endl;
			cout << endl;
			fail = 1;
			failed_round = i;
			word.erase();
			letters.erase();
			continue;
		}
		while (!Word_Check(letters, word)) {
			word.erase();
			cout << " Invalid word. Try again with: ";
			for (int i = 0; i < letters.length(); i++) cout << letters[i] << " ";
			cout << endl;
			cout << " Enter your word: ";
			cin >> word;
			if (word[0] == '0') {
				cout << endl;
				cout << "A possible word is: " << existing_word << endl;
				cout << endl;
				fail = 1;
				failed_round = i;
				word.erase();
				letters.erase(); break;
				//continue;
			}
		}
		if (fail) continue;
		points += word.length();
		if(i!=numberofrounds)cout << " Your points so far are: " << points << endl;
		letters.erase();
		cout << endl;
	}
	cout << endl;
	cout << "--->";
	cout << "Your total points are: " << points<<endl;
	cout << endl;
	cout << " *Returning to MENU*" << endl;
	cout << endl;

}
int main()
{
	int choice = 0;
	int numberofletters = 10;
	int numberofrounds = 10;
	do {
		cout << "       SCRABBLE" << endl;
		cout << endl;
		cout << "      How to play: " << endl;
		cout << "*You will be given a combination of letters from which you should make an existing word." << endl;
		cout << "*If you can't make a word, during one of the rounds, enter '0' to see a possible word." << endl;
	    cout<<"Then you will be automatically returned to Round 1." << endl;
		cout << "*If you want to return to the MENU during the game, enter 'M'." << endl;
		cout << endl;
		Menu_output();
		cin >> choice;
		switch (choice) {
		case 1:
			
			Main_Game(numberofletters, numberofrounds);
			break;

		case 2:
			char settingchoice;
			cout << " Choose a setting you want to change (a/b): ";
			do {
				cin >> settingchoice;
				if (settingchoice == 'a') {
					NumberofLetters(numberofletters);
				}
				else if (settingchoice == 'b') {
					NumberofRounds(numberofrounds);
				}
				else {
					cout << " Incorrect choice" << endl;
					cout << " Choose a setting you want to change (a/b): ";
				}
			} while (settingchoice != 'a' && settingchoice != 'b');

			break;

		case 3:
		{
	    string new_word;
		cout << " Enter new word to the dictionary: ";
		cin >> new_word;
		AppendtoDictionary(new_word);
		}
			break;

		case 4: 
			cout << "\n Hope to see you again! :)" << endl;
		    break;
		default:
			cout << endl;
			cout << " Incorrect choice." << endl;
			cout << endl;
		
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
