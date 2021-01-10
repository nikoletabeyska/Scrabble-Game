#ifndef Helping_Functions
#include<string>
void Menu_output(int numberofrounds,int numberofletters);
void NumberofLetters(int& numberofletters);
void NumberofRounds(int& numberofrounds);
void GenerateRandomLetters(int& numberofletters, std::string& letters,std::string& existing_word);
bool is_PossibleWord(std::string letters, std::string& existing_word);
void ShowPossibleWord(std::string& word, std::string& letters, std::string existing_word);
bool Word_Check(std::string letters, std::string word);
bool Dictionary_Check(std::string word);
void ToLowerCase(std::string& line);
bool isWord(std::string word);
void AppendtoDictionary(std::string new_word);
#endif