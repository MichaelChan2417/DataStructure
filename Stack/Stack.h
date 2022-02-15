#pragma once
#include <string>

using namespace std;

struct Stack
{
	int stack_size;
	string space;
	
	// functions
	// default set of the stack
	Stack() : stack_size(), space(){}
	Stack(string x);
	
	void st_push(char x);
	char st_pop();
	char st_top();
	int len();
    void Print_Stack();
};
