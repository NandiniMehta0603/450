//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    class node{
        public:
        int data;
        int index;
        node(int d,int i){
            this->data=d;
            this->index=i;
        }
    };
    class operation{
        public:
        bool operator()(node *a, node *b){
            return a->data<b->data;
        }
    };
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        priority_queue<node*,vector<node*>,operation> pq;
        for(int i=0;i<k;i++){
            pq.push(new node(arr[i],i));
        }
        int i=k;
        vector<int> ans;
        ans.push_back(pq.top()->data);
        while(i<n){
            pq.push(new node(arr[i],i));
            while(!pq.empty() && pq.top()->index<=i-k){
                pq.pop();
            }
            ans.push_back(pq.top()->data);
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends
