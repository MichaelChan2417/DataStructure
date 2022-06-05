#pragma once
#include <vector>

#define t 3
#define M 2*t-1

using namespace std;

struct BTreeNode {
	int n; // contains the number of keys in this node
	vector<int> keys;
	vector<BTreeNode*> ptrs;
	bool leaf;

	BTreeNode() : n(), keys(), leaf() {}
};

struct BTree {
	BTreeNode* root;

	// constructions
	BTree() : root() {}

	// functions
	void Tree_Init();
	BTreeNode* CreateNode();
	void Traverse_byorder(BTreeNode* root);
	void Traverse_bylayer();
	void Split_Child(BTreeNode* x, int c);
	void Insert(int k);
	void Insert_NONFULL(BTreeNode* r, int k);
};
