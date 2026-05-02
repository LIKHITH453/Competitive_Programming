/*
What is a divisor?
A number is 'a' factor(divisor) of 'b' if 'a' divides 'b' exactly without a remainder


BRUTE FORCE METHOD:
check every number from 2 to n 
vector<int> divisors;
for (int i = 1; i<=n; i++){
    if (n%i==0) divisors.push_back(i);
}
-> Time complexity: O(n)
-> Space complexity: O(n)
-> Works for n<=1e6
-> Too slow for Cp when n<=1e12

Optimized method:
Creation of pairs n, n/d
vector<long long> divisors;
for (int i = 1; i*i<=n; i++){
    if (n%i==0) {
        divisors.push_back(i);
        if (i!=n/i) divisors.push_back(n/i);
    }
}
-> Time complexity: O(sqrt(n))
-> Space complexity: O(sqrt(n))
-> Works for n<=1e12
*/