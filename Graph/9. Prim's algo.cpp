//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> keys(V,INT_MAX);
        vector<bool> mst(V,false);
        vector<int> parent(V,-1);
        
        parent[0]=-1;
        keys[0]=0;
        for(int i=0;i<V-1;i++){
            int mini=INT_MAX;
            int u;
            for(int j=0;j<V;j++){
                if(keys[j]<mini && mst[j]!=true){
                    u=j;
                    mini=keys[j];
                }
            }
            mst[u]=true;
            for(auto nbr:adj[u]){
                int node=nbr[0];
                int dist=nbr[1];
                if(dist<keys[node] && mst[node]==false)
                {
                    keys[node]=dist;
                    parent[node]=u;
                }
            }
        }
        int ans=0;
        for(int i=0;i<V;i++){
            // cout<<keys[i]<<" ";
            ans+=keys[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
