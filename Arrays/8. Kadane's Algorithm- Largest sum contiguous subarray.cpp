//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long max_so_far=INT_MIN;
        long long maxi=0;
        
        for(int i=0;i<n;i++){
            maxi+=arr[i];
            //condition 1: if the msf<maxi-->update msf
            if(max_so_far<maxi){
                max_so_far=maxi;
            }
            //condition 2: if msf<maxi & maxi>0-->leave as it is
            
            //condition 3: if maxi<0--> we do not want to include negative numbers so reinitialise maxi to 0
            if(maxi<0){
                maxi=0;
            }
            
        }
        return max_so_far;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends
