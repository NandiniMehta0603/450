int longestSubarrayWithSumK(vector<int> a, long long k) {
    int start=0;
    int end=0;
    int ans=0;
    long long sum=0;
    while(end<a.size()){
        sum+=a[end];
        while(sum>k){
            sum-=a[start];
            start++;
        }
        if(sum==k){
            ans=max(ans,end-start+1);
        }
        end++;
    }
    return ans;
}
