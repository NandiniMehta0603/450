class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int start=0;
        int end=arr.size();
        int mid=(start+end)/2;
        int ans=0;

        while(start<end){
            if(arr[mid]>arr[mid+1]){
                ans=mid;
                end=mid;
            }
            else{
                start=mid+1;
            }
            mid=(start+end)/2;
        }
        return ans;
    }
};
