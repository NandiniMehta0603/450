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
        if(x.length()%2!=0){
            return false;
        }
        stack<char> st;
        int i=0;
        while(i<x.length()){
            if(x[i]=='{' || x[i]=='[' || x[i]=='('){
                // cout<<x[i]<<" ";
                st.push(x[i]);
                i++;
            }
            else{
                if(st.empty() && i<x.length() ){
                    // cout<<"2"<<" ";
                    return false;
                }
                else if(x[i]==']' && st.top()!='[' || x[i]== '}' && st.top()!='{' || x[i]==')' && st.top()!='('){
                    // cout<<"1"<<" ";
                    return false;
                }
                
                st.pop();
                i++;
            }
            
            
        }
        if(!st.empty()){
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
