class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>=n){
            k=k%n;
        }
        if(k==0){
            return ;
        }
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        start=0;
        end=k-1;
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        start=k;
        end=nums.size()-1;
        while(start<=end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
        return ;
    }
};
