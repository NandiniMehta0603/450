//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    bool check(int arr1[],int arr2[]){
        for(int i=0;i<26;i++){
            if(arr1[i]<arr2[i]){
                // cout<<"false"<<" ";
                return false;
            }
        }
        // cout<<"true"<<" ";
        return true;
    }
    string smallestWindow (string s, string p)
    {
        
        int start=0;
        string ans="-1";
        
        int n1=s.length();
        int n2=p.length();
        if(n2>n1){
            return ans;
        }
        int arr2[26]={0};
        for(int i=0;i<n2;i++){
            int index=p[i]-'a';
            arr2[index]++;
        }
        
        int arr1[26]={0};
        for(int i=0;i<n2;i++){
            int index=s[i]-'a';
            arr1[index]++;
        }
        if(check(arr1,arr2) && n1==n2){
            return s;
        }
        int end=n2;
        
        int count=INT_MAX;
        while(end<n1){
            if(check(arr1,arr2)){
                int temp_count=end-start;
                // cout<<start<<end<<temp_count;
                if(temp_count<count){
                    count=temp_count;
                    ans=s.substr(start, temp_count);
                    // cout<<ans<<endl;
                }
                int index=s[start]-'a';
                arr1[index]--;
                start++;
            }
            else{
                int index=s[end]-'a';
                arr1[index]++;
                end++;
            }
        }
        while(start<n1)
        {
            if(check(arr1,arr2)){
                int temp_count=end-start;
                // cout<<start<<end<<temp_count;
                if(temp_count<count){
                    count=temp_count;
                    ans=s.substr(start, temp_count);
                    // cout<<ans<<endl;
                }
                
            }
            int index=s[start]-'a';
            arr1[index]--;
            start++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends
