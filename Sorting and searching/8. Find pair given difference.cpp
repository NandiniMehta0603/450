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
    sort(arr,arr+size);
    
    for(int i=size-1;i>0;i--){
        int to_find=arr[i]-n;
        int start=0;
        int end=i-1;
        int mid=(start+end)/2;
        while(start<=end){
            if(arr[mid]==to_find){
                return true;
            }
            else if(arr[mid]>to_find){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=(start+end)/2;
        }
    }
    return false;
    
}
