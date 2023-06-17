//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    int count=0;
    int c1=0,c2=0,n=S.length();
    for(int i=0;i<n;i++){
        if(i%2==0 && S[i]=='0'){
            c1++;
        }
        else if(i%2==1 && S[i]=='1'){
            c1++;
        }
        if(i%2==0 && S[i]=='1'){
            c2++;
        }
        else if(i%2==1 && S[i]=='0'){
            c2++;
        }
    }
    count=min(c1,c2);
    return count;
}
