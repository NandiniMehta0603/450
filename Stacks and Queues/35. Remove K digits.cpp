//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string S, int K) {
        stack<char> st;
        
        string temp="";
        for(int i=0;i<S.length();){
            if(temp.length()==0 && S[i]=='0'){
                i++;
            }
            else{
                temp+=S[i];
                i++;
            }
        }
        // cout<<"Temp is: "<<temp<<endl;
        S=temp;
        st.push(S[0]);
        string ans="";
        for(int i=1;i<S.length();i++){
            while(!st.empty() && K>0 && S[i]<st.top()){
                st.pop();
                K--;
            }
            st.push(S[i]);
            if(st.size()==1 && S[i]=='0'){
                st.pop();
                // K--;
            }
        }
        while(!st.empty() && K>0){
            st.pop();
            K--;
        }
        stack<char> st2;
        while(!st.empty()){
                // cout<<"Pushing this: "<<st.top()<<endl;
                ans.push_back(st.top());
                st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.length()==0){
            return "0";
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends
