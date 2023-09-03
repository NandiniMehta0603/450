//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    // sort(arr,arr+size);
    // int start=0;
    // int end=size-1;
    // // cout<<arr[start]<<" "<<arr[end]<<" ";
    // while(start<end){
    //     if(arr[end]-n==arr[start]){
    //         return true;
    //     }
    //     else if(arr[end]-n<arr[start]){
    //         return false;
    //     }
    //     else{
    //         if(end-1>start && arr[end-1]-n>=arr[start]){
    //             end--;
    //         }
    //         else{
    //             start++;
    //         }
    //     }
    // }
    // return false;
    sort(arr,arr+size);
    int start=0;
    int end=1;
    while(end<size){
        int diff=arr[end]-arr[start];
        if(diff==n && start!=end){
            return true;
        }
        else if(diff<n){
            end++;
        }
        else{
            start++;
        }
        if(start==end){
            end++;
        }
    }
    return false;
}
