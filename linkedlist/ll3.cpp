/*
Q.Find the middle node of the linkedlist
|3|pointer1| --> |2|pointer2| --> |1|pointer3| --> |7|pointer4| --> |9|NULL|

Ans: The middle node will be 1

Note on even-length lists:
If the linked list has an even number of nodes, there are two common conventions for choosing the "middle" node:
1. Return the first of the two middle nodes (e.g., for 1->2->3->4, return 2).
2. Return the second of the two middle nodes (e.g., for 1->2->3->4, return 3).

Approach 1: (Two Pointer/Fast and Slow Pointer Method)
Step 1: Traverse through the list and count the number of nodes
Step 2: Calculate the middle node using the formula key=count/2 
Step 3: Traverse the list again till the node key==data

*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;
    Node(int val): data(val),next(nullptr) {}
};

Node* find_middle(Node* head){
    int count = 0;
    Node* current = head;
    
    // Count total nodes
    while(current != nullptr)
    {
        count++;
        current = current->next;
    }
    
    // Calculate middle position
    int middle_pos = count / 2;
    
    // Traverse to the middle node
    current = head;
    for(int i = 0; i < middle_pos; i++)
    {
        current = current->next;
    }
    
    return current;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(5);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);

    Node* middle_node = find_middle(head);
    cout<<middle_node->data<<endl;

    Node* current = head;
    while(current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    
    return 0;
}
