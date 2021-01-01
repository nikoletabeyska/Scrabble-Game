// Helping_Fuctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<iomanip>
#include<random>
#include<fstream>
#include "Helping_Functions.h"
using namespace std;
void Menu_output() {
	cout << setw(10) << "MENU" << endl;
	cout << "1.Start a new game" << endl;
	cout << "2.Settings" << endl;
	cout << setw(4) << "a.change the number of the given letters (10)" << endl;
	cout << setw(4) << "b.change the number of rounds (10)" << endl;
	cout << "3.Add a new word" << endl;
	cout << "4.Exit" << endl;
	cout << endl;
	cout << "Choose an option: ";
}
void GenerateRandomLetters(int& numberofletters, string& letters) {
	char letter;
	int r;
	for (int i = 1; i <= numberofletters; i++) {
		r = rand() % 26;
		letter = 'a' + r;
		letters += letter;
		cout << letter << " ";
	}
}
void NumberofLetters(int& numberofletters) {
	cout << "Enter the number of letters: ";
	cin >> numberofletters;
}
void NumberofRounds(int& numberofrounds) {
	cout << "Enter the number of rounds: ";
	cin >> numberofrounds;
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
