class Solution {
public:
    int solve(string &text1,string &text2, int index1,int index2){
        if(index1>=text1.length()){
            return 0;
        }
        if(index2>=text2.length()){
            return 0;
        }
        int ans=0;
        if(text1[index1]==text2[index2]){
            return 1+solve(text1,text2,index1+1,index2+1);
        }

        ans=max(solve(text1,text2,index1+1,index2),solve(text1,text2,index1,index2+1));
        return ans;
    }

    int solve1(string &text1,string &text2,int index1,int index2,vector<vector<int>> &dp){
        if(index1>=text1.length()){
            return 0;
        }
        if(index2>=text2.length()){
            return 0;
        }

        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        int ans=0;
        if(text1[index1]==text2[index2]){
            ans=1+solve1(text1,text2,index1+1,index2+1,dp);
        }
        else{
            ans=max(solve1(text1,text2,index1+1,index2,dp),solve1(text1,text2,index1,index2+1,dp));
        }
        dp[index1][index2]=ans;
        return dp[index1][index2];
    }

    int solve2(string &text1,string &text2){
        int n1=text1.length();
        int n2=text2.length();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int index1=n1-1;index1>=0;index1--){
            for(int index2=n2-1;index2>=0;index2--){
                int ans=0;
                if(text1[index1]==text2[index2]){
                    ans=1+dp[index1+1][index2+1];
                }
                else{
                    ans=max(dp[index1+1][index2],dp[index1][index2+1]);
                }
                dp[index1][index2]=ans;
            }
        }
        return dp[0][0];
    }

    int solve3(string &text1,string &text2){
        int n1=text1.length();
        int n2=text2.length();

        vector<int> curr(n2+1,0);
        vector<int> next(n2+1,0);

        for(int index1=n1-1;index1>=0;index1--){
            for(int index2=n2-1;index2>=0;index2--){
                int ans=0;
                if(text1[index1]==text2[index2]){
                    ans=1+next[index2+1];
                }
                else{
                    ans=max(next[index2],curr[index2+1]);
                }
                curr[index2]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int index1=0;
        int index2=0;

        // return solve(text1,text2,index1,index2);
        // int n1=text1.length();
        // int n2=text2.length();
        // vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        // return solve1(text1,text2,index1,index2,dp);

        // return solve2(text1,text2);

        return solve3(text1,text2);
    }
};
