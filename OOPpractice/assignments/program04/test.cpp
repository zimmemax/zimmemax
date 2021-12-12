#include "linkedlist.h"

int main()
{
    Linked_List max_is_cool;

    max_is_cool.push_front(1);
    max_is_cool.push_front(3);
    max_is_cool.push_front(4);
    max_is_cool.push_middle(2,2);
    max_is_cool.print(max_is_cool.get_head());
    
    Node* head = get_head();
    
    max_is_cool.merge_sort(&head);




    //max_is_cool.recursive_ascending_sort(max_is_cool.get_head());

    //max_is_cool.recursive_descending_sort(max_is_cool.get_head());
    //max_is_cool.print();


   // max_is_cool.print();
    
    //max_is_cool.clear();
}
