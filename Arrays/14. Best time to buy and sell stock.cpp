class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size()-1;
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<=n;i++){
            int diff=prices[i]-mini;
            profit=max(profit,diff);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};
