//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char s){
        if(s=='^'){
            return 3;
        }
        else if(s=='/' || s=='*'){
            return 2;
        }
        else if(s=='+' || s=='-'){
            return 1;
        }
        else{
            return -1;
        }
    }
    string infixToPostfix(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z' || s[i]>='a' && s[i]<= 'z' || s[i]>='0' && s[i]<='9'){
                ans+=s[i];
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(st.size()>0 && st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                if(st.top()=='('){
                    st.pop();
                }
            }
            else{
                while(st.size()>0 && (prec(st.top())>=prec(s[i]))){
                    ans+=st.top();
                    st.pop();
                    
                }
                st.push(s[i]);
            }
        }
        while(st.size()!=0){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
