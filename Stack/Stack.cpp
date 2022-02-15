#include "Stack.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Constructor Function
Stack::Stack(string x) {
	stack_size = x.size();
    space = x;
}


// Push element into the stack
void Stack::st_push(char x) {
	stack_size++;
	space = space+x;
}


// Pop the top element out
char Stack::st_pop() {
	if (stack_size == 0) {
		cout << "Empty Stack, No pop Value" << endl;
		return '\0';
	}

	stack_size--;
    char ans = space[stack_size];
    space = space.substr(0,stack_size);

    return ans;
}


// Return the top value in the stack
char Stack::st_top() {
	if (stack_size == 0) {
		cout << "Empty Stack, No top Value" << endl;
		return '\0';
	}

	char ans = space[stack_size-1];
	return ans;
}


// the size of the stack
int Stack::len() {
	return stack_size;
}


// Print the Stack
void Stack::Print_Stack(){
    for(int i=0;i<space.size();i++){
        cout<<space[i]<<"-";
    }
    cout<<endl;
}

int main(){
    string temp = "12345";
    Stack st(temp);

    st.Print_Stack();
    char ad = st.st_pop();
    cout<<ad<<endl;
    st.Print_Stack();

    char ap = st.st_top();
    cout<<ap<<endl;
    st.Print_Stack();

    st.st_push('i');
    st.Print_Stack();
    
    system("pause");
    return 0;
}
