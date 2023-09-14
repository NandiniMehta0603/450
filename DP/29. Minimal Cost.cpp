int solve(int n,int k,vector<int> &height,int index){
    if(index==n-1){
        return 0;
    }
    int ans=INT_MAX;
    for(int i=1;i<=k;i++){
        if(index+i==n-1){
            return abs(height[index]-height[index+i]);
        }
        if(index+i<n){
            ans=min(ans,abs(height[index]-height[index+i])+solve(n,k,height,index+i));
        }
    }
    return ans;
}

int solve1(int n,int k,vector<int> &height,int index,vector<int> &dp){
    if(index==n-1){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int ans=INT_MAX;
    for(int i=1;i<=k;i++){
        if(index+i==n-1){
            ans=abs(height[index]-height[index+i]);
        }
        else if(index+i<n){
            ans=min(ans,abs(height[index]-height[index+i])+solve1(n,k,height,index+i,dp));
        }
        dp[index]=ans;
    }
    return dp[index];
}

int solve2(int n,int k,vector<int> &height){
    vector<int> dp(n,0);
    dp[n-1]=0;
    for(int index=n-2;index>=0;index--){
        int ans=INT_MAX;
        for(int i=1;i<=k;i++){
            if(index+i==n-1){
                ans=abs(height[index]-height[index+i]);
            }
            else if(index+i<n){
                ans=min(ans,abs(height[index]-height[index+i])+dp[index+i]);
            }
            dp[index]=ans;
        }
    }
    return dp[0];
}
int minimizeCost(int n, int k, vector<int> &height){
    // return solve(n,k,height,0);

    // vector<int> dp(n,-1);
    // return solve1(n,k,height,0,dp);

    return solve2(n,k,height);
}
