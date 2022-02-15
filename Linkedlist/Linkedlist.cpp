#include <iostream>
#include <vector>
#include <string>

#include "Linkedlist.h"

using namespace std;

// construction function
Linkedlist::Linkedlist(int x) {
    SL_Node* temp = new SL_Node(x);
    head = temp;
}

Linkedlist::Linkedlist(vector<int> v) {
    SL_Node dummy(-1);

    SL_Node* trv = &dummy;
    for (int i = 0; i < v.size(); i++) {
        SL_Node* temp = new SL_Node();
        temp->val = v[i];
        trv->next = temp;
        trv = trv->next;
    }
    head = dummy.next;
}



// Insert function
void Linkedlist::Insert(int x) {
    // if the linked-list is empty
    if (head == nullptr) {
        SL_Node* temp = new SL_Node(x);
        head = temp;
    }
    else {
        SL_Node dummy(-1);
        dummy.next = head;

        SL_Node* trv = &dummy;
        while (trv->next) {
            trv = trv->next;
        }
        SL_Node* temp = new SL_Node(x);
        trv->next = temp;
    }
}


// Delete the Node; if successful return 1; else return -1
int Linkedlist::DeleteNode(int x) {
    // if the linked-list is empty
    if (head == nullptr) {
        cout << "Empty Linked List!" << endl;
        return -1;
    }
    else {
        SL_Node dummy(-1);
        dummy.next = head;
        auto trv = &dummy;
        auto next = trv->next;

        while (next) {
            if (next->val == x) {
                trv->next = next->next;
                return 1;
            }
            trv = next;
            next = trv->next;
        }

        // now we cannot find the element
        cout << "Cannot Find the Element" << endl;
        return -1;
    }
}


// Print the List
void Linkedlist::PrintList() {
    if (head == nullptr) {
        cout << "Empty List!" << endl;
    }
    else {
        SL_Node dummy(-1);
        dummy.next = head;
        while (head) {
            cout << head->val << "->";
            head = head->next;
        }
        cout << endl;
        head = dummy.next;
    }
}

