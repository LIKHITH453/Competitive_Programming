/*
Digit DP is a technique to count or compute something about numbers by processing their digits one-by-one(From most significant to least significant).
Instead of iterating every number up to N we treat the digit of N as a boundary and use DP to count all the valid digit sequences that form numbers <= N.
We build a DP over position (digit) plus extra states to track constraints (like whether we are still bounded by N's digits or if we have started forming a smaller number).
This allows us to solve problems that would be infeasible with brute force, especially when N can

CORE IDEA-
1.pos - current digit index (0 .. length of N - 1) usually process digits from left to right
2.tight - whether we are still bound by the prefix of N (1 if we are still bound, 0 if we have already formed a smaller number)
3.leading Zeros - whether we still have only leading zeros (we haven't placed any non-zero digit yet).
useful for problems where leading zeros shouldn't count towards sum or previous digit constraints.

Additional states can be needed such as sumSoFar, modSoFar, prevdigit, countOfSomething, etc. depending on the problem.
The DP transitions will depend on the current state and the digit we choose to place at the current position, and we will also need to consider the constraints imposed by the tight state.
The final answer is usually found in the DP state corresponding to the last digit position with tight = 0 (if we want numbers less than N) or tight = 1 (if we want numbers less than or equal to N).
The time complexity of digit DP is generally O(length of N * number of states * number of digit choices) which is efficient for reasonably large N (up to 10^18 or more).

Template for digit DP problems:(recursive with memoization)

long long dfs(int pos, int tight, int leadingZero, other states...) {
    if(pos == length of N) {
        // Base case: we have processed all digits
        return some value based on the other states;
    }
    if (memorized) return memo;

    long long ans = 0;
    int maxDigit = tight ? digit[pos] : 9; // If tight, we can only go up to the digit in N at this position
    for (int d = 0; d <= maxDigit; d++) {
        int newTight = tight && (d == maxDigit) ? 1 : 0; // If we choose the max digit, we remain tight
        int newLeadingZero = leadingZero && (d == 0) ? 1 : 0; // If we choose a non-zero digit, we are no longer leading zero
        // Update other states based on the chosen digit d
        ans += dfs(pos + 1, newTight, newLeadingZero, updated other states...);
    }
    // Memoize the result before returning
    return ans;
}


*/
/*

Example1. Count how many numbers from 0 to N that does not contain digit 4.

Let us take N = 57
valid numbers are 0,1,2,3,5,6,7,8,9,10,11,...39,50,51,...57

This is a digit DP problem where we want to count valid numbers up to N with the constraint that they do not contain the digit 4.
We can define our DP states as follows:
1. pos: the current digit index we are processing (from left to right)
2. tight: whether we are still bound by the prefix of N (1 if we are still bound, 0 if we have already formed a smaller number)
3. leadingZero: whether we have only placed leading zeros so far (1 if we haven't placed any non-zero digit yet, 0 otherwise)
The transitions will involve iterating over the possible digits we can place at the current position, ensuring that we do not place the digit 4 and that we respect the tight constraint when necessary.
The final answer will be found in the DP state corresponding to the last digit position with tight = 0 (if we want numbers less than N) or tight = 1 (if we want numbers less than or equal to N).  




#include <bits/stdc++.h>
using namespace std;

long long dfs(int pos, int tight, int leadingZero, const string &N, vector<vector<vector<long long>>> &memo) {
    if(pos == N.size()) {
        return 1; // Base case: we have processed all digits and found a valid number
    }
    if(memo[pos][tight][leadingZero] != -1) {
        return memo[pos][tight][leadingZero]; // Return memoized result
    }

    long long ans = 0;
    int maxDigit = tight ? (N[pos] - '0') : 9; // If tight, we can only go up to the digit in N at this position
    for(int d = 0; d <= maxDigit; d++) {
        if(d == 4) continue; // Skip digit 4
        int newTight = (tight && (d == maxDigit)) ? 1 : 0; // If we choose the max digit, we remain tight
        int newLeadingZero = (leadingZero && (d == 0)) ? 1 : 0; // If we choose a non-zero digit, we are no longer leading zero
        ans += dfs(pos + 1, newTight, newLeadingZero, N, memo); // Recur for the next position
    }
    return memo[pos][tight][leadingZero] = ans; // Memoize the result before returning
}


int main() {
    string N;
    cin >> N;
    vector<vector<vector<long long>>> memo(N.size(), vector<vector<long long>>(2, vector<long long>(2, -1)));
    cout << dfs(0, 1, 1, N, memo) << endl; // Start from the first digit, tight = 1 (we are bound by N), leadingZero = 1 (we haven't placed any non-zero digit yet)
    return 0;
}
*/

/*

2.Count the number if digits from a to b where no 2 adjacent digits are the same.

*/

#include <bits/stdc++.h>
using namespace std;

long long dfs(int pos, int tight, int leadingZero, int prevDigit, const string &N, vector<vector<vector<vector<long long>>>> &memo) {
    if(pos == N.size()) {
        return 1; // Base case: we have processed all digits and found a valid number
    }
    if(memo[pos][tight][leadingZero][prevDigit] != -1) {
        return memo[pos][tight][leadingZero][prevDigit]; // Return memoized result
    }

    long long ans = 0;
    int maxDigit = tight ? (N[pos] - '0') : 9; // If tight, we can only go up to the digit in N at this position
    for(int d = 0; d <= maxDigit; d++) {
        if(d == prevDigit) continue; // Skip if the current digit is the same as the previous digit
        int newTight = (tight && (d == maxDigit)) ? 1 : 0; // If we choose the max digit, we remain tight
        int newLeadingZero = (leadingZero && (d == 0)) ? 1 : 0; // If we choose a non-zero digit, we are no longer leading zero
        ans += dfs(pos + 1, newTight, newLeadingZero, d, N, memo); // Recur for the next position with the current digit as the new previous digit
    }
    return memo[pos][tight][leadingZero][prevDigit] = ans; // Memoize the result before returning
}
int main() {
    string N;
    cin >> N;
    vector<vector<vector<vector<long long>>>> memo(N.size(), vector<vector<vector<long long>>>(2, vector<vector<long long>>(2, vector<long long>(10, -1))));
    cout << dfs(0, 1, 1, -1, N, memo) << endl; // Start from the first digit, tight = 1 (we are bound by N), leadingZero = 1 (we haven't placed any non-zero digit yet), prevDigit = -1 (no previous digit)
    return 0;
}