//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int arr[],int n,int index){
        //base case
        if(index>=n){
            return 0;
        }
        int include=arr[index]+solve(arr,n,index+2);
        int exclude=0+solve(arr,n,index+1);
        
        int ans=max(include,exclude);
        return ans;
    }
    int solve1(int arr[],int n,int index,vector<int> &dp){
        //base case
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        
        int include=arr[index]+solve1(arr,n,index+2,dp);
        int exclude=0+solve1(arr,n,index+1,dp);
        dp[index]=max(include,exclude);
        return dp[index];
    }
    int solve2(int arr[],int n){
        vector<int> dp(n+1,0);
        
        dp[n]=0;
        dp[n-1]=max(dp[n],arr[n-1]);
        for(int i=n-2;i>=0;i--){
            
            dp[i]=max(dp[i+1]+0,dp[i+2]+arr[i]);
        }
        return dp[0];
    }
    
    int solve3(int arr[],int n){
        int prev2=0;
        int prev1=max(prev2,arr[n-1]);
        
        for(int i=n-2;i>=0;i--){
            int curr=max(0+prev1, arr[i]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int FindMaxSum(int arr[], int n)
    {
        int index=0;
        // return solve(arr,n,index);
        
        // vector<int> dp(n+1,-1);
        // return solve1(arr,n,index,dp);
        
        // return solve2(arr,n);
        
        return solve3(arr,n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
