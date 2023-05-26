#pragma once
#include "BinaryTree.h"
#include<string>

class User : public BinaryTree
{
public:

	Node* addNode(Node* root, const string& word, const string& definition);
	Node* findMinNode(Node* node);
	Node* deleteNode(Node* root, const string& word);
	Node* modifyNode(Node* root, const string& word, const string& newDefinition);
	void user(Node*& root);
	void writeNodeToFile(Node* node, ofstream& file);
	void writeData(Node* root, const string& filename);
	void readData(Node*& root, const string& filename);

};