//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node,vector<int> adj[],vector<bool> &visited, vector<bool> &dfs_visited){
        visited[node]=true;
        dfs_visited[node]=true;
        
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                bool ans=dfs(nbr,adj,visited,dfs_visited);
                if(ans==true){
                    return true;
                }
            }
            if(visited[nbr]==true && dfs_visited[nbr]==true){
                return true;
            }
        }
        dfs_visited[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        vector<bool> dfs_visited(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=dfs(i,adj,visited,dfs_visited);
                if(ans==true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
