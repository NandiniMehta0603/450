//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       vector<long long> res;
       if(n==1){
           res.push_back(1);
           return res;
       }
        long long prod=1;
        // long long zero_prod=1;
        bool temp=false;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                prod=prod*nums[i];
            }
           else if(nums[i]==0){
                temp=true;
                count++;
            }
        }
        
        for(int i=0;i<n;i++){
            if(nums[i]!=0 && temp==false){
                long long ans=prod/nums[i];
                res.push_back(ans);
            }
            else if(nums[i]!=0 && temp==true || nums[i]==0 && count>1){
                res.push_back(0);
            }
            else if(nums[i]==0 && temp==true && count==1){
                res.push_back(prod);
            }
            
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
