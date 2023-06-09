//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    // long long trappingWater(int arr[], int n){
    //     if(n<=2){
    //         return 0;
    //     }
    //     int start=0;
    //     int end=n-1;
    //     int mini=min(arr[start],arr[end]);
    //     int i=1;
    //     long long sum=0;
    //     while(i<end){
    //         if(arr[i]<mini){
    //             sum=sum+(mini-arr[i]);
    //             i++;
    //         }
    //         else if(arr[i]>mini){
    //             mini=min(arr[i],arr[end]);
    //             sum+=sum+(arr[i]-mini);
    //             i++;
    //         }
    //     }
    //     return sum;
    // }
    long long trappingWater(int arr[], int n) {
    if (n <= 2) {
        return 0;
    }

    int left = 0;
    int right = n - 1;
    int leftMax = 0;
    int rightMax = 0;
    long long water = 0;

    while (left < right) {
        if (arr[left] < arr[right]) {
            if (arr[left] > leftMax) {
                leftMax = arr[left];
            } else {
                water += leftMax - arr[left];
            }
            left++;
        } else {
            if (arr[right] > rightMax) {
                rightMax = arr[right];
            } else {
                water += rightMax - arr[right];
            }
            right--;
        }
    }

    return water;
}
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
