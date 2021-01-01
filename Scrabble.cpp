// Scrabble.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
#include<random>
#include "Helping_Functions.h"
using namespace std;

void Main_Game(int& numberofletters, int& numberofrounds) {
	string word;
	string letters;
	cout << endl;
	for (int i = 1; i <= numberofrounds; i++) {
		cout << setw(10) << "Round " << i << endl;
		cout << "Available letters: ";
		GenerateRandomLetters(numberofletters, letters);
		cout << endl;
		cout << "Enter your word: ";
		cin >> word;
		letters.erase();
	}
	cout << endl;
	cout << "Returning to MENU" << endl;

}
int main()
{
	int score = 0;
	int choice = 0;
	int numberofletters = 10;
	int numberofrounds = 10;
	do {
		Menu_output();
		cin >> choice;
		switch (choice) {
		case 1:
			Main_Game(numberofletters, numberofrounds);
			break;

		case 2:
			char settingchoice;
			cout << "Choose a setting you want to change: ";
			do {
				cin >> settingchoice;
				if (settingchoice == 'a') {
					NumberofLetters(numberofletters);
				}
				else if (settingchoice == 'b') {
					NumberofRounds(numberofrounds);
				}
				else {
					cout << "Incorrect choice" << endl;
					cout << "Choose again: ";
				}
			} while (settingchoice != 'a' && settingchoice != 'b');

			break;

		case 3:
		case 4:
		default:
			cout << "Incorrect choice" << endl;
			cout << "Choose again: ";
		}
	} while (choice != 4);

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
