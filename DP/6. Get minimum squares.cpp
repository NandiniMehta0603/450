//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solve(vector<int> temp,int n){
	    //base case
	    if(n==0){
	        return 0;
	    }
	    if(n<0){
	        return INT_MAX;
	    }
	    int mini=INT_MAX;
	    for(int i=0;i<temp.size();i++){
	        int ans=solve(temp,n-temp[i]);
	        if(ans!=INT_MAX){
	            mini=min(mini,1+ans);
	        }
	    }
	    return mini;
	}
	
	int solve1(vector<int> temp,int n,vector<int> &dp){
	    //base case
	    if(n==0){
	        return 0;
	    }
	    if(n<0){
	        return INT_MAX;
	    }
	    if(dp[n]!=-1){
	        return dp[n];
	    }
	    
	    int mini=INT_MAX;
	    for(int i=0;i<temp.size();i++){
	        int ans=solve1(temp,n-temp[i],dp);
	        if(ans!=INT_MAX){
	            mini=min(1+ans,mini);
	        }
	    }
	    return dp[n]=mini;
	}
	
	int solve2(vector<int> &temp,int n){
	    vector<int> dp(n+1,INT_MAX);
	    
	    dp[0]=0;
	    for(int i=1;i<=n;i++){
	        int mini=INT_MAX;
	        for(int j=0;j<temp.size();j++){
	            if(i-temp[j]>=0){
	                int ans=dp[i-temp[j]];
	                if(ans!=INT_MAX){
	                    mini=min(mini,1+ans);
	                }
	            }
	        }
	        dp[i]=mini;
	    }
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    vector<int> temp;
	    if(n==1){
	        return 1;
	    }
	    
	    int i=1;
	    while(i*i<=n){
	        temp.push_back(i*i);
	        i++;
	    }
	   // int ans=solve(temp,n);
	   
	   //vector<int> dp(n+1,-1);
	   //int ans=solve1(temp,n,dp);
	   
	   int ans=solve2(temp,n);
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
