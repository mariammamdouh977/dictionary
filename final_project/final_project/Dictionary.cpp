#include "Dictionary.h"
#include "BinaryTree.h"

string Dictionary::translateWord(const string& word) 
{
	ifstream file("translations.txt");
	if (!file)
	{
		cout << "File not found: translations.txt" << endl;
		return "Translation not found";
	}
	string line;
	while (getline(file, line))
	{
		string storedWord = line;
		if (storedWord == word)
		{
			if (getline(file, line))
			{
				file.close();
				return line;
			}
			else
			{
				file.close();
				return "Translation not found";
			}
		}
	}
	file.close();
	return "Translation not found";
}

void Dictionary::displayDictionary(const string& filename)
{
	ifstream file(filename);
	if (!file) 
	{
		cout << "File not found: " << filename << endl;
		return;
	}

	string word;
	string definition;

	while (getline(file, word)) 
	{
		if (!getline(file, definition)) 
		{
			// Skip words without a definition
			continue;
		}
		cout << "Word: " << word << endl;
		cout << "Definition: " << definition << endl;
		cout << endl;
	}
	file.close();
}