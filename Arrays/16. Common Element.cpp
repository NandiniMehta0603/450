//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0,j=0,k=0;
            vector<int> ans;
            if(n1==0 || n2==0 || n3==0){
                return ans;
            }
            
            // while(i<n1 && j<n2 && k<n3){
            //     if(A[i]==B[j] && A[i]==C[k]){
            //         if(A[i]!=ans.back()){
            //             ans.push_back(A[i]);
            //         }
            //         i++;
            //         k++;
            //         j++;
            //     }
            //     else if(A[i]<B[j] || A[i]<C[k]){
            //         i++;
            //     }
            //     else if(A[i]>B[j]){
            //         j++;
            //     }
            //     else if(A[i]>C[k]){
            //         k++;
            //     }
            // }
            while (i < n1 && j < n2 && k < n3) {
        if (A[i] == B[j] && A[i] == C[k]) {
            if (ans.empty() || A[i] != ans.back()) {
                ans.push_back(A[i]);
            }
            i++;
            j++;
            k++;
        } else if (A[i] <= B[j] && A[i] <= C[k]) {
            i++;
        } else if (B[j] <= A[i] && B[j] <= C[k]) {
            j++;
        } else {
            k++;
        }
    }
            return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends
