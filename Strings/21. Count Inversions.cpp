//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    if(s.length()%2!=0){
        return -1;
    }
    int leftcount=0;
    int rightcount=0;
    
    int i=0;
    while(i<s.length()){
        if(s[i]=='{'){
            leftcount++;
        }
        else{
            if(leftcount==0){
                rightcount++;
            }
            else{
                leftcount--;
            }
        }
        i++;
    }
    int ans = ceil(leftcount / 2.0) + ceil(rightcount / 2.0);
	return ans;
}
