class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0;
        int end=0;
        int index=0;
        int n=nums.size();
        int ans=INT_MIN;
        int sum=0;
        while(index<n){
            if(nums[index]==0){
                // start=index;
                end=index;
                int t=k;
                while(end<n && k>=0){
                    if(nums[end]==0 && k>0){
                        sum+=1;
                        k--;
                        ans=max(ans,sum);
                    }
                    else if(nums[end]==1){
                        sum+=1;
                        ans=max(ans,sum);
                    }
                    else if(nums[end]==0 && k==0){
                        break;
                    }
                    end++;
                }
                if(end==n){
                    return ans;
                }
                k=t;
                sum=0;
            }
            sum+=nums[index];
            index++;
            ans=max(ans,sum);
        }
        if(ans==INT_MIN){
            ans=0;
        }
        return ans;
    }
};
