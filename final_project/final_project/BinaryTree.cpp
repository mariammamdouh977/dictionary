#include "BinaryTree.h"
#include "Node.h"
#include "Dictionary.h"
using namespace std;

Node* root;

string BinaryTree::searchWordFromFile(const string& word, const string& filename) 
{
	ifstream file(filename);

	if (!file) {
		cout << "File not found: " << filename << endl;
		return "Word not found";
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
				return "Definition is not found";
			}
		}
	}
	file.close();
	return "Word not found";
}

string BinaryTree::searchNode(Node* node, const string& word) 
{
	if (node == nullptr)
		return "Word not found";

	else if (node->word == word)
		return node->definition;

	else if (word < node->word)
		return searchNode(node->left, word);

	else
		return searchNode(node->right, word);
}

string BinaryTree::searchWord(const string& word)
{
	string result = searchNode(root, word);
	if (result == "Word not found") 
	{
		result = searchWordFromFile(word, "dictionary.txt");
		if (result == "Word not found")
			result = "Word not found in both files";
	}
	return result;
}

int BinaryTree::countWordsFromFile(const string& filename) 
{
	ifstream file(filename);
	if (!file)
	{
		cout << "File not found: " << filename << endl;
		return 0;
	}
	int count = 0;
	string line;
	while (getline(file, line))
	{
		if (!line.empty()) 
		{
			count++;
		}
	}
	count /= 1; //num of words == num of line
	file.close();
	return count;
}

void BinaryTree::displayAscending(Node* node)
{
	if (node == nullptr)
		return;

	displayAscending(node->left);
	cout << "Word: " << node->word << endl;
	cout << "Definition: " << node->definition << endl;

	displayAscending(node->right);
}

void BinaryTree::displayDescending(Node* node) {
	if (node == nullptr)
		return;

	displayDescending(node->right);
	cout << "Word: " << node->word << endl;
	cout << "Definition: " << node->definition << endl;

	displayDescending(node->left);

}



