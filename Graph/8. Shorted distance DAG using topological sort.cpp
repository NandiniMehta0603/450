//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int node,unordered_map<int,vector<pair<int,int>>> &adj,unordered_map<int,bool> &visited,stack<int> &st){
         visited[node]=true;
         for(auto nbr:adj[node]){
             if(!visited[nbr.first]){
                 dfs(nbr.first,adj,visited,st);
             }
         }
         st.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         unordered_map<int,vector<pair<int,int>>> adj;
         for(int i=0;i<edges.size();i++){
             int u=edges[i][0];
             int v=edges[i][1];
             int wt=edges[i][2];
             
             adj[u].push_back(make_pair(v,wt));
         }
        stack<int> st;
        unordered_map<int,bool> visited;
        for(int i=0;i<N;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        vector<int> distance(N,INT_MAX);
        distance[0]=0;
        while(st.top()!=0){
            st.pop();
        }
        // st.pop();
        while(!st.empty()){
            int temp=st.top();
            st.pop();
            for(auto nbr:adj[temp]){
                int node=nbr.first;
                int dist=nbr.second;
                if(distance[temp]+dist<distance[node]){
                    distance[node]=distance[temp]+dist;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(distance[i]==INT_MAX){
                distance[i]=-1;
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
