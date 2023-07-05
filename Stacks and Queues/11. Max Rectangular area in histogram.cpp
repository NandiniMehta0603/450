//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<long long> nextSmaller(long long arr[],int n){
        stack<long long> s;
        s.push(-1);
        vector<long long> ans(n);
        
        // for(int i=n-1;i>=0;i--){
        //     if(st.top()<arr[i]){
        //         ans[i]=st.top();
        //         st.push(i);
        //     }
        //     else{
        //         while(st.top()>=arr[i]){
        //             st.pop();
        //         }
        //         ans[i]=st.top();
        //         st.push(i);
        //     }
        // }
        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<long long> prevSmaller(long long arr[],int n){
        stack<long long> s;
        s.push(-1);
        vector<long long> ans(n);
        
        // for(int i=0;i<n;i++){
        //     if(st.top()<arr[i]){
        //         ans[i]=st.top();
        //         st.push(i);
        //     }
        //     else{
        //         while(st.top()>=arr[i]){
        //             st.pop();
        //         }
        //         ans[i]=st.top();
        //         st.push(i);
        //     }
        // }
        for(int i=0;i<n;i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> next(n);
        vector<long long> prev(n);
        
        next=nextSmaller(arr,n);
        
        prev=prevSmaller(arr,n);
        long long area=0;
        for(int i=0;i<n;i++){
            long long height=arr[i];
            
            if(next[i]==-1){
                next[i]=n;
            }
            
            long long breadth= next[i]-prev[i]-1;
            long long new_area=height*breadth;
            area=max(area,new_area);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
