/*
The question is a sliding window maximum problem using queues and deques.
Given an array and a window size k, we need to find the maximum element in each sliding window of size k.
An example input could be:
Array: [1, 3, -1, -3, 5, 3, 6, 7]
Window size k: 3
The output for this input should be:
[3, 3, 5, 5, 6, 7]
[1,3,-1]|-3|5|3|6|7 -> 3
3|[3,-1,-3]|5|3|6|7 -> 3
3|3[-1,-3,5]|3|6|7 -> 5
3|3|-1[-3,5,3]|6|7 -> 5
3|3|-1|-3[5,3,6]|7 -> 6
3|3|-1|-3|5[3,6,7] -> 7

The output of the program will be:
The array [3,3,5,5,6,7]

The Brute force idea will be using 2 for loops to traverse the array and find the maximum in each window of size k.
the time complexity of this approach will be O(n*k) where n is the size of the array and k is the size of the window.

The more efficient approach will be using a deque to store the indices of the array elements.
next we will traverse the array and for each element we will remove the elements from the back of the deque which are smaller than the current element.
then we will add the current element index to the back of the deque.
next we will check if the front of the deque is out of the current window, if yes we will remove it from the front.
finally, if we have processed at least k elements, we will add the front of the deque to the result as it will be the maximum element of the current window.
eg :
Array: [1, 3, -1, -3, 5, 3, 6, 7]
Window size k: 3
when traversing this array using deque we will do the following steps:
1. Add index 0 (value 1) to deque -> deque: [0]
2. Add index 1 (value 3) to deque, remove index 0 as 3 > 1 -> deque: [1]
3. Add index 2 (value -1) to deque -> deque: [1, 2]
   Now we have processed 3 elements, add value at index 1 (3) to result -> result: [3]
4. Add index 3 (value -3) to deque -> deque: [1, 2


*/


#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main()
{
    int k;
    vector<int> arr;
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "Enter the size of the window: ";
    cin >> k;
    deque<int> dq;
    vector<int> result;
    for(int i = 0; i < n; i++)
    {
        while(!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while(!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k - 1)
        {
            result.push_back(arr[dq.front()]);
        }
    }
    int size = result.size();
    cout << "The array [";
    for(int i = 0; i < size; i++)
    {
        cout << result[i];
        if(i != size - 1)
            cout << ",";
    }
    cout << "]" << endl; 
    return 0;
}