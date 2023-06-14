class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";

        int i=0;
        while(i<s.length()){
            if(s[i]!=ans.back()){
                ans.push_back(s[i]);
                i++;
            }
            else if(s[i]==ans.back()){
                ans.pop_back();
                i++;
            }
        }
        return ans;
    }
};
