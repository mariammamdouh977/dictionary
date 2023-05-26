#pragma once
#include "BinaryTree.h"
#include<string>

class Dictionary :public BinaryTree
{
public:

    string translateWord(const string& word);
	void displayDictionary(const string& filename);

};


