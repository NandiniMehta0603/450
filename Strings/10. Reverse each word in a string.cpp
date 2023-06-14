//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        stack<char> st;
        string ans="";
        int i=0;
        while(i<s.length()){
            if(s[i]=='.'){
                while(!st.empty()){
                    char temp=st.top();
                    st.pop();
                    ans+=temp;
                }
                ans+=".";
                i++;
            }
            else{
                st.push(s[i]);
                i++;
            }
        }
        while(!st.empty()){
            char temp=st.top();
            st.pop();
            ans+=temp;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
