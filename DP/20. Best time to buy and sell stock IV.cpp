class Solution {
public:
    int solve(vector<int> &prices,int index,int operation,int k){
        if(index>=prices.size() || operation==2*k){
            return 0;
        }
        if(operation%2==0){
            int buyKaro=-prices[index]+solve(prices,index+1,operation+1,k);
            int ignoreKaro=solve(prices,index,operation,k);
            return max(buyKaro,ignoreKaro);
        }
        else{
            int sellKaro=+prices[index]+solve(prices,index+1,operation+1,k);
            int ignoreKaro=solve(prices,index+1,operation,k);
            return max(sellKaro,ignoreKaro);
        }
    }

    int solve1(vector<int> &prices,int index,int operation,int k,vector<vector<int>> &dp){
        if(index>=prices.size() || operation==2*k){
            return 0;
        }
        if(dp[index][operation]!=-1){
            return dp[index][operation];
        }
        int profit=0;
        if(operation%2==0){
            int buyKaro=-prices[index]+solve1(prices,index+1,operation+1,k,dp);
            int ignoreKaro=solve1(prices,index+1,operation,k,dp);
            profit=max(buyKaro,ignoreKaro);
        }
        else{
            int sellKaro=prices[index]+solve1(prices,index+1,operation+1,k,dp);
            int ignoreKaro=solve1(prices,index+1,operation,k,dp);
            profit=max(sellKaro,ignoreKaro);
        }
        return dp[index][operation]=profit;
    }
    int solve2(vector<int> &prices,int k){
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));

        for(int index=n-1;index>=0;index--){
            for(int operation=2*k-1;operation>=0;operation--){
                int profit=0;
                if(operation%2==0){
                    int buyKaro=-prices[index]+dp[index+1][operation+1];
                    int ignoreKaro=dp[index+1][operation];
                    profit=max(buyKaro,ignoreKaro);
                }
                else{
                    int sellKaro=prices[index]+dp[index+1][operation+1];
                    int ignoreKaro=dp[index+1][operation];
                    profit=max(sellKaro,ignoreKaro);
                }
                dp[index][operation]=profit;
            }
        }
        return dp[0][0];
    }
    int solve3(vector<int> &prices,int k){
        vector<int> curr(2*k+1,0);
        vector<int> next(2*k+1,0);
        int n=prices.size();
        for(int index=n-1;index>=0;index--){
            for(int operation=2*k-1;operation>=0;operation--){
                int profit=0;
                if(operation%2==0){
                    int buyKaro=-prices[index]+next[operation+1];
                    int ignoreKaro=next[operation];
                    profit=max(buyKaro,ignoreKaro);
                }
                else{
                    int sellKaro=prices[index]+next[operation+1];
                    int ignoreKaro=next[operation];
                    profit=max(sellKaro,ignoreKaro);
                }
                curr[operation]=profit;
            }
            next=curr;
        }
        return next[0];
    }
    int maxProfit(int k, vector<int>& prices) {
        int index=0;
        int operation=0;
        // return solve(prices,index,operation,k);
        int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2*k+1,-1));
        // return solve1(prices,index,operation,k,dp);

        // return solve2(prices,k);

        return solve3(prices,k);
    }
};
