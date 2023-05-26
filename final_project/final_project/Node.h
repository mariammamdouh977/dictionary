#pragma once
#include <iostream>
#include <fstream>
#include<string>

using namespace std;

class Node
{
public:
	string word;
	string definition;
	Node* left;
	Node* right;

	// Default constructor
	Node() : left(nullptr), right(nullptr) {}
	Node(const string& w, const string& d)
		: word(w), definition(d), left(nullptr), right(nullptr) {}
};

