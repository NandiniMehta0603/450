class Solution {
public:
    int solve(vector<int> &prices, int index, bool buy){
        if(index>=prices.size()){
            return 0;
        }
        int profit=0;
        if(buy==true){
            int buyKaro= -prices[index]+solve(prices,index+1,false);
            int ignoreKaro=solve(prices,index+1,true);
            profit+=max(buyKaro,ignoreKaro);
        }
        else{
            int sellKaro= +prices[index]+solve(prices,index+1,true);
            int ignoreKaro=solve(prices,index+1,false);
            profit+=max(sellKaro,ignoreKaro);
        }
        return profit;
    }
    int solve1(vector<int> &prices,int index,bool buy,vector<vector<int>> &dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }

        int profit=0;
        if(buy){
            int buyKaro= -prices[index]+solve1(prices,index+1,false,dp);
            int ignoreKaro=0+solve1(prices,index+1,true,dp);
            profit+=max(buyKaro,ignoreKaro);
        }
        else{
            int sellKaro=prices[index]+solve1(prices,index+1,true,dp);
            int ignoreKaro=solve1(prices,index+1,false,dp);
            profit+=max(sellKaro,ignoreKaro);
        }
        return dp[index][buy]=profit;
    }
    int solve2(vector<int> &prices){
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                int profit=0;
                if(buy==1){
                    int buyKaro=-prices[index]+dp[index+1][0];
                    int ignoreKaro=dp[index+1][1];
                    profit=max(buyKaro,ignoreKaro);
                }
                else{
                    int sellKaro=prices[index]+dp[index+1][1];
                    int ignoreKaro=dp[index+1][0];
                    profit=max(sellKaro,ignoreKaro);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
    int solve3(vector<int> &prices){
        int n=prices.size();
        vector<int> curr(2,0);
        vector<int> next(2,0);

        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                int profit=0;
                if(buy==1){
                    int buyKaro=-prices[index]+next[0];
                    int ignoreKaro=next[1];
                    profit=max(buyKaro,ignoreKaro);
                }
                else{
                    int sellKaro=prices[index]+next[1];
                    int ignoreKaro=next[0];
                    profit=max(sellKaro,ignoreKaro);
                }
                curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices) {
        // return solve(prices,0,true);


        // int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return solve1(prices,0,true,dp);


        // return solve2(prices);

        return solve3(prices);
    }
};
