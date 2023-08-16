//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(string s,string t,int i,int j){
        //base case
        if(j==t.size() && i==s.size()){
            if(s==t){
                return 0;
            }
        }
        if(j==t.size() && i<s.size()){
            return s.size()-i;
        }
        if(i==s.size() && j<t.size()){
            return t.size()-j;
        }
        if(s[i]==t[j]){
            return solve(s,t,i+1,j+1);
        }
        int op1=1+solve(s,t,i,j+1);
        int op2=1+solve(s,t,i+1,j);
        int op3=1+solve(s,t,i+1,j+1);
        return min(op1,min(op2,op3));
    }
    int solve1(string s,string t,int i,int j,vector<vector<int>> &dp){
        // if(j==t.size() && i==s.size()){
        //     if(s==t){
        //         return 0;
        //     }
        // }
        if(j==t.size()){
            return s.size()-i;
        }
        if(i==s.size()){
            return t.size()-j;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(s[i]==t[j]){
            return solve1(s,t,i+1,j+1,dp);
        }
        else{
            int op1=1+solve1(s,t,i,j+1,dp);
            int op2=1+solve1(s,t,i+1,j,dp);
            int op3=1+solve1(s,t,i+1,j+1,dp);
            ans=min(op1,min(op2,op3));
        }
        return dp[i][j]=ans;
    }
    int solve2(string s,string t){
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,0));
        for(int j=0;j<t.length();j++){
            dp[s.length()][j]=t.length()-j;
        }
        for(int i=0;i<s.length();i++){
            dp[i][t.length()]=s.length()-i;
        }
        for(int i=s.length()-1;i>=0;i--){
            for(int j=t.length()-1;j>=0;j--){
                int ans=0;
                if(s[i]==t[j]){
                    ans=dp[i+1][j+1];
                }
                else{
                    int op1=1+dp[i][j+1];
                    int op2=1+dp[i+1][j];
                    int op3=1+dp[i+1][j+1];
                    ans=min(op1,min(op2,op3));
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][0];
    }
    int solve3(string s,string t){
        vector<int> curr(t.length()+1,0);
        vector<int> next(t.length()+1,0);
        for(int j=0;j<t.length();j++){
            next[j]=t.length()-j;
        }
        for(int i=s.length()-1;i>=0;i--){
            curr[t.length()]=s.length()-i;
            for(int j=t.length()-1;j>=0;j--){
                int ans=0;
                if(s[i]==t[j]){
                    ans=next[j+1];
                }else{
                    int op1=1+curr[j+1];
                    int op2=1+next[j];
                    int op3=1+next[j+1];
                    ans=min(op1,min(op2,op3));
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int editDistance(string s, string t) {
        int i=0;
        int j=0;
        // return solve(s,t,i,j);
        
        // vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
        // return solve1(s,t,i,j,dp);
        
        // return solve2(s,t);
        
        return solve3(s,t);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
