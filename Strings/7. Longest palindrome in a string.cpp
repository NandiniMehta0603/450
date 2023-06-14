//gives tle-->can be optimized using dp

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
    string str=S;
    string longest = "";
    int n = str.length();
    int j;
     
    // To store substring which we think can be a palindrome
    string subs = "";
     
    // To store reverse of substring we think can be palindrome
    string subsrev = "";
     
    for(int i = 0; i < n; i++){
        j = n-1;
        while(i < j){
             
            // Checking whether the character at i and j
            // are same.
            // If they are same then that substring can be LPS
            if((str[i] == str[j]) && (longest.length() < (j-i+1))){
               subs = str.substr(i,(j-i+1));
               subsrev = subs;
               reverse(subsrev.begin(), subsrev.end());
               if(subs == subsrev){
                  longest = subs;
               }
            }
            j--;
        }
    }
    
    // If no longest substring then we will return
    // first character
    if(longest.length() == 0){
        longest = str[0];
    }
    // cout << "Longest palindrome substring is: " << longest;
    return longest;
 
    // Return length of LPS
    // return longest.length();
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
