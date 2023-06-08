//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
#include <bits/stdc++.h>
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    
	    long long max_so_far = arr[0];
    long long min_ending = arr[0];
    long long max_ending = arr[0];

    for (int i = 1; i < n; i++) {
        long long temp_max_ending = max_ending;
        max_ending = max((long long)arr[i], max((long long)arr[i] * max_ending, (long long)arr[i] * min_ending));
        min_ending = min((long long)arr[i], min((long long)arr[i] * temp_max_ending, (long long)arr[i] * min_ending));
        max_so_far = max(max_so_far, max_ending);
    }
    return max_so_far;
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
