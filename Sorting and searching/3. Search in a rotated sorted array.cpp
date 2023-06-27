class Solution {
public:
    int pivot_index(vector<int> &nums){
        // int ans=-1;
        int start=0;
        int end=nums.size()-1;
        int mid=(start+end)/2;

        while(start<end){
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }
            else{
                end=mid;
            }
            mid=(start+end)/2;
        }
        return start;
    }

    int find(vector<int> &nums,int start,int end,int target){
        int mid=(start+end)/2;

        while(start<=end){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=(start+end)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot=pivot_index(nums);
        // cout<<"pivot "<<pivot<<endl;
        if(target>=nums[pivot] && target<=nums[nums.size()-1]){
            return find(nums,pivot,nums.size()-1,target);
        }
        else{
            return find(nums,0,pivot-1,target);
        }
    }
};
