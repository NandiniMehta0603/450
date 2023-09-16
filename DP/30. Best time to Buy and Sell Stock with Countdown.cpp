class Solution {
public:
    int solve(vector<int> &prices,int index,bool buy,vector<vector<int>> &dp){
        if(index>=prices.size()){
            return 0;
        }
        int profit=0;
        if(buy){
            int buyKaro= -prices[index]+solve(prices,index+1,false,dp);
            int ignoreKaro=0+solve(prices,index+1,true,dp);
            profit=max(buyKaro,ignoreKaro);
        }
        else{
            int sellKaro= +prices[index]+solve(prices,index+2,true,dp);
            int ignoreKaro=0+solve(prices,index+1,false,dp);
            profit=max(sellKaro,ignoreKaro);
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,0,true,dp);
    }
};
