#include <bits/stdc++.h> 

int solve(vector<int> &num, int x){
    //base case
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    int ans=INT_MAX;
    for(int i=0;i<num.size();i++){
        ans=min(ans,solve(num,x-num[i]));
    }
    if(ans!=INT_MAX){
        ans=1+ans;
    }
    return ans;
}

int solve1(vector<int> &num,int x,vector<int> &dp){
    //base case
    if(x<0){
        return INT_MAX;
    }
    if(x==0){
        return 0;
    }
    if(dp[x]!=-1){
        return dp[x];
    }
    int mini=INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans=solve1(num,x-num[i],dp);
        if(ans!=INT_MAX){
            mini=min(mini,ans+1);
        }
    }
    dp[x]=mini;
    return dp[x];
}

int solve2(vector<int> &num,int x){
    vector<int> dp(x+1);
    dp[0]=0;
    
    for(int i=1;i<=x;i++){
        int mini=INT_MAX;
        for(int j=0;j<num.size();j++){
            if(i-num[j]>=0){
                mini=min(mini,dp[i-num[j]]);
            }
        }
        if(mini!=INT_MAX){
            mini=1+mini;
        }
        dp[i]=mini;
    }
    if(dp[x]==INT_MAX){
        return -1;
    }
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    // int ans=solve(num,x);
    // if(ans==INT_MAX){
    //     return -1;
    // }
    // else{
    //     return ans;
    // }

    // vector<int> dp(x+1,-1);
    // int ans=solve1(num,x,dp);
    // if(ans==INT_MAX){
    //     return -1;
    // } else {
    //   return ans;
    // }
    return solve2(num,x);
    
}
