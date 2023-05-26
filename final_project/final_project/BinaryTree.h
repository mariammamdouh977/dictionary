#pragma once
#include "Node.h"
#include<string>
class BinaryTree : public Node
{
public:
	Node* root;

	// Default constructor
	BinaryTree() : root(nullptr) {}

	string searchNode(Node* node, const string& word);
	string searchWordFromFile(const string& word, const string& filename);
	string searchWord(const string& word);
	int countWordsFromFile(const string& filename);
	void displayAscending(Node* node);
	void displayDescending(Node* node);

};
