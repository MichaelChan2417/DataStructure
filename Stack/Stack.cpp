#include "Stack.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Constructor Function
Stack::Stack(string x) {
	stack_size = 1;
	space.push_back(x);
}

Stack::Stack(vector<string> s) {
	stack_size = s.size();
	for (int i = 0; i < s.size(); i++) {
		space.push_back(s[i]);
	}
}


// Push element into the stack
void Stack::st_push(string x) {
	stack_size++;
	space.push_back(x);
}


// Pop the top element out
string Stack::st_pop() {
	if (stack_size == 0) {
		cout << "Empty Stack, No pop Value" << endl;
		return "-1";
	}

	stack_size--;
	string ans = space.back();
	space.pop_back();
	return ans;
}


// Return the top value in the stack
string Stack::st_top() {
	if (stack_size == 0) {
		cout << "Empty Stack, No top Value" << endl;
		return "-1";
	}

	string ans = space.back();
	return ans;
}


// the size of the stack
int Stack::len() {
	return stack_size;
}
