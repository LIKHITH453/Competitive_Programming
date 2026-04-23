/*
Amazon OA:
There are N cities in a country. A is initially at the airport in city 1 and wants to reach city N the flights are to the city i+1 or i+3 .
We have been given with array B with the cost of flight tickets to N cities to find the cost of tickets from city i to j is the absolute difference of B[i] and B[j].
that is |b| = B[i] - B[j]|.
Find the minimum cost incurred by A to reach city N from city 1.

Idea is to use DP where dp[i] represents the minimum cost to reach city i from city 1.

input :
1. 6
2. [4,12,13,18,10,12]

output : 10

dp[1] = 0
dp[2] = dp[1] + |B[2]-B[1]| = 8
dp[3] = dp[1] + |B[3]-B[1]| = 9
dp[4] = min(dp[3] + |B[4]-B[3]| , dp[1] + |B[4]-B[1]|) = min(14,14) = 14
dp[5] = min(dp[4] + |B[5]-B[4]| , dp[2] + |B[5]-B[2]|) = min(18,10) = 10
dp[6] = min(dp[5] + |B[6]-B[5]| , dp[3] + |B[6]-B[3]| , dp[2] + |B[6]-B[2]|) = min(10+2,9+1) = 10




#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> B(n);
    for(int i = 0; i < n; i++) {
        cin >> B[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0; // Starting at city 1 with 0 cost
    dp[1] = abs(B[1] - B[0]); // Cost to reach city 2 from city 1
    dp[2] = abs(B[2] - B[1]) + dp[1]; // Cost to reach city 3 from city 1
    for(int i = 3; i < n; i++) {
        dp[i] = min(dp[i-1] + abs(B[i] - B[i-1]), dp[i-3] + abs(B[i] - B[i-3]));
    }
    cout << dp[n-1] << endl;
    return 0;
}
*/

/*
Question: Given an array of size N we have to start the journey from index 0 to index N-1. From any index i we can jump to i+1 or i+3 or i+5.
In the array positive as well as negative integers are present. We have to find the maximum sum of values we can collect while reaching from index 0 to index N-1.
ex: Input: N=7
A = [5,8,3,100,-5,-5,10]

dp approach:

dp[0] = A[0] = 5
dp[1] = dp[0] + max(A[0+1],A[0+3],A[0+5]) = 5 + 8 = 13
dp[2] = dp[1] + max(A[1+1],A[1+3],A[1+5]) = 13 + 100 = 113
dp[3] = dp[2] + max(A[2+1],A[2+3],A[2+5]) = 113 + 100 = 218
dp[4] = dp[3] + max(A[3+1],A[3+3]) = 218 + 10 = 228
output: 228




#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> dp(n, INT_MIN);
    dp[0] = b[0]; // Starting at index 0
    for(int i = 0; i < n; i++) {
        dp[i] = max(dp[i - 1] + b[i], max(dp[i - 3] + b[i], dp[i - 5] + b[i]));
    }
    cout << dp[n - 1] << endl;
    return 0;
}
*/


/*
Question: To find the number of ways to construct sum n by throwing a dice one or more times each throw produces an outcome between 1 and 6.
if n = 3 
then the possible combinations are (1,1,1), (1,2), (2,1), (3) so the output is 4.
print the number fo ways modulo 10^9 + 7.

If there is a pattern to count the number of ways we go from source to destination from 0 to move to n  


#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base case: There is one way to make the sum of 0 (using no dice)
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i - j >= 0) {
                dp[i] = (dp[i] + dp[i - j]) % 1000000007;
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}

The time complexity of the solution is O(n^2) and the space complexity is O(n).

We can use the idea of graphs in this question where we can consider each sum as a node and there is a direction edge from node i to node i+j where j is the outcome of the dice throw.
We can use BFS or DFS to find the number of paths from node 0 to node n. The time complexity of this approach is also O(n^2) and the space complexity is O(n).


*/

/*
A. Hit the Lottery
time limit per test
1 second
memory limit per test
256 megabytes

Allen has a LOT of money. He has n
dollars in the bank. For security reasons, he wants to withdraw it in cash (we will not disclose the reasons here). The denominations for dollar bills are 1, 5, 10, 20, 100

. What is the minimum number of bills Allen could receive after withdrawing his entire balance?
Input

The first and only line of input contains a single integer n
(1≤n≤109

).
Output:

Output the minimum number of bills that Allen could receive.



CODE -----------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> denominations = {100, 20, 10, 5, 1};
    int count = 0;
    for(int bill : denominations) {
        count += n / bill; // Count how many bills of this denomination we can use
        n %= bill; // Reduce n by the amount we've covered with this denomination
    }
    cout << count << endl; // Output the total count of bills
}
    */


/*
B. Fair Division
time limit per test
2 seconds
memory limit per test
256 megabytes

Alice and Bob received n

candies from their parents. Each candy weighs either 1 gram or 2 grams. Now they want to divide all 
candies among themselves fairly so that the total weight of Alice's candies is equal to the total weight of Bob's candies.

Check if they can do that.

Note that candies are not allowed to be cut in half.
Input

The first line contains one integer t
(1≤t≤104) — the number of test cases. Then t

test cases follow.

The first line of each test case contains an integer n
(1≤n≤100

) — the number of candies that Alice and Bob received.

The next line contains n
integers a1,a2,…,an — the weights of the candies. The weight of each candy is either 1 or 2

.

It is guaranteed that the sum of n
over all test cases does not exceed 105

.
Output

For each test case, output on a separate line:

    "YES", if all candies can be divided into two sets with the same weight;
    "NO" otherwise. 

You can output "YES" and "NO" in any case (for example, the strings yEs, yes, Yes and YES will be recognized as positive).






#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> candies(n);
        int count1 = 0,  count2 = 0;
        for(int i = 0; i < n; i++) {
            cin >> candies[i];
            if(candies[i] == 1) count1++;
            else count2++;
        }
        int totalWeight = count1 + 2 * count2;
        if(totalWeight % 2 != 0) {
            cout << "NO" << endl; // If total weight is odd, it's impossible to divide it equally
            continue;
        }
        else {
            int halfWeight = totalWeight / 2;
            if(halfWeight % 2 == 0) {
                cout << "YES" << endl; // If half weight is even, we can always form it
            }
            else {
                if(count1 >= 1) {
                    cout << "YES" << endl; // If half weight is odd, we need at least one 1-gram candy
                }
                else {
                    cout << "NO" << endl; // No 1-gram candy to adjust the odd half weight
                }
            }
        }
    }
}
*/
/*
A. Maximum Increase
time limit per test
1 second
memory limit per test
256 megabytes

You are given array consisting of n integers. Your task is to find the maximum length of an increasing subarray of the given array.

A subarray is the sequence of consecutive elements of the array. Subarray is called increasing if each element of this subarray strictly greater than previous.
Input

The first line contains single positive integer n (1 ≤ n ≤ 105) — the number of integers.

The second line contains n positive integers a1, a2, ..., an (1 ≤ ai ≤ 109).
Output

Print the maximum length of an increasing subarray of the given array.





CODE --------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maxLength = 1; // At least one element is an increasing subarray
    int currentLength = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i - 1]) {
            currentLength++; // Continue the increasing subarray
        } else {
            maxLength = max(maxLength, currentLength); // Update max length if needed
            currentLength = 1; // Reset for the next subarray
        }
    }
    maxLength = max(maxLength, currentLength); // Check at the end in case the longest subarray ends at the last element
    cout << maxLength << endl;

}

*/


/*
B. The Cake Is a Lie
time limit per test
2 seconds
memory limit per test
256 megabytes

There is a n×m
grid. You are standing at cell (1,1) and your goal is to finish at cell (n,m)

.

You can move to the neighboring cells to the right or down. In other words, suppose you are standing at cell (x,y)

. You can:

    move right to the cell (x,y+1)

 — it costs x
burles;
move down to the cell (x+1,y)
 — it costs y

    burles. 

Can you reach cell (n,m)
spending exactly k

burles?
Input

The first line contains the single integer t
(1≤t≤100

) — the number of test cases.

The first and only line of each test case contains three integers n
, m, and k (1≤n,m≤100; 0≤k≤104

) — the sizes of grid and the exact amount of money you need to spend.
Output

For each test case, if you can reach cell (n,m)
spending exactly k

burles, print YES. Otherwise, print NO.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

CODE : -----------------------------------------------------------------------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
       if(n*m-1 == k) { // The cost to reach (n,m) from (1,1) is (n-1)*m + (m-1)*n = n*m - 1
            cout << "YES" << endl; // If the cost matches k, we can reach (n,m)
        } else {
            cout << "NO" << endl; // Otherwise, it's not possible
        }
    }
}
    */


/*
A. Kefa and First Steps
time limit per test
2 seconds
memory limit per test
256 megabytes

Kefa decided to make some money doing business on the Internet for exactly n days. He knows that on the i-th day (1 ≤ i ≤ n) he makes ai money. Kefa loves progress, that's why he wants to know the length of the maximum non-decreasing subsegment in sequence ai. Let us remind you that the subsegment of the sequence is its continuous fragment. A subsegment of numbers is called non-decreasing if all numbers in it follow in the non-decreasing order.

Help Kefa cope with this task!
Input

The first line contains integer n (1 ≤ n ≤ 105).

The second line contains n integers a1,  a2,  ...,  an (1 ≤ ai ≤ 109).
Output

Print a single integer — the length of the maximum non-decreasing subsegment of sequence a.

CODE: ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


#include <iostream>
using namespace std;

int main()
{
    int n, l(1), ml(1);
    cin >> n;
    int profits[n];

    for (int i = 0; i < n; i++)
    {
        cin >> profits[i];
        if (i > 0)
            if (profits[i] >= profits[i - 1])
            {
                l++;
                ml = max(ml, l);
            }
            else
                l = 1;
    }

    cout << ml << endl;
    return 0;
}
    */
/*

C. Raspberries
time limit per test
2 seconds
memory limit per test
256 megabytes

You are given an array of integers a1,a2,…,an
and a number k (2≤k≤5

). In one operation, you can do the following:

    Choose an index 1≤i≤n

,
Set ai=ai+1

    .

Find the minimum number of operations needed to make the product of all the numbers in the array a1⋅a2⋅…⋅an
divisible by k

.
Input

Each test consists of multiple test cases. The first line contains a single integer t
(1≤t≤104

) — the number of test cases. Then follows the description of the test cases.

The first line of each test case contains two integers n
and k (2≤n≤105, 2≤k≤5) — the size of the array a and the number k

.

The second line of each test case contains n
integers a1,a2,…,an (1≤ai≤10

).

It is guaranteed that the sum of n
over all test cases does not exceed 2⋅105

.
Output

For each test case, output the minimum number of operations needed to make the product of all the numbers in the array divisible by k
.


*/
#include <bits/stdc++.h>    
using namespace std;

int main() {
    return 0;
}