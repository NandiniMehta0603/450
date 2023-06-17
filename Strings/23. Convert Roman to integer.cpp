//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int value(char r){
        if(r=='I'){
            return 1;
        }
        if(r=='V'){
            return 5;
        }
        if(r=='X'){
            return 10;
        }
        if(r=='L'){
            return 50;
        }
        if(r=='C'){
            return 100;
        }
        if(r=='D'){
            return 500;
        }
        if(r=='M'){
            return 1000;
        }
        return -1;
    }
    int romanToDecimal(string &str) {
        int i=str.length()-1;
        int res=value(str[i]);
        while(i>0){
            int val1=value(str[i]);
            int val2=value(str[i-1]);
            if(val1<=val2){
                res=res + val2;
                i--;
            }
            else {
                res=res - val2;
                i--;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
