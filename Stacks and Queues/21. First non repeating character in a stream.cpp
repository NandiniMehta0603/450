//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<int,int> mp;
		    queue<char> st;
		    string ans="";
		    for(int i=0;i<A.length();i++){
		        mp[A[i]]++;
		        st.push(A[i]);
		        
		        while(!st.empty()){
		            if(mp[st.front()]>1){
		                st.pop();
		            }
		            else{
		                ans+=st.front();
		                break;
		            }
		        }
		        if(st.empty()){
		            ans+='#';
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
