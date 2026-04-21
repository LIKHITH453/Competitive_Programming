/*
Queue is a linear data structure that follows the First In First Out (FIFO) principle.
It is non-homogeneous and allows insertion and deletion of elements of any data type.
Elements are added at the back (enqueue) and removed from the front (dequeue).
the time complexity for both enqueue and dequeue operations is O(1).
This example demonstrates a simple implementation of a queue using C++ STL.


The result of the program will be:

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Output: 10
    cout << "Back element: " << q.back() << endl;   // Output: 30

    // Dequeue elements
    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 20

    cout << "Queue size: " << q.size() << endl; // Output: 2

    return 0;
}
    
The output of the program will be:
Front element: 10
Back element: 30
Front element after pop: 20
Queue size: 2

If we take a right and left look at a queue, we can visualize it as follows:
Front [10, 20, 30] Back
When we push an element, it goes to the back:
Front [10, 20, 30, 40] Back
When we pop an element, it is removed from the front:
Front [20, 30, 40] Back


Now there is an advanced version of queue called Deque (Double Ended Queue) which allows insertion and deletion of elements from both ends.
The function to use deque in C++ STL is similar to queue.
pushback() - to add an element at the back
pushfront() - to add an element at the front
popback() - to remove an element from the back
popfront() - to remove an element from the front
or we can use left nad right instead of front and back.
pushright() - to add an element at the right
pushleft() - to add an element at the left
popright() - to remove an element from the right
popleft() - to remove an element from the left
back() - to get the last element
front() - to get the first element
left() - to get the first element
right() - to get the last element
Now let us see an example of deque in C++ STL.
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;

    // Adding elements at the back
    dq.push_back(10);
    dq.push_back(20);

    // Adding elements at the front
    dq.push_front(5);

    cout << "Front element: " << dq.front() << endl; // Output: 5
    cout << "Back element: " << dq.back() << endl;   // Output: 20

    // Removing elements from the front
    dq.pop_front();
    cout << "Front element after pop_front: " << dq.front() << endl; // Output: 10

    // Removing elements from the back
    dq.pop_back();
    cout << "Back element after pop_back: " << dq.back() << endl; // Output: 10

    cout << "Deque size: " << dq.size() << endl; // Output: 1

    return 0;
}

Now the result of the program will be:
Front element: 5
Back element: 20
Front element after pop_front: 10
Back element after pop_back: 10
Deque size: 1

The visualization of deque can be represented as follows:
Left [5, 10, 20] Right
When we push an element at the front:
Left [3, 5, 10, 20] Right
When we push an element at the back:
Left [3, 5, 10, 20, 25] Right   
When we pop an element from the front:
Left [5, 10, 20, 25] Right
When we pop an element from the back:
Left [5, 10, 20] Right

*/

#include <iostream>
#include <queue>
#include <deque>
using namespace std;

int main() {
    queue<int> q;

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // Output: 10
    cout << "Back element: " << q.back() << endl;   // Output: 30

    // Dequeue elements
    q.pop();
    cout << "Front element after pop: " << q.front() << endl; // Output: 20

    cout << "Queue size: " << q.size() << endl; // Output: 2



    deque<int> dq;

    // Adding elements at the back
    dq.push_back(10);
    dq.push_back(20);

    // Adding elements at the front
    dq.push_front(5);

    cout << "Front element: " << dq.front() << endl; // Output: 5
    cout << "Back element: " << dq.back() << endl;   // Output: 20

    // Removing elements from the front
    dq.pop_front();
    cout << "Front element after pop_front: " << dq.front() << endl; // Output: 10

    // Removing elements from the back
    dq.pop_back();
    cout << "Back element after pop_back: " << dq.back() << endl; // Output: 10

    cout << "Deque size: " << dq.size() << endl; // Output: 1

    return 0;
}