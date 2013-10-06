/**
 * @file BinTree.cpp
 */
#include <iostream>
#include <iomanip>
using namespace std;

template <typename KEY_T, typename VAL_T>
class BinTree
{
	struct Node {
		KEY_T key;
		VAL_T value;
		Node* left;
		Node* right;
		Node(const KEY_T& key) : key(key), left(NULL), right(NULL) {}
	};

public:
	explicit BinTree() { root_ = NULL; }
	virtual ~BinTree() {
		ClearRecursive(root_);
	}

	Node*& Append(KEY_T key, VAL_T value) {
		Node*& node = FindNode(root_, key);
		if (node == NULL) {
			node = new Node(key);
		}
		node->value = value;
		return node;
	}

	void Dump() const {
		DumpRecursive(root_);
	}

private:
	Node* root_;

	Node*& FindNode(Node*& node, KEY_T key) {
		if (node == NULL) return node;

		if (key < node->key) return FindNode(node->left, key);
		else if (node->key < key) return FindNode(node->right, key);
		else return node; // node->key == key 
	}

	void ClearRecursive(const Node* node) {
		if (node == NULL) return;
		
		if (node->left != NULL) ClearRecursive(node->left);
		if (node->right != NULL) ClearRecursive(node->right);
		cout << "delete : " << node->key << endl;
		delete node;
	}

	void DumpRecursive(const Node* node, int depth = 0) const {
		if (node == NULL) return;
		cout << setw(depth*4) << " "
			 << node->key << "(" << node->value << ")" << endl;

		if (node->left != NULL) DumpRecursive(node->left, depth + 1);
		if (node->right != NULL) DumpRecursive(node->right, depth + 1);
	}
};


int main() {
	BinTree<string, int> yankees;

	yankees.Append("Ichiro", 31);
	yankees.Append("Jeter", 2);
	yankees.Append("Cano", 24);
	yankees.Append("Teixeira", 25);
	yankees.Append("Granderson", 14);
	yankees.Append("Nix", 17);
	yankees.Append("Chavez", 12);
	yankees.Append("A.Jones", 22);
	yankees.Append("Martin", 55);

	yankees.Dump();

	return 0;
}
