#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct SL_Node
{
    int val;
    SL_Node* next;

    // construction fucntion
    SL_Node() :val(), next() {}
    SL_Node(int x) :val(x), next(nullptr) {}

};

struct Linkedlist
{
    SL_Node* head;

    // construction function
    Linkedlist() :head() {}
    Linkedlist(SL_Node* t) :head(t) {}
    Linkedlist(int x);
    Linkedlist(vector<int> v);

    // other functions
    void Insert(int x);
    int DeleteNode(int x);

    void PrintList();
};
