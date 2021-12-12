#include <iostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;


class Node {
public:
   int val;             // the value that this node stores
   Node *next;          // a pointer to the next node in the list
};
class Linked_List {
private:
   unsigned int length;                 // the number of nodes contained in the list
   Node *head;                          // a pointer to the first node in the list

public:
   Linked_List();
   int get_length();
   void print(Node*);                        // output a list of all integers contained within the list
   void clear();
   Node* get_head();                        // delete the entire list (remove all nodes and reset length to 0)
   unsigned int push_front(int);  
   unsigned int push_middle(int, int);      // insert a new value at the front of the list (returns the new length of the list)
   unsigned int push_back(int);
   void partition(Node*,Node*,Node*);
   void operator = (const Linked_List* &L);
   void merge_sort(Node*);
   Node* ascending_merge_lists(Node*, Node*);
   Node* descending_merge(Node*, Node*);  
   void swapNodes(Node** head_ref, Node* currX, Node* currY, Node* prevY);     // insert a new value at the back of the list (returns the new length of the list)
};


#endif