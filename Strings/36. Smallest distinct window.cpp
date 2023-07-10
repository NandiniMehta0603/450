//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        unordered_set<char> st;
        for(int i=0;i<str.length();i++){
            st.insert(str[i]);
        }
        int unique=st.size();
        
        unordered_map<char,int> mp;
        int window_size=str.length();
        int start=0;
        int end=start;
        while(end<str.length()){
            while(mp.size()!=unique && end<str.length()){
                mp[str[end]]++;
                end++;
            }
            window_size=min(end-start,window_size);
            mp[str[start]]--;
            if(mp[str[start]]==0){
                mp.erase(str[start]);
            }
            start++;
            
        }
        while(mp.size()==unique){
            window_size=min(end-start,window_size);
            mp[str[start]]--;
            if(mp[str[start]]==0){
                mp.erase(str[start]);
            }
            start++;
        }
        return window_size;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends
