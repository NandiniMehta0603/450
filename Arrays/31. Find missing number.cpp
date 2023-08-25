class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int actual_sum=(n*(n+1))/2;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum==actual_sum){
            return 0;
        }
        else{
            return actual_sum-sum;
        }
    }
};
