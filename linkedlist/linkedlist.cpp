/*
Linked List: A linked list is a linear data structure where each element is a separate object, called a node. 
Each node contains data and a reference (or link) to the next node in the sequence. 
Unlike arrays, linked lists do not require contiguous memory allocation, allowing for efficient insertions and deletions.
Each node typically has two components:
1. Data: The value or information stored in the node.
2. Next Pointer: A reference to the next node in the list.
Types of Linked Lists:
1. Singly Linked List: Each node points to the next node in the sequence. Traversal is unidirectional.
2. Doubly Linked List: Each node contains two pointers, one pointing to the next node and another pointing to the previous node. This allows for bidirectional traversal.
3. Circular Linked List: In a circular linked list, the last node points back to the first node, forming a circle. This can be implemented as either a singly or doubly circular linked list.

How to represent a linked list in C++:
struct Node {
    int data; // Data part
    Node* next; // Pointer to the next node
    Node(int val) : data(val), next(nullptr) {} // Constructor
};
Algorithm to traverse a linked list:
1. Start from the head node.
2. While the current node is not null:
   a. Process the data of the current node (e.g., print it).
   b. Move to the next node by updating the current node to current->next.
3. End when the current node is null.

When implementing node  which would be better class or struct?
In C++, both classes and structs can be used to define a node for a linked list.
but there are some differences between the two:
1. Default Access Modifier:
    - Struct: Members are public by default.
    - Class: Members are private by default.
2. Usage Convention:
    - Structs are typically used for simple data structures that primarily hold data and have little to no behavior (methods).
    - Classes are used for more complex data structures that encapsulate both data and behavior.
3. Inheritance:
    - Both structs and classes support inheritance, but classes are more commonly used in object-oriented programming where inheritance and polymorphism are involved.
4. Semantic Meaning:
    - Using struct can signal to other programmers that the primary purpose of the type is to hold data.
    - Using class can indicate that the type has more complex behavior and encapsulation.
5. Performance:
    - There is no performance difference between structs and classes in C++. The choice between the two does not impact runtime performance.
*/

#include <iostream>
using namespace std;    

// Added: actual Node definition so it is available to functions below
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void traverseLinkedList(Node* head) {
    Node* current = head; // Start from the head node
    while (current != nullptr) { // Traverse until the end of the list
        cout << current->data << " "; // Process the data (print it)
        current = current->next; // Move to the next node
    }
}

int main() {
    // Creating a simple linked list: 1 -> 2 -> 3 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(7);
    head->next->next = new Node(3);

    //another way to declare nodes using for loop
    /*
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 1; i <= 3; ++i) {
        Node* newNode = new Node(i);
        if (head == nullptr) {
            head = newNode; // First node becomes the head
            tail = newNode; // First node is also the tail initially
        } else {
            tail->next = newNode; // Link the new node at the end of the list
            tail = newNode; // Update the tail to the new node
        }
    }
    */

    // Traversing the linked list
    traverseLinkedList(head);
    cout << '\n';

    // Freeing allocated memory
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}