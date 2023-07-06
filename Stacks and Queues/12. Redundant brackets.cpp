#include <bits/stdc++.h> 
bool findRedundantBrackets(string &s)
{
    int i=0;
    int n=s.length();
    stack<char> st;
    while(i<n){
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            st.push(s[i]);
            i++;
        }
        else{
            if(s[i]==')'){
                if(st.top()=='('){
                    return true;
                }
                else{
                    while(st.top()!='('){
                        st.pop();
                    }
                    st.pop();
                }
                i++;
            }
            else{
                i++;
            }
        }
    }
    return false;
}
