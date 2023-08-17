//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        vector<int> distance(V,INT_MAX);
        distance[S]=0;
        set<pair<int,int>> st;
        st.insert(make_pair(0,S));
        while(st.size()>0){
            auto temp=*(st.begin());
            int node=temp.second;
            int dist=temp.first;
            st.erase(make_pair(dist,node));
            
            for(auto nbr:adj[node]){
                if(dist+nbr[1]<distance[nbr[0]]){
                    if(st.find(make_pair(distance[nbr[0]],nbr[0]))!=st.end()){
                        st.erase(make_pair(distance[nbr[0]],nbr[0]));
                    }
                    distance[nbr[0]]=dist+nbr[1];
                    st.insert(make_pair(distance[nbr[0]],nbr[0]));
                }
            }
        }
        return distance;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
