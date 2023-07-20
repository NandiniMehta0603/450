class Solution {
public:
    int solve(vector<int> &values,int i,int j){
        //base case
        if(j-i<=1){
            return 0;
        }
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            int mul=values[i]*values[j]*values[k]+solve(values,i,k)+solve(values,k,j);
            ans=min(mul,ans);
        }
        return ans;
    }
    int solve1(vector<int> &values,int i,int j,vector<vector<int>> &dp){
        //base case
        if(j-i<=1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=i+1;k<j;k++){
            int mul=values[i]*values[j]*values[k]+solve1(values,i,k,dp)+solve1(values,k,j,dp);
            ans=min(mul,ans);
        }
        return dp[i][j]=ans;
    }

    int solve2(vector<int> &values){
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i=n-1;i>=0;i--){
            for(int j=i+2;j<n;j++){
                int ans=INT_MAX;
                for(int k=i+1;k<j;k++){
                    int mul=values[i]*values[j]*values[k]+dp[i][k]+dp[k][j];
                    ans=min(ans,mul);
                }
                dp[i][j]=ans;
            }
        }
        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        // return solve(values,0,n-1);

        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return solve1(values,0,n-1,dp);

        return solve2(values);
    }
};
