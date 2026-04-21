/*
DP(Dynamic Programming) ot find th solution involving dp problem we divide the problem into sub-problems find the answer to those sub-problem, combine them to get the original answer
Eg: sum of 1+2+3+4+5 would be 
sum of (1+2)+(3+4)+(5)
then 3+7+5
would be 15

My personal trick :-
-->dp[i] usually mean the best answer to the problem till the i’th index of the array.
-->Obviously, final answer will be dp[n](where 'n' is the size of the array)
-->We cannot calculate dp[n] directly, we first need to calculate dp[1],dp[2],… and combine their results to find the value of dp[n] :-)

Problem-1 : We are given an array of integers(a[n]) . We are given multiple queries of the form : (1, i) which means we need to output the sum of all numbers from index- ‘1’ to index ‘i’ of the array.
Analysis : Running a loop for each query[O(N)] and finding the sum is a good idea but not very efficient as it takes O(N*Q) time.
Let us create a dp-array of size ‘n’.
-->dp[1]=sum of all numbers from (1,1)
-->dp[2]=sum of all numbers from (1,2)…
and so on.
Say, a[5]={4,5,3,2,1}…(assume 1-based-indexing here) So, dp[1]=4(pretty easy)…..(1)
dp[2]=4+5=9………(2)
dp[3]=4+5+3=12…..(3) and so on.
So, for any index ‘i’ ,
dp[i]=a[i]+dp[i-1],
Example:-
dp[3] = a[3] + dp[3–1] = a[3] + dp[2]= 3 + 9 =12 ….(which is same as equation…(3))



#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 5 ; //size of the array 
    int a[5] = {6,7,3,2,2}; 

    int dp[n+1]={0}; //dp array 
    int i = 0 ; 
    while(i<=n-1){
        if(i==0){
            dp[i] = a[i] ; 
        }
        else{
            dp[i] = a[i] + dp[i-1];
        }
        i++;
    }
    int q = 4 ; //number of queries 
    int w[4] = {0,3,4,2}; //query array 
    i = 0 ; 
    while(i<=q-1){
        int query;query = w[i];
        cout<<dp[query]; //answering each query in O(1) 
        cout<<endl;
        i++;
       }
    return 0;
} 
*/

/*
A. Friendly Numbers
time limit per test
1 second
memory limit per test
256 megabytes

For an integer x
, we call another integer y

friendly if the following condition holds:

    y−d(y)=x

, where d(y) is the sum of the digits of y

    . 

For a given integer x

, determine how many friendly numbers it has.
Input

Each test contains multiple test cases. The first line contains the number of test cases t
(1≤t≤500

). The description of the test cases follows.

Each test case consists of a single line containing one integer x
(1≤x≤109

).
Output

For each test case, output one integer — the answer to the problem.

Idea let us use a haspmap to store the count of each digit sum. We can iterate through all numbers from 1 to x and calculate their digit sum and store the count in the hashmap. Then we can iterate through the hashmap and for each digit sum, we can check if there is a friendly number by checking if x + digit sum is present in the hashmap. If it is present, then we can add the count of that digit sum to our answer.


*/


#include <bits/stdc++.h>
using namespace std;

int digitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long x;
        cin >> x;
        
        unordered_set<long long> friendlyNumbers;
        
        // Try all possible digit sums
        // For x up to 10^9, y would be around 10^9 + digit_sum
        // Maximum digit sum we need to check is around 200
        for (int s = 1; s <= 200; s++) {
            long long y = x + s;
            
            // Check if digit sum of y equals s
            if (digitSum(y) == s) {
                friendlyNumbers.insert(y);
            }
        }
        
        cout << friendlyNumbers.size() << "\n";
    }
    
    return 0;
}