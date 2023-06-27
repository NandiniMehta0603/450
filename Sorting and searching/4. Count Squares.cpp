//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        int start=0;
        int end=N-1;
        long long mid=(start+end)/2;
        int ans=1;
        while(start<=end){
            if(mid*mid<N){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }
            mid=(start+end)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends
