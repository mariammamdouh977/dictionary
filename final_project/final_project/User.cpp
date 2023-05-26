#include "User.h"
#include "BinaryTree.h"

Node* User::addNode(Node* root, const string& word, const string& definition) 
{
	if (root == nullptr) 
	{
		root = new Node(word, definition);
	}
	else if (word < root->word)
	{
		root->left = addNode(root->left, word, definition);
	}
	else if (word > root->word) 
	{
		root->right = addNode(root->right, word, definition);
	}
	else 
	{
		cout << "the word already exist";
	}
	return root;
}

void User::user(Node*& root) 
{
	string word, definition;
	cout << "Enter the word: ";
	getline(cin, word);
	cout << "Enter the definition: ";
	getline(cin, definition);
	root = addNode(root, word, definition);
}

void User::readData(Node*& root, const string& filename)
{
	ifstream file(filename);
	if (!file) 
	{
		cout << "File not found: " << filename << endl;
		return;
	}
	string word, definition;
	while (file >> word && getline(file, definition))
	{
		definition = definition.substr(1);
		root = addNode(root, word, definition);
	}
	file.close();
}

Node* User::findMinNode(Node* node) 
{
	if (node == nullptr)
		return nullptr;
	while (node->left != nullptr)
		node = node->left;
	return node;
}

Node* User::deleteNode(Node* root, const string& word)
{
	if (root == nullptr)
		return nullptr;
	if (word < root->word)
	{
		root->left = deleteNode(root->left, word);
	}
	else if (word > root->word)
	{
		root->right = deleteNode(root->right, word);
	}
	// word will deleted is root
	else 
	{
		if (root->left == nullptr && root->right == nullptr)
		{
			delete root;
			root = nullptr;
		}
		else if (root->left == nullptr) 
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == nullptr) 
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		else 
		{
			Node* minRight = findMinNode(root->right);
			root->word = minRight->word;
			root->definition = minRight->definition;
			root->right = deleteNode(root->right, minRight->word);
		}
	}
	return root;
}

Node* User::modifyNode(Node* root, const string& word, const string& newDefinition) {
	if (root == nullptr)
		return nullptr;

	if (word < root->word) 
	{
		root->left = modifyNode(root->left, word, newDefinition);
	}
	else if (word > root->word)
	{
		root->right = modifyNode(root->right, word, newDefinition);
	}
	else
	{
		root->definition = newDefinition;
	}
	return root;
}

void User::writeNodeToFile(Node* node, ofstream& file) 
{
	if (node == nullptr)
		return;
	file << node->word << " " << node->definition << endl;
	writeNodeToFile(node->left, file);
	writeNodeToFile(node->right, file);
}

void User::writeData(Node* root, const string& filename) 
{
	ofstream file(filename);
	if (!file)
	{
		cout << "Error opening file for writing: " << filename << endl;
		return;
	}
	writeNodeToFile(root, file);
	file.close();
}