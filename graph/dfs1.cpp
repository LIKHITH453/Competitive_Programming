/*
Q.There is a bidirectional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). 
The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bidirectional edge between vertex ui and vertex vi. 
Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.    

We want to determine if there is a valid path that exists from vertex source to vertex destination.

Eg: 0 -- 1
    |    |
    2 -- 3  

    we can use adjacency matrix or adjacency list to represent the graph.
    
       0 1 2 3
    0  F T T F
    1  T F F T 
    2  T F T F
    3  F T F T


Then we will define a stack to perform DFS.
And a visited array to keep track of visited nodes.And marking all the source nodes as false initially.

Then we will push the source node into the stack and mark it as visited.
Then we will run a while loop until the stack is empty.




#include <bits/stdc++.h>
using namespace std;

bool dfs_has_path(int node, int dest, const vector<vector<int>>& graph, vector<char>& visited) {
    if (node == dest) return true;
    visited[node] = 1;
    for (int nei : graph[node]) {
        if (!visited[nei]) {
            if (dfs_has_path(nei, dest, graph, visited)) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    if (n <= 0) return 0;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u >= 0 && u < n && v >= 0 && v < n) {
            graph[u].push_back(v);
            graph[v].push_back(u); // undirected
        }
    }

    int source, destination;
    cin >> source >> destination;
    if (source < 0 || source >= n || destination < 0 || destination >= n) {
        cout << "Invalid source/destination\n";
        return 0;
    }

    vector<char> visited(n, 0);
    bool exists = dfs_has_path(source, destination, graph, visited);

    if (exists) cout << "Path exists\n";
    else cout << "No path\n";

    return 0;
}
    */


/*
Suppose we have a graph of the form 

    0--1
    |                   3--5
    |           and     \  /
    2           4        4


    Then we can represent it using an adjacency list as follows:
    0: [1, 2]
    1: [0]
    2: [0]
    3: [4, 5]
    4: [3, 5]
    5: [3, 4]

    where we can use the index to represent the node and the vector at that index to represent its neighbors.
    we can use an unordered_map<int, vector<int>> to represent the adjacency list.

#include <bits/stdc++.h>
using namespace std;   

bool dfs(int n, int source, int dest, const unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
    if (source == dest) return true;
    visited[source] = true;
    for (auto neighbor : adj.at(source)) {
        if (!visited[neighbor]) {
            if (dfs(n, neighbor, dest, adj, visited)) return true;
        }
    }
    return false;
}

int main()
{
    int n, m; // n = number of nodes, m = number of edges
    cin >> n >> m;
    unordered_map<int, vector<int>> adj; // adjacency list representation of the graph
    vector<vector<int>>& m; // to store the edges
    for(auto edge : m)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }
    int source, dest;
    cin >> source >> dest;
    vector<bool> visited(n, false); // to keep track of visited nodes
    return dfs(source, dest, adj, visited);
}

// The example input can be represented as follows:
// n = 6, m = 5
// edges = [[0,1],[0,2],[3,4],[4,5],[3,5]]
// source = 0, dest = 5 
*/


/*
Question: Given 2 intergers n and k return an array of all the integers of length n where the difference between every two consecutive digits is k.

Ex: n = 3, k = 7
output: [181,292,707,818,929]

n = 2, k = 1
output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]



*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int num, int n, int k, vector<int>& result) {
    if(n==0) {
        result.push_back(num);
        return;
    }
    if((num%10)+k <=9) {
        dfs(num*10 + (num%10)+k, n-1, k, result);
    }
    if(num%10 - k >=0 && k!=0) {
        dfs(num*10 + (num%10)-k, n-1, k, result);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> result;
    for(int num =0;num<=9;num++) {
        dfs(num, n-1, k, result);
    }
    for(auto num : result) {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}