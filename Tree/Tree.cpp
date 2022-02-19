#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "Tree.h"

using namespace std;

// the extend function used in vector
// to get a full written vector input for the tree
vector<string> Extend(vector<string>s) {
	vector<string> temp;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == "#" && i*2 + 1 < s.size()) {
			// the first part
			for (int j = 0; j < 2 * i + 1; j++) {
				temp.push_back(s[j]);
			}
			temp.push_back("#");
			temp.push_back("#");
			for (int j = 2 * i + 1; j < s.size(); j++) {
				temp.push_back(s[j]);
			}

			s = temp;
			temp = {};
		}
	}

	return s;
}

// the recursion function used to set up a tree;
void setTree(TreeNode* t, vector<string> b, int a) {
	// the next left child and right child indexes to be set
	int left = 2 * a + 1;
	int right = 2 * (a + 1);

	// now set the left tree node
	if (left > b.size() || b[left] == "#") {
		// now the left child is empty
		// do nothing just break;
		t->left = nullptr;
	}
	else {
		TreeNode* lefttemp = new TreeNode(stoi(b[left]));
		lefttemp->p = t;
		t->left = lefttemp;
		setTree(lefttemp, b, left);
	}

	// then set the right tree node
	if (right > b.size() || b[right] == "#") {
		t->right = nullptr;
	}
	else {
		TreeNode* righttemp = new TreeNode(stoi(b[right]));
		righttemp->p = t;
		t->right = righttemp;
		setTree(righttemp, b, right);
	}
}


// Construction Fuction
Tree::Tree(int x) {
	TreeNode* temp = new TreeNode(x);
	root = temp;
}

Tree::Tree(vector<string> s) {
	vector<string> b = Extend(s);
	TreeNode* t = new TreeNode(stoi(s[0]));
	root = t;

	setTree(t, b, 0);
}


void Tree::Insert(int a) {
	TreeNode* x = root;
	TreeNode* y = nullptr;

	while (x) {
		y = x;
		if (a < x->val) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}

	TreeNode* z = new TreeNode(a);
	z->p = y;

	if (y == nullptr) { // tree is empty
		root = z;
	}
	else if (a < y->val) {
		y->left = z;
	}
	else {
		y->right = z;
	}
}



// Print the Tree; Pre-Order-Traverse
vector<int> Tree::PreOrder() {
	vector<int> result;
	stack<const TreeNode*> s;
	if (root != nullptr) s.push(root);

	while (!s.empty()) {
		const TreeNode* p = s.top();
		s.pop();
		result.push_back(p->val);
		
		// since FILO, we need right to be first insert
		if (p->right != nullptr) s.push(p->right);
		if (p->left != nullptr) s.push(p->left);
	}

	return result;
}

// Return the Tree; In-Order-Traverse
vector<int> Tree::InOrder() {
	stack<const TreeNode* > stk;
	vector<int> result;

	const TreeNode* trv = root;

	while (!stk.empty() || trv != nullptr) {
		// the left condition
		if (trv != nullptr) {
			stk.push(trv);
			trv = trv->left;
		}
		// now it should be the right condition
		else {
			trv = stk.top();
			stk.pop();
			result.push_back(trv->val);
			trv = trv->right;
		}
	}
	
	return result;
}

// Return the Tree; Post-Order-Traverse
// left-right-root
vector<int> Tree::PostOrder() {
	vector<int> result;
	stack<const TreeNode*> stk;
	const TreeNode* p = root, *q = nullptr;

	do {
		// to the left bottom corner
		while (p != nullptr) {
			stk.push(p);
			p = p->left;
		}
		q = nullptr;

		while (!stk.empty()) {
			p = stk.top();
			stk.pop();

			// q is used to denote whether the right child
			// has been traversed or not.
			if (p->right == q) {
				result.push_back(p->val);
				q = p;
			}
			else {
				stk.push(p);
				p = p->right;
				break;
			}
		}

	} while (!stk.empty());

	return result;
}

