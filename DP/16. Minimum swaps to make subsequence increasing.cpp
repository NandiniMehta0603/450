class Solution {
public:
    int solve(vector<int> &nums1,vector<int> &nums2,int index,bool swapped){
        if(index>=nums1.size()){
            return 0;
        }
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        int ans=INT_MAX;

        if(swapped==true){
            swap(prev1,prev2);
        }

        if(nums1[index]>prev1 && nums2[index]>prev2){
            //not swapped
            ans=min(ans,solve(nums1,nums2,index+1,0));
        }
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+solve(nums1,nums2,index+1,1));
        }
        return ans;
    }
    int solve1(vector<int> &nums1,vector<int> &nums2,int index,bool swapped, vector<vector<int>> &dp){
        //base case
        if(index==nums1.size()){
            return 0;
        }
        if(dp[index][swapped]!=-1){
            return dp[index][swapped];
        }
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        if(swapped==true){
            swap(prev1,prev2);
        }
        int ans=INT_MAX;
        if(nums1[index]>prev1 && nums2[index]>prev2){
            ans=min(ans,solve1(nums1,nums2,index+1,0,dp));
        }
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1+solve1(nums1,nums2,index+1,1,dp));
        }

        return dp[index][swapped]=ans;
    }
    int solve2(vector<int> &nums1,vector<int> nums2){
        int n=nums1.size();
        vector<vector<int>> dp(n+1,vector<int>(2,INT_MAX));
        dp[n][0]=0;
        dp[n][1]=0;

        for(int index=n-1;index>=1;index--){
            for(int swapped=1;swapped>=0;swapped--){
                int prev1=nums1[index-1];
                int prev2=nums2[index-1];

                if(swapped==1){
                    swap(prev1,prev2);
                }
                int ans=INT_MAX;
                if(nums1[index]>prev1 && nums2[index]>prev2){
                    ans=min(ans,dp[index+1][0]);
                }
                if(nums1[index]>prev2 && nums2[index]>prev1){
                    ans=min(ans,1+dp[index+1][1]);
                }
                dp[index][swapped]=ans;
            }
        }
        return dp[1][0];
    }
    int solve3(vector<int> &nums1,vector<int> &nums2){
        int n=nums1.size();
        vector<int> curr(2,INT_MAX);
        vector<int> next(2,INT_MAX);

        next[0]=0;
        next[1]=0;

        for(int index=n-1;index>=1;index--){
            for(int swapped=1;swapped>=0;swapped--){
                int prev1=nums1[index-1];
                int prev2=nums2[index-1];

                if(swapped==1){
                    swap(prev1,prev2);
                }
                int ans=INT_MAX;
                if(nums1[index]>prev1 && nums2[index]>prev2){
                    ans=min(ans,next[0]);
                }
                if(nums1[index]>prev2 && nums2[index]>prev1){
                    ans=min(ans,1+next[1]);
                }
                curr[swapped]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped = false;
        int n=nums1.size();
        // int ans=solve(nums1,nums2,1,swapped);

        // vector<vector<int>> dp(n+1,vector<int> (2,-1));
        // int ans=solve1(nums1,nums2,1,swapped,dp);

        // int ans=solve2(nums1,nums2);

        int ans=solve3(nums1,nums2);
        return ans;
    }
};
