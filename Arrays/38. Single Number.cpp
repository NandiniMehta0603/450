class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans=ans^nums[i];
        }
        return ans;
    }
};