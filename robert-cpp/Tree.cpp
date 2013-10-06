/**
 * @file Tree.cpp
 */
#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

template <typename T>
class Tree
{
public:
	struct Node {
		T value;
		list<Node*> children;
		Node(const T& value) : value(value) {};
	};

	explicit Tree(const T& value) {
		root_ = new Node(value);
	}
	virtual ~Tree() {
		ClearRecursive(root_);
		cout << "delete : " << root_->value << endl;
		delete root_;
	}
	Node* GetRoot() const {
		return root_;
	}
	static Node* Append(Node *node, const T& value) {
		Node* child = new Node(value);
		node->children.push_back(child);
		return child;
	}
	void Dump() const {
		DumpRecursive(root_);
	}

private:
	Node* root_;

	void ClearRecursive(Node* node) {
		list<Node*>& children = node->children;
		typename list<Node*>::iterator itr = children.begin();
		for (; itr != children.end(); ++itr) {
			ClearRecursive(*itr);
		}
		children.clear(); // リスト内の全ての要素を削除

		// root nodeはdeleteしない
		if (node != root_) {
			cout << "delete : " << node->value << endl;
			delete node;
		}
	}

	void DumpRecursive(Node *node, int depth = 0) const {
		cout << setw(depth*4) << " " << node->value << endl;

		list<Node*>& children = node->children;
		typename list<Node*>::iterator itr = children.begin();
		for (; itr != children.end(); ++itr) {
			DumpRecursive(*itr, depth + 1);
		}
	}
};


int main() {
	Tree<string> tree("foo");

	Tree<string>::Node* foo = tree.GetRoot();
	Tree<string>::Node* bar = tree.Append(foo, "bar");
	Tree<string>::Node* baz = tree.Append(foo, "baz");

	tree.Append(bar, "bar.hpp");
	tree.Append(bar, "bar.cpp");

	tree.Append(baz, "baz.hpp");
	tree.Append(baz, "baz.cpp");

	tree.Append(foo, "README");

	tree.Dump();

	return 0;
}
