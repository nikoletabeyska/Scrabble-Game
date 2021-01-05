// Helping_Fuctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<iomanip>
#include<random>
#include<fstream>
#include<ctime>
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
	srand(time(NULL)); //initializes the random number generator
	for (int i = 1; i <= numberofletters; i++) {
		r = rand() % 26;// generats a random number
		letter = 'a' + r; // converts the number to a letter from a-z
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
//checks if the word is in the dictionary
bool Dictionary_Check(string word) {

	bool found = 0;
	string line;
	//input file stream
	ifstream DictionaryFile;
	//opens without erasing the content of the file
	DictionaryFile.open("Dictionary.txt", ios::in);
	//checks if the file  is open
	if (DictionaryFile.is_open())
	{
		while (getline(DictionaryFile, line))
		{       
			if(line==word) {
			  found = 1;
				break;
			}
		}

	}
	DictionaryFile.close();
	if (found) return 1;
	return 0;
}
void AppendtoDictionary(string new_word) {
	//output file stream
	ofstream Dictionaryfile;
	//opens the file for appending
	Dictionaryfile.open("Dictionary.txt", ios::app);
	//checking if the file is open
	if (Dictionaryfile.is_open()) {
		//checks if the new word already exists in the Dictionary file
		if (!Dictionary_Check(new_word)) {
			//adding the new word on a new line in the Dictionary text file 
			Dictionaryfile << endl << new_word;
			cout << "The new word was added.";
			cout << endl << endl;
		}
		else {
			//closing the file
			Dictionaryfile.close();
			//erasing the string
			new_word.erase();
			cout << "This word already exists in the dictionary." << endl;
			cout << "If you want to return to MENU enter '1' else enter new word to the dictionary: ";
			cin >> new_word;
			//calling the function again with the new word
			if (new_word != "1")AppendtoDictionary(new_word);
		}
	}   //closing the file
		Dictionaryfile.close();
	
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
