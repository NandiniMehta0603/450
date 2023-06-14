class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;

        int i=0;
        while(i<s.length() ){
            if(s[i]=='#' && !st1.empty()){
                st1.pop();
            }
            else if(s[i]!='#'){
                st1.push(s[i]);
            }
            i++;
        }
        i=0;
        while(i<t.length()){
            if(t[i]=='#' && !st2.empty()){
                st2.pop();
            }else if(t[i]!='#'){
                st2.push(t[i]);
            }
            i++;
        }

        while(!st1.empty() && !st2.empty()){
            if(st1.top()!=st2.top()){
                return false;
            }
            else{
                st1.pop();
                st2.pop();
            }
        }
        if(!st1.empty() && st2.empty()){
            // cout<<"top of"<<st1.top();
            return false;
        }
        if(!st2.empty() && st1.empty()){
            // cout<<st2.top();
            return false;
        }

        return true;
    }
};
