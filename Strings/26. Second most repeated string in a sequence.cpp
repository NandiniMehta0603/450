//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        int maxi=0;
        string ans="";
        for(auto i:mp){
            if(i.second>maxi){
                maxi=i.second;
                ans=i.first;
            }
        }
        // mp.remove(ans);
        
        maxi=0;
        string ans2="";
        for(auto i:mp){
            if(i.second>maxi && i.first!=ans){
                maxi=i.second;
                ans2=i.first;
            }
        }
        return ans2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
