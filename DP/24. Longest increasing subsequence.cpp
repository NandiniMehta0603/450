
class Solution
{
    public:
    int solve(int n,int a[],int curr,int prev){
        //base case
        if(curr==n)
            return 0;
        
        //include
        //jab voh element purane vale se bada hoga
        //first element ko humesha include karna hai
        int take=0;
        if(prev==-1 || a[curr]>a[prev]){
            //prev index curr index ban jayega next call mei
            take=1+solve(n,a,curr+1,curr);
        }
        
        //exclude
        //prev remains same as we have not included the curr element
        int notTake=0+solve(n,a,curr+1,prev);
        
        return max(take,notTake);
    }
    
    //there are many overlapping subproblems
    //so we can applydp here
    int solveMem(int n,int a[],int curr,int prev,vector<vector<int>> &dp){
        //base case
        if(curr==n)
            return 0;
        
        if(dp[curr][prev+1]!=-1)
            return dp[curr][prev+1];
        //include
        //jab voh element purane vale se bada hoga
        //first element ko humesha include karna hai
        int take=0;
        if(prev==-1 || a[curr]>a[prev]){
            //prev index curr index ban jayega next call mei
            take=1+solveMem(n,a,curr+1,curr,dp);
        }
        
        //exclude
        //prev remains same as we have not included the curr element
        int notTake=0+solveMem(n,a,curr+1,prev,dp);
        
        return dp[curr][prev+1]=max(take,notTake);//+1 so that it does not give invalid index=-1
    }
    
    int solveTab(int n, int a[]){
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                //include
                int take=0;
                if(prev==-1 || a[curr]>a[prev]){
                    //prev index curr index ban jayega next call mei
                    take=1+dp[curr+1][curr+1];
                }
                
                //exclude
                //prev remains same as we have not included the curr element
                int notTake=0+dp[curr+1][prev+1];
                
                dp[curr][prev+1]=max(take,notTake);
                }
        }
        return dp[0][-1+1];//as -1 is not an index so we add +1
    }
    
    int solveSpaceOP(int n, int a[]){
        
        vector<int> currRow(n+1,0);
        vector<int> nextRow(n+1,0);
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                //include
                int take=0;
                if(prev==-1 || a[curr]>a[prev]){
                    //prev index curr index ban jayega next call mei
                    take=1+nextRow[curr+1];
                }
                
                //exclude
                //prev remains same as we have not included the curr element
                int notTake=0+nextRow[prev+1];
                
                currRow[prev+1]=max(take,notTake);
                }
                //update next row and curr row after each iteration
                nextRow=currRow;
        }
        return nextRow[-1+1];//as -1 is not an index so we add +1
    }
    
    int solveOptimal(int n,int a[]){
        if(n==0){
            return 0;
        }
        
        vector<int> ans;
        //first element always comes in array
        ans.push_back(a[0]);
        
        for(int i=1;i<n;i++){
            if(a[i]>ans.back())
                ans.push_back(a[i]);
            else{
                //find index of just bada element in ans
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    
    
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // return solve(n,a,0,-1);
        
        
        //curr =curr+1 and prev= prev=curr
        //thus both curr and prev changes 
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return solveMem(n,a,0,-1,dp);
        
        // solveTab(n,a);
        
        // solveSpaceOP(n,a);
        
        return solveOptimal(n,a);
    }
};
