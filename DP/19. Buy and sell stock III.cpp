class Solution {
public:
    int solve(vector<int> &prices,int index,int buy,int count){
        //base case
        if(index>=prices.size() || count<=0){
            return 0;
        }

        if(buy==0){
            int buyKaro= -prices[index]+solve(prices,index+1,1,count);
            int ignore=0+solve(prices,index+1,0,count);
            return max(buyKaro,ignore);
        }
        else{
            int sellKaro=+prices[index]+solve(prices,index+1,0,count-1);
            int ignore=0+solve(prices,index+1,1,count);
            return max(sellKaro,ignore);
        }
    }
    int solve1(vector<int> &prices,int index,int buy,int count,vector<vector<vector<int>>> &dp){
        if(index>=prices.size() || count<=0){
            return 0;
        }
        if(dp[index][buy][count]!=-1){
            return dp[index][buy][count];
        }
        if(buy==0){
            int buyKaro=-prices[index]+solve1(prices,index+1,1,count,dp);
            int ignore=solve1(prices,index+1,0,count,dp);
            dp[index][buy][count]= max(ignore,buyKaro);
        }
        else{
            int sellKaro=+prices[index]+solve1(prices,index+1,0,count-1,dp);
            int ignore=0+solve1(prices,index+1,1,count,dp);
            dp[index][buy][count]=max(sellKaro,ignore);
        }
        return dp[index][buy][count];
    }
    int solve2(vector<int> &prices){
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                for(int count=1;count<=2;count++){
                    int profit=0;
                    if(buy==0){
                        int buyKaro=-prices[index]+dp[index+1][1][count];
                        int ignoreKaro=0+dp[index+1][0][count];
                        profit=max(buyKaro,ignoreKaro);
                    }
                    else{
                        int sellKaro=+prices[index]+dp[index+1][0][count-1];
                        int ignoreKaro=dp[index+1][1][count];
                        profit=max(sellKaro,ignoreKaro);
                    }
                    dp[index][buy][count]=profit;
                }
            }
        }
        return dp[0][0][2];
    }
    int solve3(vector<int> &prices){
        vector<vector<int>> curr(2,vector<int>(3,0));
        vector<vector<int>> next(2,vector<int>(3,0));
        int n=prices.size();
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                for(int count=1;count<=2;count++){
                    int profit=0;
                    if(buy==0){
                        int buyKaro=-prices[index]+next[1][count];
                        int ignoreKaro=next[0][count];
                        profit=max(buyKaro,ignoreKaro);
                    }
                    else{
                        int sellKaro=+prices[index]+next[0][count-1];
                        int ignoreKaro=next[1][count];
                        profit=max(sellKaro,ignoreKaro);
                    }
                    curr[buy][count]=profit;
                }
            }
            next=curr;
        }
        return next[0][2];
    }
    int maxProfit(vector<int>& prices) {
        int index=0;
        int buy=0;
        int count=2;
        // return solve(prices,index,buy,count);
        int n=prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        // return solve1(prices,index,buy,count,dp);

        // return solve2(prices);

        return solve3(prices);
    }
};
