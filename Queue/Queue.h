#pragma once
#include <string>

using namespace std;

struct Queue 
{
	int Q_size;
	string buf;

	// functions
	Queue() : Q_size(), buf(){}

	Queue(string a);

	void Enqueue(char a);
	char Dequeue();
	int len();
	void Print_Queue();
};
