#include <bits/stdc++.h> 
int solve(vector<int> &nums,int index){
    //base case
    if(index>=nums.size()){
        return 0;
    }
    
    int include=nums[index]+solve(nums,index+2);
    int exclude=0+solve(nums,index+1);

    return max(include, exclude);
}
int solve1(vector<int> &nums,int index,vector<int> &dp){
    //base case
    int n=nums.size();
    if(index>=n){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    
    int include=nums[index]+solve1(nums,index+2,dp);
    int exclude=0+solve1(nums,index+1,dp);

    dp[index]=max(include,exclude);
    return dp[index];
}

int solve2(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n+1,0);
    dp[n]=0;
    dp[n-1]=max(nums[n-1],dp[n]);

    for(int index=n-2;index>=0;index--){
        int include=nums[index]+dp[index+2];
        int exclude=0+dp[index+1];
        dp[index]=max(include,exclude);
    }
    return dp[0];
}

int solve3(vector<int> &nums){
    int n=nums.size();
    int prev2=0;
    int prev1=max(nums[n-1],prev2);

    for(int index=n-2;index>=0;index--){
        int include=nums[index]+prev2;
        int exclude=0+prev1;
        int curr=max(include,exclude);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    // return solve(nums,0);

    int n=nums.size();
    // vector<int> dp(n+1,-1);
    // return solve1(nums,0,dp);

    // return solve2(nums);

    return solve3(nums);
}
