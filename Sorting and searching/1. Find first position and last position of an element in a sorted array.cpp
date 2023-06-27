//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    int ans=-1;
    vector<int> res;
    while(start<=end)
    {
        if(arr[mid]==x){
            ans=mid;
            end=mid-1;
        }
        else if(arr[mid]>x){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    res.push_back(ans);
    
    start=0;
    end=n-1;
    mid=(start+end)/2;
    ans=-1;
    while(start<=end){
        if(arr[mid]==x){
            ans=mid;
            start=mid+1;
        }
        else if(arr[mid]>x){
            end=mid-1;
        }
        else if(arr[mid]<x){
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    res.push_back(ans);
    
    return res;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
