#include <bits/stdc++.h> 
int solve(vector<int> weight,vector<int> value,int maxWeight,int index){
	//base case
	if(maxWeight==0){
		return 0;
	}
	if(index==0){
		if(maxWeight-weight[0]>=0){
			return value[0];
		}
		else{
			return 0;
		}
	}
	
	int include=0;
	if(maxWeight-weight[index]>=0){
		include=value[index]+solve(weight,value,maxWeight-weight[index],index-1);
	}
	int exclude=0+solve(weight,value,maxWeight,index-1);
	return max(include,exclude);
}

int solve1(vector<int> weight,vector<int> value,int index,int maxWeight,vector<vector<int>> &dp){
	//base case
	if(index==0){
		if(maxWeight-weight[0]>=0){
			return value[0];
		}
		else{
			return 0;
		}
	}
	if(dp[index][maxWeight]!=-1){
		return dp[index][maxWeight];
	}

	int include=0;
	if(maxWeight-weight[index]>=0){
		include=value[index]+solve1(weight,value,index-1,maxWeight-weight[index],dp);
	}
	int exclude=0+solve1(weight,value,index-1,maxWeight,dp);
	dp[index][maxWeight]=max(include,exclude);
	return dp[index][maxWeight];
}

int solve2(vector<int> weight,vector<int> value,int n,int maxWeight){
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	for(int i=0;i<=maxWeight;i++){
		if(i-weight[0]>=0){
			dp[0][i]=value[0];
		}
	}

	for(int i=1;i<n;i++){
		for(int cap=0;cap<=maxWeight;cap++){
			int include=0;
			if(cap-weight[i]>=0){
				include=value[i]+dp[i-1][cap-weight[i]];
			}
			int exclude=0+dp[i-1][cap];
			dp[i][cap]=max(include,exclude);
		}
	}
	return dp[n-1][maxWeight];
}

int solve3(vector<int> weight,vector<int> value,int n,int maxWeight){
	vector<int> curr(maxWeight+1,0);
	vector<int> prev(maxWeight+1,0);

	for(int i=0;i<=maxWeight;i++){
		if(i-weight[0]>=0){
			prev[i]=value[0];
		}
	}

	for(int index=1;index<n;index++){
		for(int cap=0;cap<=maxWeight;cap++){
			int include=0;
			if(cap-weight[index]>=0){
				include=value[index]+prev[cap-weight[index]];
			}
			int exclude=0+prev[cap];
			curr[cap]=max(include,exclude);
		}
		prev=curr;
	}
	return prev[maxWeight];
}
int solveTabSO2(vector<int> &weight, vector<int> &value, int n, int capacity){
	//step1:
	vector<int> prev(capacity+1,0);
	vector<int> curr(capacity+1,0);


	//step2: analyse the base case
	for(int w=weight[0];w<=capacity;w++){
		if(weight[0]<=capacity)
			curr[w]=value[0];
		else
			curr[w]=0;
	}

	for(int index=1;index<n;index++){
		for(int w=capacity;w>=0;w--){
			int include=0;
			if(weight[index]<=w)
				include=value[index]+curr[w-weight[index]];

			int exclude=0+curr[w];

			curr[w]=max(exclude,include);
			
		}
		
	}
	return curr[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// int n=weight.size();
	int index=n-1;
	// return solve(weight,value,maxWeight,index);
	
	// vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	// return solve1(weight,value,index,maxWeight,dp);

	// return solve2(weight,value,n,maxWeight);

	return solve3(weight,value,n,maxWeight);
}
