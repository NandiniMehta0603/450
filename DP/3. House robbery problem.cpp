#include <bits/stdc++.h> 

long long solve(vector<int> &nums){
    long long n=nums.size();
    long long prev2=0;
    long long prev1=nums[n-1];

    for(int index=n-2;index>=0;index--){
        long long include=nums[index]+prev2;
        long long exclude=0+prev1;
        long long curr=max(include,exclude);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n=valueInHouse.size();
    if (valueInHouse.size()==1){
        return valueInHouse[0];
    }

    vector<int> first;
    vector<int> second;
    
    for(int i=0;i<n;i++){
        if(i!=0){
            second.push_back(valueInHouse[i]);
        }
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }
    }

    long long ans1=solve(first);
    long long ans2=solve(second);

    return max(ans1,ans2);
}
