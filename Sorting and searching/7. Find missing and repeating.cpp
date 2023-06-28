//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // long long len=n;
        // long long cal_sum=(n*(n+1))/2;
        // long long cal_sum_sq=(n*(n+1)*(2*n+1))/6;
        
        // long long repeating =0;
        // long long missing=0;
        
        // for(int i=0;i<n;i++){
        //     cal_sum-=arr[i];
        //     cal_sum_sq-=(long long)arr[i]*(long long)arr[i];
        // }
        // missing =(cal_sum + (cal_sum_sq)/cal_sum)/2;
        // repeating=missing-cal_sum;
        // vector<int> res;
        // res.push_back(repeating);
        // res.push_back(missing);
        // return res;
        
        long long int len = n;
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
     
    for(int i=0;i<arr.size(); i++){
       Sum_N -= (long long int)arr[i];
       Sum_NSq -= (long long int)arr[i]*(long long int)arr[i];
    }
     
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
    repeating= missingNumber - Sum_N;
    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
