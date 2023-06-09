//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans(n);
        stack<long long> st;
        long long i=n-1;
        while(i>=0){
            if(st.empty() && i>=0){
                ans[i]=-1;
                st.push(arr[i]);
                i--;
            }
            else if(!st.empty() && i>=0){
                if(arr[i]<st.top()){
                    ans[i]=st.top();
                    st.push(arr[i]);
                    i--;
                }
                else if(arr[i]>=st.top()){
                    st.pop();
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
