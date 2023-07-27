class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            int sell=prices[i];
            profit=max(sell-buy,profit);
            buy=min(buy,sell);
        }
        return profit;
    }
};
