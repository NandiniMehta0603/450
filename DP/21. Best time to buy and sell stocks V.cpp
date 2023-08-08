class Solution {
public:
    int solve1(vector<int>&prices,int fee){
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                int profit=0;
                if(buy==0){
                    int buyKaro=-prices[index]+dp[index+1][1];
                    int ignoreKaro=0+dp[index+1][0];
                    profit=max(buyKaro,ignoreKaro);
                }
                else{
                    int sellKaro=prices[index]+dp[index+1][0]-fee;
                    int ignoreKaro=dp[index+1][1];
                    profit=max(sellKaro,ignoreKaro);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][0];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solve1(prices,fee);
    }
};
