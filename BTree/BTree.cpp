#include <iostream>
#include <vector>
#include <queue>

#include "BTree.h"

using namespace std;


// the Tree_Init function is to init the new tree
// and have a new tree root
void BTree::Tree_Init() {
	BTreeNode* rooti = new BTreeNode;
	vector<int> keys(M);
	vector<BTreeNode*> childs(M + 1);

	rooti->n = 0;
	rooti->keys = keys;
	rooti->ptrs = childs;

	for (int i = 0; i < M + 1; i++) {
		rooti->ptrs[i] = nullptr;
	}
	rooti->leaf = true;

	root = rooti;
}

// The function when creating a new node
BTreeNode* BTree::CreateNode() {
	BTreeNode* node = new BTreeNode;
	vector<int> keys(M);
	vector<BTreeNode*> childs(M + 1);

	node->n = 0;
	node->keys = keys;
	node->ptrs = childs;

	for (int i = 0; i < M + 1; i++) {
		node->ptrs[i] = nullptr;
	}
	node->leaf = true;

	return node;
}


// the Traverse function start from the root with order
void BTree::Traverse_byorder(BTreeNode* trv) {
	cout << endl;
	int i;
	for (i = 0; i < trv->n; i++) {
		if (trv->leaf == false) {
			Traverse_byorder(trv->ptrs[i]);
		}
		// cout << "layer" << layer<<" ";
		cout << trv->keys[i] << " ";
	}
	if (trv->leaf == false) {
		Traverse_byorder(trv->ptrs[i]);
	}
	cout << endl;

}

// Traverse the Tree from root with layer;
void BTree::Traverse_bylayer() {
	int layer = 0;
	queue<BTreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		int qsize = q.size();
		for (int node_i = 0; node_i < qsize; node_i++) {
			
			BTreeNode* temp = q.front();
			if (temp == nullptr) continue;
			q.pop();
			// first print keys
			cout << "layer: " << layer << endl;
			int j;
			for (j = 0; j < temp->n; j++) {
				cout << temp->keys[j] << " ";
				if (!temp->leaf) {
					q.push(temp->ptrs[j]);
				}
			}
			cout << endl;
			// add the subnode into q
			q.push(temp->ptrs[j]);
		}

		layer++;
	}
}

// Split the un-full Node x with the tree index c
void BTree::Split_Child(BTreeNode* x, int c) {
	BTreeNode* z = CreateNode();
	BTreeNode* fullT = x->ptrs[c];

	// start seting the node z
	z->leaf = fullT->leaf;
	z->n = t - 1;
	for (int i = 0; i < t - 1; i++) {
		z->keys[i] = fullT->keys[i+t];
	}
	if (!fullT->leaf) {
		// if not the leaf, moving the sub-nodes
		for (int i = 0; i < t; i++) {
			z->ptrs[i] = fullT->ptrs[i + t];
		}
	}

	// how should we modify the full T?
	// should we remove those?
	// NO! just modify the numbers;
	fullT->n = t - 1;

	for (int i = (x->n); i > c; i--) {
		// childs update
		x->ptrs[i + 1] = x->ptrs[i];
	}
	x->ptrs[c + 1] = z;

	for (int i = (x->n) - 1; i > c; i--) {
		// keys update
		x->keys[i + 1] = x->keys[i];
	}
	x->keys[c] = fullT->keys[t - 1];

	x->n = x->n + 1;
}

// Now is the function when insert a new key
// Start with the helper function 
void BTree::Insert_NONFULL(BTreeNode* r, int k) {
	int m = r->n;
	m--;
	if (r->leaf) {
		// it's a leaf
		while (m >= 0 && k < r->keys[m]) {
			r->keys[m + 1] = r->keys[m];  // shifting
			m--;
		}
		r->keys[m + 1] = k;
		r->n += 1;
	}
	else {
		while (m >= 0 && k < r->keys[m]) {
			m--;
		}
		m++;
		if (r->ptrs[m]->n == M) {
			Split_Child(r, m);

			if (k > r->keys[m]) {
				m++;
			}
		}
		Insert_NONFULL(r->ptrs[m], k);
	}
}

void BTree::Insert(int k) {
	BTreeNode* r = root;
	if (root->n == M) {
		// now root is full
		BTreeNode* s = CreateNode();
		root = s;
		s->leaf = false;
		s->n = 0;
		s->ptrs[0] = r;
		Split_Child(s, 0);
		Insert_NONFULL(s, k);
	}
	else {
		Insert_NONFULL(r, k);
	}
}
