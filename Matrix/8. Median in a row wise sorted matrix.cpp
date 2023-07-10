//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

int upper_bound(vector<int>&row,int mid)
    {
        int l=0,h=row.size()-1;
        while(l<=h)
        {
            int md=(l+h)/2;
            if(row[md]<=mid)
            l=md+1;
            else
            h=md-1;
        }
        return l;
    }
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int min_ele=INT_MAX,max_ele=INT_MIN;
        for(int i=0;i<r;i++)
        {
            min_ele=min(min_ele,matrix[0][i]) ;  // first element of each row
            max_ele=max(max_ele,matrix[i][c-1]); // last element of each row
        }
        
        int low=min_ele,high=max_ele;
        
        int median_pos=(r*c+1)/2;
        while(low<=high)
        {
            int mid=(low+high)/2;
            int place=0;
            int count=0;
            for(int i=0;i<r;i++)
            {
                count=upper_bound(matrix[i],mid);
                place=place+count ;
            }
            
            if(place<median_pos)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        
        return low ;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends
