#include <bits/stdc++.h> 
int solve(vector<int> height,int index,int n){
    if(index+1==n-1){
        return abs(height[index]-height[index+1]);
    }
    if(index+2==n-1){
        return abs(height[index]-height[index+2]);
    }
    int first=0;
    if(index+1<n){
        first=abs(height[index]-height[index+1])+solve(height,index+1,n);
    }
    int second=0;
    if(index+2<n){
        second=abs(height[index]-height[index+2])+solve(height,index+2,n);
    }
    return min(first,second);
}
int solve1(vector<int> &height,int index,int n,vector<int> &dp){
    // if(index+1==n-1){
    //     return abs(height[index]-height[index+1]);
    // }
    // if(index+2==n-1){
    //     return abs(height[index]-height[index+2]);
    // }

    // int first=0;
    // if(index+1<n){
    //     first=abs(height[index]+height[index+1])+solve1(height,index+1,n,dp);
    // }
    // int second=0;
    // if(index+2<n){
    //     second=abs(height[index]-height[index+2])+solve1(height,index+2,n,dp);
    // }

    if(index==n-1){
        return 0;
    }
    if(index==n-2){
        return abs(height[index]-height[index+1]);
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int first=abs(height[index]-height[index+1])+solve1(height,index+1,n,dp);
    int second=abs(height[index]-height[index+2])+solve1(height,index+2,n,dp);
    dp[index]=min(first,second);
    return dp[index];
}
int frogJump(int n, vector<int> &heights)
{
    // return solve(heights,0,n);

    vector<int> dp(n,-1);
    return solve1(heights,0,n,dp);
    
}
