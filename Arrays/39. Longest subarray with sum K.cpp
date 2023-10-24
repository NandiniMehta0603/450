//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int,int> mp;
        int curr_sum=0;
        int maxi=0;
        for(int i=0;i<N;i++){
            curr_sum+=A[i];
            int left=curr_sum-K;
            if(curr_sum==K){
                // maxi=max(maxi,i);
                maxi=i+1;
            }
            if(mp.find(left)!=mp.end()){
                int index=mp[left];
                maxi=max(maxi,i-index);
                // cout<<"At index i: "<<i<<" "<<maxi<<endl;
            }
            if(!mp[curr_sum]){
                
                mp[curr_sum]=i;
                // cout<<"At index: "<<i<<" "<<mp[curr_sum]<<endl;
            }
        }
        
        return maxi;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
