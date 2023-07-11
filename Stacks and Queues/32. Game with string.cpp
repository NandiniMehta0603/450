//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        while(k>0){
            int maxi=INT_MIN;
            char temp;
            for(auto i:mp){
                if(i.second>maxi){
                    maxi=i.second;
                    temp=i.first;
                }
            }
            mp[temp]--;
            k--;
        }
        int ans=0;
        for(auto i:mp){
            int j=i.second;
            ans+=(j*j);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
