//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        set<int> st;
        for(int i=0;i<N;i++){
            st.insert(arr[i]);
        }
        set<int> ::iterator it;
        it=st.begin();
        int first=*(it);
        int count=1;
        int max_count=1;
        st.erase(st.begin());
        for(auto it:st){
            // if(first==it){
            //     count=0;
            // }
            if(it-first==1){
                count++;
                max_count=max(max_count,count);
                first=it;
            }
            else if(it-first>0){
                // max_count=max(max_count,count);
                // if(max_count>0){
                //     max_count++;
                // }
                count=1;
                first=it;
            }
        }
        return max_count;
        
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
