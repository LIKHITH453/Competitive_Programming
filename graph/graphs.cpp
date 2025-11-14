/*
Graphs is a data structure that is made up of 2 things 
1. Nodes
2. Edges
Each node is connected to other nodes via edges and each edge connects two nodes.
Eg: Social Networks, Web Page Links, Flight Routes etc.
There are two types of graphs:      
1. Directed Graphs : A directed graph is a graph in which the edges have a direction. That is, if there is an edge from node A to node B, then you cannot traverse from B to A.
2. Undirected Graphs : An undirected graph is a graph in which the edges do not have a direction. That is, if there is an edge from node A to node B, then you can traverse from B to A.

Directed Edge can create undirected edge by adding two directed edges in opposite directions.
like A --→ B and B --→ A creates an undirected edge between A and B.
Every undirected graph can be represented as a directed graph but every directed graph cannot be represented as an undirected graph.

How to represent a graph in C++
1. Adjacency Matrix
2. Adjacency List
Eg of Adjacency Matrix:
        0 1 2 3
      0 0 1 0 0
      1 0 0 1 0
      2 0 0 0 1
      3 0 0 0 0 
 meaning the graph is of the form 0 → 1 → 2 → 3
Eg of Adjacency List:
  0 -> 1
  1 -> 2
  2 -> 3
  3 -> NULL


Algorithm to find the number of edges connect to a node in a graph:
1. For Adjacency Matrix:
   Count the number of 1's in the row corresponding to the node.
2. For Adjacency List:
   Count the number of nodes in the list corresponding to the node.

*/


/*
BFS: Breadth First Search is an algorithm for traversing or searching tree or graph data structures. It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key') and explores the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.
Can be given in the adjacency list or adjacency matrix form.
Node from which we start the traversal is called the source node.
Algorithm:
1. Create a queue and enqueue the source node.
2. Mark the source node as visited.
3. While the queue is not empty:
   a. Dequeue a node from the queue and print it.
   b. Get all adjacent nodes of the dequeued node. If an adjacent node has not been visited, mark it as visited and enqueue it.
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
Queue is used to keep track of the nodes to be explored next.
Queue follows FIFO (First In First Out) principle.

Implementation of BFS using Adjacency List:
1. Create a graph using an adjacency list.
2. Implement the BFS algorithm as described above.

How to represent a graph using Adjacency List in C++:
struct Graph {
    int V; // Number of vertices
    list<int>* adj; // Pointer to an array containing adjacency lists   
      Graph(int V) {
         this->V = V;
         adj = new list<int>[V];
      }
      void addEdge(int u, int v) {
         adj[u].push_back(v); // Add v to u’s list.
      }
};

How to implement BFS in C++:
void BFS(int s) {
    // Mark all the vertices as not visited
    vector<bool> visited(V, false); 
      // Create a queue for BFS
      queue<int> queue;
      // Mark the current node as visited and enqueue it
      visited[s] = true;
      queue.push(s);
      while(!queue.empty()) {
          // Dequeue a vertex from queue and print it
          s = queue.front();
          cout << s << " ";   
         queue.pop();
         // Get all adjacent vertices of the dequeued vertex s
         for (auto adjecent : adj[s]) {
             if (!visited[adjecent]) {
                 visited[adjecent] = true;
                 queue.push(adjecent);
             }
         }
     }
}
*/

/* 
BFS Implementation in C++ using Adjacency List 
#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n; // Number of nodes
   cin>>n;
   int m; // Number of edges
   cin>>m;
   vector<int> adj[n+5]; // Adjacency List representation
   int i=1;
   while(i<=m)
   {
         int u,v; //Here u and v are the two nodes connected by an edge
         cin>>u>>v;
         adj[u].push_back(v); // Add edge u -> v 
         adj[v].push_back(u); // Add edge v -> u for undirected graph
         i++;
   }

   int source=1; // Starting node for BFS
   int used[n+5]={0}; // To keep track of visited nodes
   int level[n+5]={0}; // To keep track of levels of nodes
   queue<int> q;       // Queue for BFS
   q.push(source);     // Enqueue source node
   used[source]=1;      // Mark source as visited
   level[source] = 0;   // Level of source node is 0
   while(!q.empty()) {
       int s = q.front();  // Get the front node
       cout << s << " ";    //Print the node
       cout<<level[s]<<endl; //Print the level of the node
       q.pop();         // Dequeue the front node

       for(auto adjacent : adj[s]) {
           if(!used[adjacent]) {
               used[adjacent] = 1;  // Mark adjacent node as visited
               q.push(adjacent);    // Enqueue adjacent node
               level[adjacent] = level[s] + 1; // Update level of adjacent node
           }
       }
   }
   return 0;
}

*/



/*
DFS: Depth First Search is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root (or an arbitrary node in the case of a graph) and explores as far as possible along each branch before backtracking.
Trick of DFS is basically to go to each branch from the root node and exhaust the searching there then come back to the root node and go to the next branch and do the same until all the branches are exhausted.
We make the boundary of the branch.
Let us take an example suing Adjacency List representation of graph:
  1 -> 2, 7
  2 -> 3, 4
  3 -> NULL
  4 -> 5, 6
  5 -> NULL
  6 -> NULL
  7 -> 8, 9
  8 -> NULL
  9 -> NULL
the adjacency list represents the following graph:
          1
        /   \
       2     7
      / \   / \
     3   4 8   9
        / \
       5   6
       the Adjacency matrix representation of the above graph is:
         1 2 3 4 5 6 7 8 9
      1  0 1 0 0 0 0 1 0 0
      2  0 0 1 1 0 0 0 0 0
      3  0 0 0 0 0 0 0 0 0
      4  0 0 0 0 1 1 0 0 0
      5  0 0 0 0 0 0 0 0 0
      6  0 0 0 0 0 0 0 0 0
      7  0 0 0 0 0 0 0 1 1
      8  0 0 0 0 0 0 0 0 0
      9  0 0 0 0 0 0 0 0 0

      We will follow the route 1 -> 2 -> 3 then backtrack to 2 then go to 4 -> 5 then backtrack to 4 then go to 6 then backtrack to 4 then backtrack to 2 then backtrack to 1 then go to 7 -> 8 then backtrack to 7 then go to 9.
      the data structure used to store the nodes is stack.
Algorithm:
1. Start by pushing the source node onto a stack.
2. While the stack is not empty:
   a. Pop a node from the stack and print it.
   b. Get all adjacent nodes of the popped node. If an adjacent node has not been visited, mark it as visited and push it onto the stack.
Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
Stack is used to keep track of the nodes to be explored next.
Stack follows LIFO (Last In First Out) principle.

Now let us see the implementation of DFS using Adjacency List in C++:

#include <bits/stdc++.h>
using namespace std; 

int main()
{
   int n; // Number of nodes
   cin>>n;
   int m; // Number of edges
   cin>>m;
   vector<int> adj[n+5]; // Adjacency List representation
   int i=1;
   while(i<=m)
   {
         int u,v; //Here u and v are the two nodes connected by an edge
         cin>>u>>v;
         adj[u].push_back(v); // Add edge u -> v 
         adj[v].push_back(u); // Add edge v -> u for undirected graph
         i++;
   }

   int source=1; // Starting node for DFS
   int used[n+5]={0}; // To keep track of visited nodes
   stack<int> s;       // Stack for DFS
   s.push(source);     // Push source node onto stack
   used[source]=1;      // Mark source as visited

   while(!s.empty()) {
       int v = s.top();  // Get the top node
       cout << v << " ";    //Print the node
       s.pop();         // Pop the top node

       for(auto adjacent : adj[v]) { // here adj[v] gives all the adjacent nodes of v 
           if(!used[adjacent]) {
               used[adjacent] = 1;  // Mark adjacent node as visited
               s.push(adjacent);    // Push adjacent node onto stack
           }
       }
   }
   return 0;
}

Now let us see the implementation using recursion of a DFS traversal in C++:

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005]; // Adjacency List representation
int used[100005]; // To keep track of visited nodes

void DFS(int v) {
    used[v] = 1; // Mark the current node as visited
    cout << v << " "; // Print the node
    for (auto adjacent : adj[v]) { // Get all adjacent nodes
        if (!used[adjacent]) { // If adjacent node is not visited
            DFS(adjacent); // Recur for adjacent node
        }
    }
}
    int main()
{
   int n; // Number of nodes
   cin>>n;
   int m; // Number of edges
   cin>>m;
    int i=1;
    while(i<=m)
    {
         int u,v; //Here u and v are the two nodes connected by an edge
         cin>>u>>v;
         adj[u].push_back(v); // Add edge u -> v 
         adj[v].push_back(u); // Add edge v -> u for undirected graph
         i++;
    }
    int source=1; // Starting node for DFS
    DFS(source); // Call the DFS function
    return 0;
}
*/