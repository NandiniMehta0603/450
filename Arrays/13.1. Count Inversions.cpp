class Solution {
public:
    vector<int> ans;//declare here to avoid tle-->being re-initialised every time
    long long merge(vector<int> &nums,int start,int end){
        int mid=start+(end-start)/2;
        ans.clear();
        // int index=0;
        int index1=start;
        int index2=mid+1;
        long long count=0;
        while(index1<=mid && index2<=end){
            if(nums[index1]<=nums[index2]){
                ans.push_back(nums[index1]);
                index1++;
                // index++;
            }
            else{
                count+=mid-index1+1;
                ans.push_back(nums[index2]);
                index2++;
                // index++;
            }
        }
        while(index1<=mid){
            ans.push_back(nums[index1]);
            index1++;
            // index++;
        }
        while(index2<=end){
            ans.push_back(nums[index2]);
            index2++;
            // index++;
        }
        int index=0;
        for(int i=start;i<=end;i++){
            nums[i]=ans[i-start];
        }
        return count;
    }
    long long solve(vector<int> &nums,int start,int end){
        //base case
        if(start>=end){
            return 0;
        }
        long long ans=0;
        int mid=start+(end-start)/2;
        ans+=solve(nums,start,mid);
        ans+=solve(nums,mid+1,end);
        ans+=merge(nums,start,end);
        return ans;
    }

    bool isIdealPermutation(vector<int>& nums) {
        long long local_inversions=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                local_inversions++;
            }
        }
        long long global_conversions=solve(nums,0,nums.size()-1);
        return (local_inversions==global_conversions)?true:false;
    }
};


