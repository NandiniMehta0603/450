class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                int curr_size=st.size();
                ans=max(ans,curr_size);
                st.pop();
            }
        }
        return ans;
    }
};
