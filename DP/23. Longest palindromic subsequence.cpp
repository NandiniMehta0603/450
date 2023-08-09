class Solution {
public:
    int solve(string text1,string text2){
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
                    ans=max(curr[index2+1],next[index2]);
                }
                curr[index2]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());

        return solve(s,rev);

    }
};
