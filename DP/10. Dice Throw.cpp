//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long solve(int M,int N,int X){
        //base case
        if(X<0){
            return 0;
        }
        if(X==0 && N==0){
            return 1;
        }
        long long int ans=0;
        for(int i=1;i<=M;i++){
            ans+=solve(M,N-1,X-i);
        }
        return ans;
    }
    long long solve1(int M,int N, int X,vector<vector<long long>> &dp){
        //base case
        if(X<0){
            return 0;
        }
        if(X==0 && N==0){
            return 1;
        }
        if(X!=0 && N==0){
            return 0;
        }
        if(dp[N][X]!=-1){
            return dp[N][X];
        }
        long long ans=0;
        for(int i=1;i<=M;i++){
            ans+=solve1(M,N-1,X-i,dp);
        }
        dp[N][X]=ans;
        return dp[N][X];
    }
    
    long long solve2(int M,int N,int X){
        //base case
        vector<vector<long long>> dp(N+1,vector<long long> (X+1,0));
        dp[0][0]=1;
        // for(int i=0;i<=X;i++){
        //     dp[0][i]=0;
        // }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=X;j++){
                long long ans=0;
                for(int k=1;k<=M;k++){
                    if(j-k>=0){
                        ans+=dp[i-1][j-k];
                    }
                }
                dp[i][j]=ans;
            }
        }
        return dp[N][X];
    }
    
    long long solve3(int M,int N,int X){
        vector<long long> curr(X+1,0);
        vector<long long> prev(X+1,0);
        
        prev[0]=1;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=X;j++){
                long long ans=0;
                for(int k=1;k<=M;k++){
                    if(j-k>=0){
                        ans+=prev[j-k];
                    }
                }
                curr[j]=ans;
            }
            prev=curr;
        }
        return prev[X];
    }
    long long noOfWays(int M , int N , int X) {
        // return solve(M,N,X);
        
        // vector<vector<long long>> dp(N+1,vector<long long>(X+1,-1));
        // return solve1(M,N,X,dp);
        
        // return solve2(M,N,X);
        
        return solve3(M,N,X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends
