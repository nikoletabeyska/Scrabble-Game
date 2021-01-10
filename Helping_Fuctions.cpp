// Helping_Fuctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
*
* Solution to course project # 8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020 / 2021
*
* @author Nikoleta Beyska
* @idnumber 62540
* @compiler VC
*
* <file with helper functions>
*
*/

#include<iostream>
#include<iomanip>
#include<random>
#include<fstream>
#include<ctime>
#include<limits>
#include "Helping_Functions.h"
using namespace std;

void Menu_output(int numberofrounds, int numberofletters) {

	cout <<setw(10)<< "MENU" << endl;
	cout << " 1.Start a new game" << endl;
	cout << " 2.Settings" << endl;
	cout << " a.change the number of the given letters (" <<numberofletters<<")"<< endl;
	cout << " b.change the number of rounds (" << numberofrounds << ")" << endl;
	cout << " 3.Add a new word to the dictionary" << endl;
	cout << " 4.Exit" << endl;
	cout << " 5.Rules" << endl;
	cout << endl;
	cout << "--> Choose an option: ";
}

// Changes the number of letters
void NumberofLetters(int& numberofletters) {
	cout << " Enter the new number of letters: ";
	cin >> numberofletters;
	while (numberofletters <= 1) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " Not a possible setting." << endl;
		cout << " Enter the new number of letters: ";
		cin >> numberofletters;
	}
	cout << endl;
}

// Changes the number of rounds
void NumberofRounds(int& numberofrounds) {
	cout << " Enter the new number of rounds: ";
	cin >> numberofrounds;
	while (numberofrounds < 1) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " Not a possible setting." << endl;
		cout << " Enter the new number of letters: ";
		cin >> numberofrounds;
	}
	cout << endl;
}

// Generates random letters with at least 30% vowels and with a possible combination that equals a word
void GenerateRandomLetters(int& numberofletters, string& letters,string& existing_word) {
	char letter;
	int r;
	int numberofvowels;
	char Vowels[] = {'a','o','e','i','u','y'};
	// Continues if the number of vowels among the generated letters are less than 30 percent of them
	do {
		letters.erase();
	    numberofvowels = 0;
		for (int i = 1; i <= numberofletters; i++) {
			// Generates a random number with range 0-25 (english alphabet = 26)
			r = rand() % 26;
			// Converts the number to a letter from a-z
			letter = 'a' + r;
			// Adds the letter to the sequence of letters
			letters += letter;
		}
		// Counts the number of vowels in the generated letters
		for (int i = 0; i < numberofletters; i++) {
			int j = 0;
			while (Vowels[j] != '\0') {
				if (letters[i] == Vowels[j]) {
					numberofvowels++;
				}
				j++;
			}
		}
	} while (numberofvowels < int(0.3 * numberofletters));

	// If there can't be made a possible combination from the letters that equals a valid word, the function is called again
	if (!is_PossibleWord(letters,existing_word)) {
		letters.erase();
		GenerateRandomLetters(numberofletters, letters,existing_word);
	}

	// The letters are displayed
	else {
		for (int i = 0; i < numberofletters; i++) cout << letters[i] << " ";
	}
}

// Checks if a valid combination (word) of the generated letters exists
bool is_PossibleWord(string letters,string& existing_word) {
	// Line string to read from the dictionary file
	string line;
	// String to save the original letters 
	string initial_letters = letters;
	ifstream DictionaryFile;
	int counter = 0;
	DictionaryFile.open("Dictionary.txt", ios::in);
	// Checks if the file is open
	if (DictionaryFile.is_open()) {
		// Continues until there are lines in the file
		while (getline(DictionaryFile, line)) {
			counter = 0;
			// Counts how many of the generated letters are present in a word from the dictionary
			for (size_t i = 0; i < line.length(); i++) {
				for (size_t j = 0; j < letters.length(); j++) {
					if (line[i] == letters[j]) {
						counter++;
						// Erases the generated letter which is found in the word
						letters.erase(letters.begin() + j);
						// Breaks the second loop and continues with another letter from the word
						break;
					}
				}
			}
			/* When the word's length equals to the count of the generated letters found in it
			it indicates that there is a possible combination that the user can make from the letter sequence*/
			if (counter == line.length()) {
				existing_word = line;
				DictionaryFile.close();
				return 1;
			}
            // Erases the changed sequence
			letters.erase(); 
           // Turns back to the initial letters
			letters = initial_letters; 
		}
		
	}

	DictionaryFile.close();
	return 0;
}

// Checks if the word is valid
bool Word_Check(string letters, string word) {
	int counter = 0;
	// Checks if the word is longer than the count of the given letters
	if (word.length() > letters.length()) return 0;

    // Checks if there is a letter in the word which is not among the given letters
	for (size_t i = 0; i < word.length(); i++) {
		for (size_t j = 0; j < letters.length(); j++) {
			if (word[i] == letters[j]) {
				counter++;
				letters.erase(letters.begin() + j);
				break;
			}
		}
	}
	// Returns false if the number of the given letters present in the word are less than it's length
	if (counter != word.length()) {
		return 0;
	}
	// Returns false if the word isn't in the dictionary
	if (!Dictionary_Check(word)) {
		return 0;
	}
	return 1;
}

// Checks if the word is in the dictionary
bool Dictionary_Check(string word) {
	bool found = 0;
	string line;
	fstream DictionaryFile;
	// Opens without erasing the content of the file
	DictionaryFile.open("Dictionary.txt", ios::in);
	// Checks if the file is open
	if (DictionaryFile.is_open()) {
		// Continues until there are lines in the file
		while (getline(DictionaryFile, line)) {
			// If the word is found in the dictionary the loop breaks
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

// Displays the possible word
void ShowPossibleWord(string& word, string& letters,string existing_word ) {
	cout << endl;
	cout << "A possible word is: " << existing_word << endl;
	cout << endl;
	word.erase();
	letters.erase();
}

// Converts all uppercase letters in a word to lowercase letters
void ToLowerCase(string& line) {
	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] >= 'A' && line[i] <= 'Z') {
			line[i] = line[i] + ('a' - 'A');
		}
	}
}

// Checks if a string contains only letters
bool isWord(string word) {
	for (size_t i = 0; i < word.length(); i++) {
		if (word[i] < 'A' || word[i]>'z') {
			return 0;
		}
		if (word[i] > 'Z' && word[i] < 'a') {
			return 0;
		}
	}
	return 1;
}

// Adds a new word to the dictionary if it doesn't exist yet
void AppendtoDictionary(string new_word) {
	fstream Dictionaryfile;

	// Checks if the new word has uppercase letters and if yes, converts them to lowercase
	ToLowerCase(new_word);

	// Opens the dictionary file for appending
	Dictionaryfile.open("Dictionary.txt", ios::app);

	// Checks if the file is open
	if (Dictionaryfile.is_open()) {
		// Checks if the new word already exists in the Dictionary file
		if (!Dictionary_Check(new_word)) {
			// Adds the new word on a new line in the Dictionary text file 
			Dictionaryfile << endl << new_word;
			cout << " The new word was added.";
			cout << endl << endl;
		}
		else {
			Dictionaryfile.close();
			new_word.erase();
			cout << " This word already exists in the dictionary." << endl;
			cout << " If you want to return to MENU enter '1' else enter new word to the dictionary: ";
			cin >> new_word;
			// Calls the function again with the new word
			if (new_word != "1") {
				AppendtoDictionary(new_word);
			}
			else {
				cout << endl;
			}
		}
	}  
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
