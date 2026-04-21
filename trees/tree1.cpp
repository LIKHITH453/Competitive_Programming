/*
Tree: A connected acyclic graph is called a tree. A tree with n nodes has exactly n-1 edges.
Properties of Trees:
1. Unique Path: There is exactly one path between any two nodes in a tree.
2. Leaf Nodes: Nodes with degree 1 are called leaf nodes.
3. Rooted Trees: A tree can be rooted by designating one node as the root.
4. Height and Depth: The height of a tree is the length of the longest path from the root to a leaf. 
The depth of a node is the length of the path from the root
5. Subtrees: Any node and its descendants form a subtree.

Root of the tree: We consider it at the top mosts node of the ress and all the other nodes come below it. 
Either root is defined in the question or we assume it depending on the context.

Child: is the node which is directly connected to it below.

Parent: is the node which is directly connected to it above.

Each node has only 1 single parent but can have multiple children.

Algorithms on Trees:
1. Depth-First Search (DFS): Used for traversing or searching tree data structures.
2. Breadth-First Search (BFS): Another traversal method that explores neighbors level by level.
3. Tree Traversals: Inorder, Preorder, Postorder traversals for binary trees.
4. Lowest Common Ancestor (LCA): Finding the lowest common ancestor of two nodes in a tree.
5. Dynamic Programming on Trees: Solving optimization problems on trees using DP techniques

*/
//DFS implementation to find connected components in an undirected graph
#include <bits/stdc++.h>
using namespace std;