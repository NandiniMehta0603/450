int solve(int index,vector<int> &days,vector<int> &cost){
    if(index>=days.size()){
        return 0;
    }
    
    int i1=index;
    for(;days[i1]<days[index]+1;i1++);
    int cost1=cost[0]+solve(i1,days,cost);

    int i2=index;
    for(;days[i2]<days[index]+7;i2++);
    int cost2=cost[1]+solve(i2,days,cost);
    
    int i3=index;
    for(;days[i3]<days[index]+30;i3++);
    int cost3=cost[2]+solve(i3,days,cost);
    
    return min(cost1,min(cost2,cost3));
}

int solve1(int index,vector<int> &days,vector<int> &cost,vector<int> &dp){
    //base case
    if(index>=days.size()){
        return 0;
    }
    if(dp[index]!=-1){
        return dp[index];
    }
    int i1=index;
    for(;days[i1]<days[index]+1;i1++);
    int cost1=cost[0]+solve1(i1,days,cost,dp);

    int i2=index;
    for(;days[i2]<days[index]+7;i2++);
    int cost2=cost[1]+solve1(i2,days,cost,dp);

    int i3=index;
    for(;days[i3]<days[index]+30;i3++);
    int cost3=cost[2]+solve1(i3,days,cost,dp);

    dp[index]=min(cost1,min(cost2,cost3));
    return dp[index];
}

int solve2(vector<int> &days,vector<int> &cost){
    int n=days.size();
    vector<int> dp(n+1,0);
    
    dp[n]=0;
    for(int index=n-1;index>=0;index--){
        int i1=index;
        int i2=index;
        int i3=index;

        for(;days[i1]<days[index]+1 && i1<n;i1++);
        int cost1=cost[0]+dp[i1];

        for(;days[i2]<days[index]+7 && i2<n;i2++);
        int cost2=cost[1]+dp[i2];

        for(;days[i3]<days[index]+30 && i3<n;i3++);
        int cost3=cost[2]+dp[i3];

        dp[index]=min(cost1,min(cost2,cost3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // return solve(0,days,cost);

    int index=days.size();
    // vector<int> dp(index+1,-1);
    // return solve1(0,days,cost,dp);

    return solve2(days,cost);
    
}
