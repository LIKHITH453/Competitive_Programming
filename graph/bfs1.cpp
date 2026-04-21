/*
Question 500-A
New Year Transportation
time limit per test
2 seconds
memory limit per test
256 megabytes

New Year is coming in Line World! In this world, there are n cells numbered by integers from 1 to n, as a 1 × n board. People live in cells. However, it was hard to move between distinct cells, because of the difficulty of escaping the cell. People wanted to meet people who live in other cells.

So, user tncks0121 has made a transportation system to move between these cells, to celebrate the New Year. First, he thought of n - 1 positive integers a1, a2, ..., an - 1. For every integer i where 1 ≤ i ≤ n - 1 the condition 1 ≤ ai ≤ n - i holds. Next, he made n - 1 portals, numbered by integers from 1 to n - 1. 
The i-th (1 ≤ i ≤ n - 1) portal connects cell i and cell (i + ai), and one can travel from cell i to cell (i + ai) using the i-th portal. Unfortunately, one cannot use the portal backwards, which means one cannot move from cell (i + ai) to cell i using the i-th portal. It is easy to see that because of condition 1 ≤ ai ≤ n - i one can't leave the Line World using portals.

Currently, I am standing at cell 1, and I want to go to cell t. However, I don't know whether it is possible to go there. Please determine whether I can go to cell t by only using the construted transportation system.
Input

The first line contains two space-separated integers n (3 ≤ n ≤ 3 × 104) and t (2 ≤ t ≤ n) — the number of cells, and the index of the cell which I want to go to.

The second line contains n - 1 space-separated integers a1, a2, ..., an - 1 (1 ≤ ai ≤ n - i). It is guaranteed, that using the given transportation system, one cannot leave the Line World.
Output

If I can go to cell t using the transportation system, print "YES". Otherwise, print "NO".

We are using graphs to solve this problem. We can represent the cells as nodes and the portals as directed edges. We can then perform a breadth-first search (BFS) starting from cell 1 to see if we can reach cell t.
we aer using a directed graph because the portals only allow movement in one direction (from cell i to cell i + ai). from 1 to t we can only move forward, so we will not be able to go back to previous cells.


*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main () {
    int n, t;
    cin >> n >> t;
    int a[n];
    int p = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i]; 
    }
    while (p < t - 1) {
        p += a[p];
    }
    if (p == t - 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}