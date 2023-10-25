//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        int count=0;
        int i=0;
        int mini=0;
        sort(candies,candies+N);
        while(i<N && count<N){
            mini+=candies[i];
            count+=1;
            count+=K;
            i++;
        }
        i=N-1;
        int maxi=0;
        count=0;
        while(i>=0 && count<N){
            maxi+=candies[i];
            count+=1;
            count+=K;
            i--;
        }
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends
