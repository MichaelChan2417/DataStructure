#include <string>
#include <iostream>
#include "Queue.h"

using namespace std;

// construction function
Queue::Queue(string a) {
	buf = a;
	Q_size = a.size();
}


// Enqueue
void Queue::Enqueue(char a) {
	buf += a;
	Q_size++;
}

// Dequeue
char Queue::Dequeue() {
	if (Q_size == 0) {
		cout << "Empty Queue, Returning Space" << endl;
		return ' ';
	}
	char ans = buf[0];
	buf = buf.substr(1);
	Q_size--;
	return ans;
}

// len
int Queue::len() {
	return Q_size;
}

// Print Queue
void Queue::Print_Queue() {
	if (!Q_size) {
		cout << "Empty Queue!" << endl;
	}
	else {
		for (auto i = buf.begin(); i < buf.end(); i++) {
			cout << *i << "-";
		}
		cout << endl;
	}
}
