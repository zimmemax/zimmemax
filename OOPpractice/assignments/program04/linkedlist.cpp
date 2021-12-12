#include "linkedlist.h"

#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

Linked_List::Linked_List()
{
    unsigned int length = 0;                
    Node *head = NULL;
}

Node* Linked_List::get_head()
{
    return head;
}

void Linked_List::clear()
{
    if(head == NULL)
    {
        cout << "empty list" << endl;
    }
    else
    {
        Node *temp = head;
        delete head;
        while(temp!=NULL)
        {
            temp = temp ->next;
            delete temp;
        }
    }
}

int Linked_List::get_length()
{
    Node *current = head;
    length = 0;

    while(current != NULL)
    {
        length++;
        current = current->next;
    }

    return length;
}

unsigned int Linked_List::push_front(int new_data)
{
    Node* new_node = new Node();
    new_node->val = new_data;
    //cout << "got to 2nd line" << endl;
    new_node->next = head; 
    //cout << "got to 3rd line" << endl;
    head = new_node;
    //cout << "got to 4th line" << endl;

    int new_length = get_length();

    int test = new_node->val;

    return new_length;
  
}

unsigned int Linked_List::push_back(int new_data)
{
    Node* new_node = new Node();

    new_node->val = new_data;

    if(head == NULL)
    {
        head = new_node;
        new_node->next=NULL;
    }
    else
    {
        Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->next = NULL;
    }



    int new_length = get_length();

    return new_length;
}

void Linked_List::print(Node* head_ref)
{
    cout << endl << "List: ";

    while(head_ref != NULL)
    {
        int test = head_ref ->val;
        cout << test << " ";
        head_ref = head_ref->next;
    }
    cout << endl << endl;
}

void Linked_List::operator = (const Linked_List* &L)
{
    
}

void Linked_List::swapNodes(Node** head_ref, Node* currX, Node* currY, Node* prevY)
{
    // make 'currY' as new head
    *head_ref = currY;
 
    // adjust links
    prevY->next = currX;
 
    // Swap next pointers
    struct Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}


unsigned int Linked_List::push_middle(int data, int position)
{
    Node* new_node = new Node();
    Node* previous_node;
    new_node->val = data;
    previous_node = get_head();
    int i = 0;

    while(i < position-2)
    {
        previous_node = previous_node->next;
        i++;
    }

    new_node->next = previous_node->next;
    previous_node->next = new_node;

    int new_length = get_length();
    return new_length;


}
void Linked_List::merge_sort(Node* a_node)
{
    Node* temp_head = a_node;
    Node* a = NULL;
    Node* b = NULL;
    

    if(temp_head == NULL || temp_head->next == NULL)
    {
        return;
    }
    else
    {
        partition(a,b,temp_head);
    }


    merge_sort(a);
    merge_sort(b);

    a_node = ascending_merge_lists(a,b);

}

Node* Linked_List::ascending_merge_lists(Node* a, Node* b)
{
    //final edited list we will be returning
    Node* merge_lists = NULL;

    if(a == NULL)
    {
        return b;
    }
    else if(b == NULL)
    {
        return a;
    }

    if(a->val <= b->val)
    {
        merge_lists = a;
        merge_lists->next = ascending_merge_lists(a->next,b);
    }
    else
    {
        merge_lists = b;
        merge_lists->next = (a, b->next);
    }

    return merge_lists;
    

}



void Linked_List::partition(Node* front, Node* back, Node* temp_head)
{
    Node* fast;
    Node* slow;

    if(temp_head == NULL || temp_head->next == NULL)
    {
        *front = *temp_head;
        back = NULL;
    }
    else
    {
        slow = temp_head;
        fast = temp_head->next;

        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        front = temp_head;
        back = slow->next;
        //derefrences pointer from back list, basically splits it in half
        slow->next = NULL;
        /*cout << "Front: ";
        print(front);
        cout << endl << "Back: ";
        print(back);
        cout << endl;*/
    }



}

#endif