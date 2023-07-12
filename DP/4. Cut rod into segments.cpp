#include<limits.h>
int solve(int n,int x,int y,int z){
    //base case
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    int ans=INT_MIN;

    for(int i=0;i<3;i++){
        int first=solve(n-x,x,y,z);
        int second=solve(n-y,x,y,z);
        int third=solve(n-z,x,y,z);

        ans=max(first,max(second,third));
    }
    if(ans!=INT_MIN){
        ans=ans+1;
    }
    return ans;
}

int solve1(int n,int x,int y,int z,vector<int> &dp){
    //base case
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=INT_MIN;

    for(int i=0;i<3;i++){
        int first=solve1(n-x,x,y,z,dp);
        int second=solve1(n-y,x,y,z,dp);
        int third=solve1(n-z,x,y,z,dp);

        ans=max(first,max(second,third));
    }
    if(ans!=INT_MIN){
        ans+=1;
    }
    return dp[n]=ans;
}

int solve2(int n,int x,int y,int z){
    vector<int> dp(n+1,0);

    dp[0]=0;
    for(int i=1;i<=n;i++){
        int ans=INT_MIN;
        if(i-x>=0){
            ans=max(ans,dp[i-x]);
        }
        if(i-y>=0){
            ans=max(ans,dp[i-y]);
        }
        if(i-z>=0){
            ans=max(ans,dp[i-z]);
        }

        if(ans!=INT_MIN){
            ans+=1;
        }
        dp[i]=ans;
    }
    if(dp[n]==INT_MIN){
        return 0;
    }
    else{
        return dp[n];
    }
}

int cutSegments(int n, int x, int y, int z) {
    
	// int ans=solve(n,x,y,z);
    // if(ans==INT_MIN){
    //     return 0;
    // }
    // else{
    //     return ans;
    // }

    // vector<int> dp(n+1,-1);
    // int ans=solve1(n,x,y,z,dp);
    // if(ans==INT_MIN){
    //     return 0;
    // }
    // else{
    //     return ans;
    // }

    return solve2(n,x,y,z);
    
}
