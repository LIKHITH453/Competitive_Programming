/*
Cisco OA Graph question:
A system contains pods serving pods numbered from 1 to pods distributed across multiple clusters.
each pod is interconnected by n links represented by the array connection such that if 2 pods are connected directly or indirectly they belong to same cluster. 
Each pod can communicate with other pods in the same cluster directly. 
However, communication between pods in different clusters is not direct and must go through a gateway pod in each cluster. 
If there are no pods in the system return -1.
Process q queries for 2 types: a data sending query of the form "1 pod_id" or a connection failure query of the form "2 pod_id"


Inputs : suppose pods = 3 and n = 2, connection = [[1,2],[2,3]]
q = 5, queries = [[2,2],[1,2],[2,1],[2,3],[1,1]]


*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int c = 0;
vector<set<int>> k(200005);
unordered_map <int,int> g;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    int d = node;
    k[c+1].insert(d); g[d] = c + 1 ;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int pods, n;
    //cout << "Enter number of nodes and edges: ";
    cin >> pods >> n;
    c = 0 ;
    vector<vector<int>> adj(pods + 1); g.clear();
    vector<bool> visited(pods + 1, false);
    for(int i=1;i<=pods;i++){
        k[i].clear();
    }
    //cout << "Enter edges (u v):" << endl;
    for (int i = 1; i <=n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= pods; ++i) {
        if (!visited[i]){
            dfs(i, adj, visited);
            c++;
        }
    }

    //cout << c << endl;
    
    // for (int i = 1; i <= pods; i++) {
    //     cout << "Set " << i << ": ";
    //     for (int x : k[i]) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    
    int q;
    cin>>q;//reading the count of queries.
    for(int i=1;i<=q;i++){
        
        
        int l,r;
        cin>>l>>r;
        if(l==1){
            int c1 = g[r];
            int u = k[c1].size();
            if(u==0){
                cout<<"-1";
            }else{
                if(k[c1].find(r)==k[c1].end()){
                    auto g1 = k[c1].begin();
                    cout<<(*g1);
                }
                
                else
                
                {
                    cout<<r;
                }
            }
            cout<<"\n";
        }
        
        if(l==2){
            int c1 = g[r];
            if(k[c1].find(r)!=k[c1].end()){
            k[c1].erase(k[c1].find(r));}
            
        }
        
        
    }