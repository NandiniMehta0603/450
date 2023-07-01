//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    int find_pivot(string S){
	        int n=S.length();
	        int i=n-2;
	        while(S[i+1]<=S[i] && i>=0){
	            i--;
	        }
	        return i;
	    }
		vector<string>find_permutation(string S)
		{   sort(S.begin(),S.end());
		    int pivot=find_pivot(S);
		    vector<string> res;
		    res.push_back(S);
		    while(pivot>=0){
		        for(int i=S.length()-1;i>=0 && pivot>=0;i--){
		            if(S[i]>S[pivot]){
		                swap(S[i],S[pivot]);
		                break;
		            }
		        }
		        reverse(S.begin()+pivot+1,S.end());
		        res.push_back(S);
		        pivot=find_pivot(S);
		    }
		    return res;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
