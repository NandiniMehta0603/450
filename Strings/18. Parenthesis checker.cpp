//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int n=x.length();
        if(n%2!=0){
            return false;
        }
        stack<char> st;
        int i=0;
        while(i<n){
            //push if opening bracket
            if(x[i]=='(' || x[i]=='{' || x[i]=='['){
                // cout<<i<<x[i]<<endl;
                st.push(x[i]);
                i++;
            }
            else{
                 if (st.empty() && i<n) {
                    //  cout<<"cond1"<<endl;
                return false;
            }
            if (x[i] == ')' && st.top() != '(') {
                // cout<<"cond2"<<endl;
                return false;
            }
            if (x[i] == '}' && st.top() != '{') {
                // cout<<"cond3"<<endl;
                return false;
            }
            if (x[i] == ']' && st.top() != '[') {
                // cout<<"cond4"<<endl;
                return false;
            }
            st.pop();
            i++;
            }
        }
        if(!st.empty()){
            // cout<<"cond5"<<endl;
            return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
