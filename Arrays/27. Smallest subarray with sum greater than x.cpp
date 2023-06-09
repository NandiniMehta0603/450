//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // try to find the subsequence just > x
        //then try to minimize it as much as possible
        //store its mini count
        //then if end!=arr.size(); try for next subgroup
        
        int start=0;
        int index=0;
        int sum=0;
        int count=INT_MAX;
        while(index<n){
            if(sum+arr[index]<=x){
                sum+=arr[index];
                index++;
            }
            else{
                //try minimizing it,
                if(sum-arr[start]>x){
                    start++;
                }else{
                    // cout<<index<<" "<<start<<endl;
                    count=min(count,index-start+1);
                    start++;
                    index=start;
                    sum=0;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends
