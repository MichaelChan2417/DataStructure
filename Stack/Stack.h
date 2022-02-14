#pragma once
#include <vector>
#include <string>

using namespace std;

struct Stack
{
	int stack_size;
	vector<string> space;
	
	// functions
	// default set of the stack
	Stack() : stack_size(), space(){}
	Stack(string x){}
	Stack(vector<string> s){}
	
	void st_push(string x);
	string st_pop();
	string st_top();
	int len();

};
