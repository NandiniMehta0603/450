class Solution {
public:
    string removeOuterParentheses(string s) {
        int start=0;
        int end=0;
        int left=0;
        string ans="";
        while(end<s.length()){
            if(s[end]=='('){
                left++;
            }
            else{
                left--;
                if(left==0 && start!=end){
                    string temp=s.substr(start+1,end-start-1);
                    ans+=temp;
                    start=end+1;
                }
            }
            end++;
        }
        return ans;
    }
};
