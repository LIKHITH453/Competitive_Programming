/*
What are Greedy algorithms?
are a class of algorithms 
1.Make the choice based on what is best at the moment
2.Looking for maximizing the short term gain
3.Never takes back it decision/choice
4.directly constructs the final solution

Backtracking: In this the algorithm we fins one of the most optimal solution but it is not guaranteed to be the best solution.
It is a general algorithm for finding all (or some) solutions to some computational problems, notably constraint satisfaction problems, 
that incrementally builds candidates to the solutions, and abandons a candidate ("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution.

Complete Search: In this the algorithm we fins one of the most optimal solution but it is not guaranteed to be the best solution.
It is a general algorithm for finding all (or some) solutions to some computational problems, notably constraint satisfaction problems, 
that incrementally builds candidates to the solutions, and abandons a candidate ("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution.

General approach to solve greedy problems:
1. Greedy choice property: A global optimal solution can be arrived at by selecting a local optimal choice.
2. Optimal substructure: An optimal solution to the problem contains an optimal solution to subproblems.
3. Prove that the greedy choice property and optimal substructure hold for the problem.
4. Design an algorithm that makes greedy choices and solves the resulting subproblems recursively.
5. Analyze the time complexity of the algorithm.
6. Implement the algorithm and test it with various inputs to ensure its correctness and efficiency.
7. Optimize the algorithm if necessary, and consider edge cases and potential pitfalls in the implementation.




*/

#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

// Modular exponentiation for modInverse
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

const int MAXN = 2000005;
int phi[MAXN];
long long fact[MAXN];

// Precompute Euler Totient and Factorials
void sieve(int n) {
    for (int i = 0; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<int> count_fixed(n + 1, 0);
    int n0 = n; // Number of currently unassigned positions
    long long sum_i0 = 1LL * n * (n + 1) / 2; // Sum of indices of unassigned positions
    long long N = fact[n]; // Total permutations W
    bool possible = true;
    int n_fixed_idx = -1;

    long long inv4 = modInverse(4);
    // Expected inversions for pairs not involving the value 'n'
    long long others_expected = (n < 2) ? 0 : 1LL * (n - 1) * (n - 2) % MOD * inv4 % MOD;

    for (int k = 0; k < q; k++) {
        int i, x;
        cin >> i >> x;

        // If it's already impossible, we just keep printing 0
        if (!possible) {
            cout << 0 << "\n";
            continue;
        }

        // Update the number of valid permutations (N) using the change in choices
        int sz_x = phi[n / x];
        N = (N * modInverse(n0)) % MOD;
        N = (N * (sz_x - count_fixed[x])) % MOD;

        count_fixed[x]++;
        n0--;
        sum_i0 -= i;

        // Validity checks
        if (count_fixed[x] > sz_x) possible = false;
        if (x == n) n_fixed_idx = i;

        if (!possible || N == 0) {
            cout << 0 << "\n";
            possible = false;
            continue;
        }

        long long ans = 0;
        if (n_fixed_idx != -1) {
            // Value 'n' is at a known position
            long long e = (n - n_fixed_idx + others_expected + MOD) % MOD;
            ans = (N * e) % MOD;
        } else {
            // Value 'n' is at an unknown '0' position
            long long term1 = (N * n) % MOD;
            long long term2 = (N * modInverse(n0)) % MOD * (sum_i0 % MOD) % MOD;
            long long term3 = (N * others_expected) % MOD;
            ans = (term1 - term2 + MOD + term3) % MOD;
        }
        
        // Print answer on a new line to avoid grouping/concatenation
        cout << ans << "\n";
    }
}

int main() {
    // Fast I/O is critical for this problem due to large N and Q
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    sieve(2000000);
    
    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}