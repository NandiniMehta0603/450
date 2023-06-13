
class Solution {
public:

    string countAndSay(int n){
        string ans="1";
        for(int count=2;count<=n;count++){
            string temp="";
            int i=0;
            while(i<ans.length()){
                int start=i;
                while(i<ans.length() && ans[i]==ans[start]){
                    i++;
                }
                temp+=to_string(i-start)+ans[start];
            }
            ans=temp;
        }
        return ans;
    }
};
