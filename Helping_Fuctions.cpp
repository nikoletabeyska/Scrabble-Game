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
bool Word_Check(string letters, string word) {
	//checks if the word is longer than the count of the given letters
	if (word.length() > letters.length()) return 0;
	//checks if there is a letter in the word which is not in the given letters
	int counter = 0;
	for (int i = 0; i < word.length(); i++) {
		for (int j = 0; j < letters.length(); j++) {
			if (word[i] == letters[j]) {
				counter++;
				letters.erase(letters.begin() + j);
				break;
			}
		}
	}
	if (counter != word.length()) return 0;
	if (!Dictionary_Check(word)) return 0;
	return 1;
}


bool Dictionary_Check(string word) {

	//checks if the word is in the dictionary
	int offset = 0;
	bool found = 0;
	string line;
	ifstream DictionaryFile;
	DictionaryFile.open("Dictionary.txt", ios::in);

	if (DictionaryFile.is_open())
	{
		while (!DictionaryFile.eof())
		{
			getline(DictionaryFile, line);
			if ((offset = line.find(word, 0)) != string::npos)
			{
				found = 1;
				DictionaryFile.close();
				break;
			}
		}

	}
	DictionaryFile.close();
	if (found) return 1;
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
