class Solution {
public:
    bool check(vector<int>& nums) {
        int mini=INT_MAX;
        int shift=-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(mini>nums[i]){
                mini=nums[i];
                shift=i;
            }
            if(i+1<nums.size() && shift==i+1 && mini==nums[i] && nums[i]==nums[i+1]){
                shift=i;
            }
        }
        for(int i=0;i<shift;i++){
            nums.push_back(nums[i]);
        }
        // cout<<shift<<endl;
        for(int i=shift;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]){
                continue;
            }
            else{
                cout<<nums[i]<<" "<<nums[i+1]<<endl;
                return false;
            }
        }
        return true;
    }
};
