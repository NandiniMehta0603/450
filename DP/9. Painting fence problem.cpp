#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return ((a%MOD)*1LL * (b%MOD))%MOD;
}
int solve(int n,int k){
    //base case
    if(n==1){
        return k;
    }
    if(n==2){
        return ((k)%MOD + ((k)%MOD*((k-1)%MOD))%MOD)%MOD;
    }
    
    int ans=((k-1)%MOD *((solve(n-1,k)%MOD)+(solve(n-2,k)%MOD)))%MOD;
    return ans;
}

int solve1(int n,int k,vector<int> &dp){
    //base case
    if(n==1){
        return k;
    }
    if(n==2){
        return ((k)%MOD + ((k)%MOD*((k-1)%MOD))%MOD)%MOD;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    // int ans=((k-1)%MOD *((solve1(n-1,k,dp)%MOD)+(solve1(n-2,k,dp)%MOD))%MOD)%MOD;
    int ans=(add(mul(solve1(n-1,k,dp),k-1),mul(solve1(n-2,k,dp),k-1)));
    return dp[n]=ans;
}

int solve2(int n,int k){
    vector<int> dp(n+1,0);

    dp[0]=-1;
    dp[1]=k;
    dp[2]=((k)%MOD + ((k)%MOD*((k-1)%MOD))%MOD)%MOD;

    for(int index=3;index<=n;index++){
        int ans=(add(mul(dp[index-1],k-1),mul(dp[index-2],k-1)));
        dp[index]=ans;
    }
    return dp[n];
}

int solve3(int n,int k){
    int prev2=k;
    int prev1=((k)%MOD + ((k)%MOD*((k-1)%MOD))%MOD)%MOD;

    for(int index=3;index<=n;index++){
        int curr=add(mul(prev1,k-1),mul(prev2,k-1));
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int numberOfWays(int n, int k) {
    // return solve(n,k);

    // vector<int> dp(n+1,-1);
    // return solve1(n,k,dp);

    // return solve2(n,k);

    return solve3(n,k);
}
