//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int find_maj(int a[],int n){
        int maj_index=0;
        int count=1;
        for(int i=1;i<n;i++){
            if(a[maj_index]==a[i]){
                count++;
            }
            else{
                count--;
                if(count==0){
                    maj_index=i;
                    count=1;
                }
            }
        }
        return a[maj_index];
    }
    bool check(int a[],int n,int ele){
        int count=0;
        for(int i=0;i<n;i++){
            if(a[i]==ele){
                count++;
            }
        }
        if(count>n/2){
            return true;
        }
        return false;
    }
    int majorityElement(int a[], int size)
    {
        int maj_ele=find_maj(a,size);
        if(check(a,size,maj_ele)){
            return maj_ele;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends
