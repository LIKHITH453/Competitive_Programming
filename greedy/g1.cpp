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
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Optimized DSU with lightweight rollback
struct RollbackDSU {
    vector<int> p, sz;
    vector<int> history;

    RollbackDSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }

    int find(int x) {
        while (p[x] != x) x = p[x];
        return x;
    }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        history.push_back(b); // Store only the child index
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }

    int save() { return (int)history.size(); }

    void rollback(int snap) {
        while ((int)history.size() > snap) {
            int b = history.back();
            history.pop_back();
            sz[p[b]] -= sz[b];
            p[b] = b;
        }
    }
};

// Standard DSU for final global answer
struct DSU {
    vector<int> p;
    int comps;
    DSU(int n) : p(n), comps(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        p[b] = a;
        comps--;
        return true;
    }
};

void solve() {
    int n, m, q;
    if (!(cin >> n >> m >> q)) return;

    vector<vector<pair<int, int>>> ew(m + 2);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        if (w <= m) ew[w].push_back({u, v});
    }

    vector<int> c(q);
    for (int& x : c) { cin >> x; x--; }

    DSU global_dsu(q);
    RollbackDSU orig(n);
    ll ans = 0;

    // Use a shared indices vector to avoid copies
    vector<int> c_idx(q);
    iota(c_idx.begin(), c_idx.end(), 0);

    function<void(int, int, int, int)> dc = [&](int l, int r, int ql, int qr) {
        if (ql > qr) return;

        if (l == r) {
            int prev_root = -1, prev_node = -1;
            // Sorting by root within this range
            vector<pair<int, int>> comp_nodes;
            for (int i = ql; i <= qr; i++) {
                comp_nodes.push_back({orig.find(c[c_idx[i]]), c_idx[i]});
            }
            sort(comp_nodes.begin(), comp_nodes.end());

            for (auto& [root, node] : comp_nodes) {
                if (root == prev_root && prev_node != -1) {
                    if (global_dsu.unite(node, prev_node)) ans += l;
                } else {
                    prev_root = root;
                    prev_node = node;
                }
            }
            return;
        }

        int mid = (l + r) / 2;
        int snap = orig.save();

        // Left branch: add edges from weight range (mid+1, r]
        for (int w = mid + 1; w <= r; w++)
            for (auto& edge : ew[w]) orig.unite(edge.first, edge.second);
        dc(l, mid, ql, qr);
        orig.rollback(snap);

        // Right branch: add edges from weight range [l, mid]
        for (int w = l; w <= mid; w++)
            for (auto& edge : ew[w]) orig.unite(edge.first, edge.second);
        dc(mid + 1, r, ql, qr);
        orig.rollback(snap);
    };

    dc(0, m, 0, q - 1);

    // Final check for connectivity at weight m+1
    if (global_dsu.comps > 1) {
        int snap = orig.save();
        for (int w = 0; w <= m; w++)
            for (auto& edge : ew[w]) orig.unite(edge.first, edge.second);

        vector<pair<int, int>> comp_nodes;
        for (int i = 0; i < q; i++) comp_nodes.push_back({orig.find(c[i]), i});
        sort(comp_nodes.begin(), comp_nodes.end());

        int prev_root = -1, prev_node = -1;
        for (auto& [root, node] : comp_nodes) {
            if (root == prev_root && prev_node != -1) {
                if (global_dsu.unite(node, prev_node)) ans += (m + 1);
            } else {
                prev_root = root;
                prev_node = node;
            }
        }
        orig.rollback(snap);
    }

    if (global_dsu.comps > 1) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}
