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

Number of Factors (f(n)):
The umber of positive divisors of a number n denoted by f(n) can be calculated using the prime factorization of n. 
if : n = p1^a1 * p2^a2 * ... * pk^ak
where p1, p2, ..., pk are the prime factors of n and a1, a2, ..., ak are their respective positive integer exponents, then the number of positive divisors f(n) can be calculated using the formula:
f(n) = (a1 + 1) * (a2 + 1) * ... * (ak + 1)
Why? for each prime pi it exponents in a divisor an range from 0 to ai, so there are (ai + 1) choices for the exponent of pi in a divisor. Since the choices for each prime factor are independent, 
we multiply the number of choices together to get the total number of divisors.
example n = 84

84 = 2^2 * 3^1 * 7^1
f(84) = (2 + 1) * (1 + 1) * (1 + 1) = 3 * 2 * 2 = 12
The divisors of 84 are: 1, 2, 3, 4, 6, 7, 12, 14, 21, 28, 42, 84
To calculate f(n) efficiently, we can use trial division to find the prime factors and their exponents, which has a time complexity of O(sqrt(n)). 
This method is efficient for n up to around 10^12, which is suitable for competitive programming problems.

long long countDivisors(long long n) {
long long ans = 1;
for (long long i = 2; i * i <= n; i++) {
    long long count = 0;
    while (n % i == 0) {
        n /= i;
        count++;}
    ans *= (count + 1);
}
if (n > 1) {
    ans *= 2;
}
return ans;
}
-> Time complexity: O(sqrt(n))
-> Space complexity: O(sqrt(n)) in the worst case when n is a product of distinct primes, but typically much less.
-> Works for n<=1e12    

Sum of Factors:
The sum of positive divisors of a number n, denoted by S(n), can also be calculated using the geometric series formula based on the prime factorization of n.
If n = p1^a1 * p2^a2 * ... * pk^ak, then the sum of positive divisors S(n) can be calculated using the formula:
S(n) = ((p1^(a1 + 1) - 1) / (p1 - 1)) * ((p2^(a2 + 1) - 1) / (p2 - 1)) * ... * ((pk^(ak + 1) - 1) / (pk - 1))
This formula arises because the sum of divisors for each prime factor can be expressed as a geometric series. 
For each prime factor pi, the divisors contributed by that prime factor are pi^0, pi^1, ..., pi^ai, 
and the sum of these divisors can be calculated using the formula for the sum of a geometric series.
S(84) = 2^3-1/2-1 * 3^2-1/3-1 * 7^2-1/7-1 = 7*8*4 = 224
To calculate S(n) efficiently, we can use trial division to find the prime factors and their exponents, which has a time complexity of O(sqrt(n)). 
This method is efficient for n up to around 10^12, which is suitable for competitive programming problems.

long long sumOfDivisors(long long n) {
    long long ans = 1;
    for (long long i = 2; i * i <= n; i++) {
        long long count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        if (count > 0) {
            ans *= (pow(i, count + 1) - 1) / (i - 1);
        }
    }
    if (n > 1) {
        ans *= (pow(n, 2) - 1) / (n - 1);
    }
    return ans;
}
-> Time complexity: O(sqrt(n))
-> Space complexity: O(sqrt(n)) in the worst case when n is a product of distinct primes, but typically much less.
-> Works for n<=1e12

Product of Factors:
The product of all positive divisors of a number n, denoted by P(n), can be calculated using the formula:
P(n) = n^(f(n)/2)
where f(n) is the number of positive divisors of n.
This formula arises because the divisors of n can be paired up such that each pair multiplies to n. 
If n has an odd number of divisors, then one of the divisors is the square root of n, and it will be paired with itself, contributing a factor of n to the product.
Example n = 84
f(84) = 12
P(84) = 84^(12/2) = 84^6
To calculate P(n) efficiently, we can first calculate f(n) using the method described earlier, and then compute n^(f(n)/2) using fast exponentiation, which has a time complexity of O(log(f(n))).


long long productOfDivisors(long long n) {
    long long numDivisors = 1;
    long long temp = n;
    for (long long i = 2; i * i <= temp; i++) {
        long long count = 0;
        while (temp % i == 0) {
            temp /= i;
            count++;
        }
        if (count > 0) {
            numDivisors *= (count + 1);
        }
    }
    if (temp > 1) {
        numDivisors *= 2; // For the prime factor that is greater than sqrt(n)
    }
    return pow(n, numDivisors / 2); // n^(f(n)/2)
}



Precomputing Divisors for all Numbers(Seive-like approach):
We can precompute the number of divisors, sum of divisors, and product of divisors for all numbers up to a certain limit using a sieve-like approach. 
This is particularly useful when we need to answer multiple queries about divisors for numbers up to a certain limit.

int N = 1e6; // Limit for precomputation
vector<int> divisorCount(N + 1);
for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
        divisorCount[j]++;
    }
}
This code snippet precomputes the number of divisors for all numbers from 1 to N. 
The outer loop iterates through each integer i, and the inner loop increments the divisor count
*/

/*
Given a integer your task is to report for each integer the number fo its divisors.
For example x=18 the correct answer is 6 because its divisors are 1,2,3,6,9,18

Input:
The first input line has an integer n; the number of integers
After this, there are n lines, each has an integer x.

Output:
Print the number of divisors for each integer.

Constraints:
1 <= n <= 10^5
1 <= x <= 10^6

#include <bits/stdc++.h>
using namespace std;

long long countDivisors(long long n) {
    long long ans = 1;
    for (long long i = 2; i * i <= n; i++) {
        long long count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        ans *= (count + 1);
    }
    if (n > 1) {
        ans *= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        long long x;
        cin >> x;
        cout << countDivisors(x) << "\n";
    }
    return 0;
}
    */


/*
GCD(Greatest Common Divisor):
The greatest common divisor (GCD) of two integers a and b, denoted as gcd(a, b), is the largest positive integer that divides both a and b without leaving a remainder.
The most efficient way to compute the GCD of two numbers is to use the Euclidean algorithm, which is based on the principle that the GCD of two numbers also divides their difference.
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
-> Time complexity: O(log(min(a, b)))
-> Space complexity: O(1)
other methods to compute GCD include prime factorization, but the Euclidean algorithm is generally more efficient and is the preferred method in competitive programming.
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
-> Time complexity: O(log(min(a, b)))
-> Space complexity: O(log(min(a, b))) due to recursive call stack
Eg: 36 = 2*2*3*3


*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    for (int tc = 0; tc < t; ++tc) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        vector<int> ops;
        int parity = 0;   // 0 = even number of flips applied to the current suffix, 1 = odd
        
        // Process from right to left (i = n-1 down to 1)
        for (int i = n - 1; i > 0; --i) {
            int cur = a[i];
            if (parity) cur = -cur;
            // If the current element (after previous flips) is positive,
            // we perform an operation at index i (1‑based) to flip the prefix up to i.
            // This will make this element negative, but it allows earlier elements to be flipped later.
            if (cur > 0) {
                ops.push_back(i);   // store 0‑based index, will convert later
                parity ^= 1;        // toggle flip parity for the left part
            }
        }
        
        // Handle the first element (index 0)
        int first = a[0];
        if (parity) first = -first;
        if (first < 0) {
            ops.push_back(0);       // flip the whole array (prefix up to 1)
        }
        
        // Convert to 1‑based indices and reverse (because we collected from right to left)
        for (int &x : ops) x++;
        reverse(ops.begin(), ops.end());
        
        // Output
        cout << ops.size() << '\n';
        for (size_t i = 0; i < ops.size(); ++i) {
            if (i) cout << ' ';
            cout << ops[i];
        }
        cout << '\n';
        
        // Print a blank line after each test case except the last (to match sample)
        if (tc < t - 1) cout << '\n';
    }
    return 0;
}