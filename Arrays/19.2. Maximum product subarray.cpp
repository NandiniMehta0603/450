#include<bits/stdc++.h>

int subarrayWithMaxProduct(vector<int> &arr){
	//travel from left to right to calculate the prefix
	//travel from right to left to calculate the suffix

	int pre=1,suf=1;
	int ans=INT_MIN;
	int n=arr.size();
	for(int i=0;i<n;i++){
		if(pre==0)
			pre=1;
		if(suf==0)
			suf=1;
		pre=pre*arr[i];
		suf=suf*arr[n-i-1];
		ans=max(ans,max(pre,suf));
	}
	return ans;
}
