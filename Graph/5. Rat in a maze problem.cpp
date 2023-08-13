//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int n,int row,int col,vector<vector<bool>> &visited,vector<vector<int>> &m){
        if(row>=0 && row<n && col>=0 && col<n && visited[row][col]==false && m[row][col]==1){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>> &m,int n,int i,int j,string output,vector<string> &ans,vector<vector<bool>> &visited){
        if(i==n-1 && j==n-1){
            if(output.length()>0){
                ans.push_back(output);
                return ;
            }
        }
        if(isSafe(n,i+1,j,visited,m)){
            visited[i][j]=true;
            // output+='D';
            solve(m,n,i+1,j,output+'D',ans,visited);
            visited[i][j]=false;
        }
        //left
        if(isSafe(n,i,j-1,visited,m)){
            visited[i][j]=true;
            // output+='L';
            solve(m,n,i,j-1,output+'L',ans,visited);
            visited[i][j]=false;
        }
        //right
        if(isSafe(n,i,j+1,visited,m)){
            visited[i][j]=true;
            // output+='R';
            solve(m,n,i,j+1,output+'R',ans,visited);
            visited[i][j]=false;
        }
        //top
        if(isSafe(n,i-1,j,visited,m)){
            visited[i][j]=true;
            // output+='T';
            solve(m,n,i-1,j,output+'U',ans,visited);
            visited[i][j]=false;
        }
        //bottom
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
	    vector<vector<bool>> visited(n,vector<bool>(n,0));
	    string output="";
	    if(m[0][0]==0){
	        return ans;
	    }
	    solve(m,n,0,0,output,ans,visited);
	    return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
