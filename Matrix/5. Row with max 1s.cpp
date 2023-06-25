//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	   // vector<int> res;
	   int mini=INT_MAX;
	   int row=INT_MAX;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(arr[i][j]==1){
	               // res.push_back(j);
	               //cout<<"the value of col is "<<j <<endl;
	               if(j<mini){
	                   row=i;
	                   mini=j;
	               }
	               //mini=min(mini,j);
	                break;
	            }
	        }
	    }
	    if(row==INT_MAX){
	        return -1;
	    }
	    
	   // int count=m-mini;
	   // return count;
	   return row;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
