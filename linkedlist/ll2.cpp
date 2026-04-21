/*
Q.Count the number of nodes linked list?

|1|pointer1| --> |3|pointer2| --> |4|pointer3| --> |5|pointer4| --> |6|NULL|
There are 5 nodes the approach would we to travel through the linked list and to increase the counter
 */


#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}  //This is a constructor to initialize a node with data
};

int countNodes(Node* head)
{
    int count = 0 ;
    Node* current = head;
    while(current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next =nullptr;

    cout<<countNodes(head);

    Node* current = head;
    while(current != nullptr)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    return 0;
}