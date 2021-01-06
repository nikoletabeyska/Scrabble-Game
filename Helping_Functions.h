#ifndef Helping_Functions
#include<string>
void Menu_output();
void GenerateRandomLetters(int& numberofletters, std::string& letters);
void NumberofLetters(int& numberofletters);
void NumberofRounds(int& numberofrounds);
bool Word_Check(std::string letters, std::string word);
void ToLowerCase(std::string& line);
bool Dictionary_Check(std::string word);
void AppendtoDictionary(std::string new_word);
#endif