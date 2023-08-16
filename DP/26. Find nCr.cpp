//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define MOD 1000000007
class Solution{
public:
    int solve(int n,int r,vector<vector<int>> &dp){
        //base case
        if(r>n){
            return 0;
        }
        if(r==0){
            return 1;
        }
        if(r==1){
            return n;
        }
        
        if(dp[n][r]!=-1){
            return dp[n][r];
        }
        
        return dp[n][r]=(solve(n-1,r-1,dp)%MOD+solve(n-1,r,dp)%MOD)%MOD;
    }
    int solve1(int n,int r){
        vector<vector<int>> dp(n+1,vector<int>(r+1,0));
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
            dp[i][1]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=2;j<=r;j++){
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%MOD;
            }
        }
        return dp[n][r];
    }
    // int solve2(int n,int r){
    //     vector<int> curr(r+1,0);
    //     vector<int> prev(r+1,0);
    //     prev[0]=1;
    //     prev[1]=1;
    //     for(int i=1;i<=n;i++){
    //         curr[0]=1;
    //         curr[1]=i;
    //         for(int j=2;j<=r;j++){
    //             curr[j]=(prev[j-1]+prev[j])%MOD;
    //         }
    //         curr=prev;
    //     }
    //     return prev[r];
    // }
    int nCr(int n, int r){
        // vector<vector<int>>dp(n+1,vector<int>(r+1,-1));
        // return solve(n,r,dp);
        
        return solve1(n,r);
        
        // return solve2(n,r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends
