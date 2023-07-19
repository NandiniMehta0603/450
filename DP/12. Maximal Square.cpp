//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,vector<vector<int>> &mat,int &maxi){
        //base case
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        int right=solve(i,j+1,mat,maxi);
        int down=solve(i+1,j,mat,maxi);
        int diag=solve(i+1,j+1,mat,maxi);
        
        if(mat[i][j]==1){
            int ans=1+min(diag,min(right,down));
            maxi=max(maxi,ans);
            return ans;
        }
        else{
            return 0;
        }
        
    }
    int solve1(int i,int j,vector<vector<int>> &mat, int &maxi,vector<vector<int>> &dp){
        //base case
        if(i>=mat.size() || j>=mat[0].size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int right=solve1(i,j+1,mat,maxi,dp);
        int down=solve1(i+1,j,mat,maxi,dp);
        int diag=solve1(i+1,j+1,mat,maxi,dp);
        
        if(mat[i][j]==1){
            dp[i][j]=1+min(diag,min(right,down));
            maxi=max(maxi,dp[i][j]);
            return dp[i][j];
        }
        else{
            return dp[i][j]=0;
        }
    }
    
    int solve2(vector<vector<int>> &mat,int n,int m,int &maxi){
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                
                int right=dp[i][j+1];
                int down=dp[i+1][j];
                int diag=dp[i+1][j+1];
                
                if(mat[i][j]==1){
                    dp[i][j]=1+min(diag,min(right,down));
                    maxi=max(maxi,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[0][0];
    }
    
    int solve3(vector<vector<int>> &mat,int n,int m,int &maxi){
        vector<int> curr(m+1,0);
        vector<int> next(m+1,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int right=curr[j+1];
                int down=next[j];
                int diag=next[j+1];
                
                if(mat[i][j]==1){
                    curr[j]=1+min(diag,min(right,down));
                    maxi=max(maxi,curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            next=curr;
        }
        
        return next[0];
    }
    int solve4(vector<vector<int>> &mat,int n,int m,int &maxi){
        vector<int> curr(50,0);
        vector<int> next(51,0);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int right=curr[j+1];
                int down=next[j];
                int diag=next[j+1];
                
                if(mat[i][j]==1){
                    curr[j]=1+min(diag,min(right,down));
                    maxi=max(maxi,curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            next=curr;
        }
        
        return next[0];
    }
    
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        // int ans=solve(0,0,mat,maxi);
        
        
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // int ans=solve1(0,0,mat,maxi,dp);
        
        // int ans=solve2(mat,n,m,maxi);
        
        // int ans=solve3(mat,n,m,maxi);
        
        int ans=solve4(mat,n,m,maxi);
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
