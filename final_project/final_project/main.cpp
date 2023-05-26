#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "BinaryTree.h"
#include "Dictionary.h"
#include "User.h"
using namespace std;
int main()
{
	BinaryTree binaryTree;
	User user;
	Dictionary dictionary;
	binaryTree.root = nullptr;
	user.readData(binaryTree.root, "user.txt");

	while (true) 
	{
		cout << "\n Dictionary Menu " << endl;
		cout << "1. To Manage Your Own Words" << endl;
		cout << "2. Dictionary" << endl;
		cout << "3. Exit" << endl;

		int choice;
		cout << "Enter your choice (1-3): ";
		cin >> choice;
		cin.ignore(); // Ignore the newline character

		switch (choice) 
		{
		case 1:
		{
			while (true)
			{
				cout << "\n* Word Operations *" << endl;
				cout << "1. Add word" << endl;
				cout << "2. Delete word" << endl;
				cout << "3. Modify word" << endl;
				cout << "4. Count your words" << endl;
				cout << "5. Search word" << endl;
				cout << "6. Display all your words in ascending order" << endl;
				cout << "7. Display all your words in descending order" << endl;
				cout << "8. Back to dictionary Menu" << endl;
				cout << "Enter your choice (1-8): ";
				cin >> choice;
				cin.ignore();

				switch (choice)
				{
				case 1:
					user.user(binaryTree.root);
					user.writeData(binaryTree.root, "user.txt");
					cout << "Word added successfully." << endl;
					break;
				case 2:
				{
					string wordToDelete;
					cout << "Enter the word to delete: ";
					getline(cin, wordToDelete);
					binaryTree.root = user.deleteNode(binaryTree.root, wordToDelete);
					user.writeData(binaryTree.root, "user.txt");
					cout << "Word deleted successfully." << endl;
					break;
				}
				case 3:
				{
					string wordToModify;
					cout << "Enter the word to modify: ";
					getline(cin, wordToModify);
					string newDefinition;
					cout << "Enter the new definition: ";
					getline(cin, newDefinition);
					binaryTree.root = user.modifyNode(binaryTree.root, wordToModify, newDefinition);
					user.writeData(binaryTree.root, "user.txt");
					cout << "Word modified successfully." << endl;
					break;
				}
				case 4: 
				{
					int count = binaryTree.countWordsFromFile("user.txt");
					cout << "Total words in 'user.txt' file: " << count << endl;
					break;
				}
				case 5:
				{
					string wordToSearch;
					cout << "Enter the word to search: ";
					getline(cin, wordToSearch);
					string definition = binaryTree.searchWord(wordToSearch);
					cout << "Definition: " << definition << endl;
					break;
				}
				case 6:
					cout << "*** Words in ascending order ***" << endl;
					binaryTree.displayAscending(binaryTree.root);
					break;
				case 7:
					cout << "*** Words in descending order ***" << endl;
					binaryTree.displayDescending(binaryTree.root);
					break;
				case 8:
					cout << "Exiting User Word Operations." << endl;
					break;
				default:
					cout << "Invalid choice. Please try again." << endl;
				}

				if (choice == 8)
					break;
			}
			break;
		}
		case 2: 
		{
			while (true) 
			{
				cout << "\n Dictionary " << endl;
				cout << "1. Search word" << endl;
				cout << "2. Translate word" << endl;
				cout << "3. Display All Words In Dictionary" << endl;
				cout << "4. Count words in 'dictionary.txt' file" << endl;
				cout << "5.Back to dictionary Menu " << endl;
				cout << "Enter your choice (1-5): ";
				cin >> choice;
				cin.ignore();

				switch (choice)
				{
				case 1:
				{
					string wordToSearch;
					cout << "Enter the word to search: ";
					getline(cin, wordToSearch);
					string definition = binaryTree.searchWord(wordToSearch);
					cout << "Definition: " << definition << endl;
					break;
				}
				case 2:
				{
					string wordToTranslate;
					cout << "Enter the word to translate: ";
					getline(cin, wordToTranslate);
					string translation = dictionary.translateWord(wordToTranslate);
					cout << "Translation: " << translation << endl;
					break;
				}
				case 3:
					dictionary.displayDictionary("dictionary.txt");
					break;

				case 4: 
				{
					int count = binaryTree.countWordsFromFile("dictionary.txt");
					cout << "Total words in 'dictionary.txt' file: " << count / 2 << endl;
					break;
				}
				case 5:
					cout << "Exiting Dictionary Operations." << endl;
					break;
				default:
					cout << "Invalid choice. Please try again." << endl;
				}

				if (choice == 5)
					break;
			}
			break;
		}
		case 3:
			cout << "Exiting the program. Goodbye!" << endl;
			return 0;

		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	}
	return 0;
}


