//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n=nums.size();
	    vector<int> copy=nums;
	    unordered_map<int,int> mp;
	    
	    for(int i=0;i<n;i++){
	        mp[nums[i]]=i;
	    }
	    sort(copy.begin(),copy.end());
	    
	    int i=0;
	    int count=0;
	    while(i<n){
	        if(nums[i]!=copy[i]){
	            count++;
	            int index=mp[copy[i]];
	            mp[nums[i]]=index;
	            mp[nums[index]]=i;
	            
	            swap(nums[i],nums[index]);
	        }
	        i++;
	    }
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
