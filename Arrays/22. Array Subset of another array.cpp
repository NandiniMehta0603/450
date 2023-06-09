//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> mp1;
    unordered_map<int,int> mp2;
    
    for(int i=0;i<n;i++){
        mp1[a1[i]]++;
    }
    for(int i=0;i<m;i++){
        mp2[a2[i]]++;
    }

    for(auto i:mp2){
        int ele=i.first;
        int freq=i.second;
        auto index=mp1.find(ele);
        if(index==mp1.end() || (*index).second<freq){
          //or index->second<freq
            return "No";
        }
    }
    return "Yes";
}