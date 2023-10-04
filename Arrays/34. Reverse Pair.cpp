class Solution {
public:
    int merge(vector<int> &nums,int start,int mid,int end){
        int i=start;
        int j=mid+1;
        int count=0;
        while(i<=mid && j<=end){
            if((long long)nums[i]>(long long)2*nums[j]){
                count+=(mid-i+1);
                j++;
            }
            else{
                i++;
            }
        }

        sort(nums.begin()+start,nums.begin()+end+1);
        return count;
    }
    int mergeSort(vector<int> &nums,int start,int end){
        if(start>=end){
            return 0;
        }

        int count=0;
        int mid=start+(end-start)/2;
        count+=mergeSort(nums,start,mid);
        count+=mergeSort(nums,mid+1,end);
        count+=merge(nums,start,mid,end);

        return count;
    }
    int reversePairs(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        return mergeSort(nums,start,end);
    }
};
