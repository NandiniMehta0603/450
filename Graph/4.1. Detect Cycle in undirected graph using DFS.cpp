//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node,int parent,vector<int> adj[],vector<bool> &visited){
        visited[node]=true;
        for(auto nbr: adj[node]){
            if(nbr==parent){
                continue;
            }
            else if(!visited[nbr]){
                bool ans=dfs(nbr,node,adj,visited);
                if(ans==true){
                    return true;
                }
            }
            else if(visited[nbr] && nbr!=parent){
                // cout<<nbr<<" "<<node<<" ";
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans=dfs(i,-1,adj,visited);
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
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
