#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(int t,vector<vector<int>> ranges,vector<int> test){
	for(int i=0;i<t;i++){
		vector<int> range=ranges[i];
		for(int j=0;j<test.size();j++){
			if(test[j]>range[1]-range[0]+1){
				int ans=-1;
				cout<<ans;
			}
			else{
				int lb=range[0];
				int ub=range[1];
				// cout<<lb<<" "<<ub<<" ";
				vector<int> temp;
				for(int k=lb;k<=ub;k++){
					// cout<<k<<" ";
					temp.push_back(k);
				}
				// cout<<"value of j "<<j<<" ";
				cout<<temp[test[j]-1]<<endl;
			}
		}
	}
}
int main(){
	//no of test cases
	int t=0;
	cin>>t;

	//range and kth smallest integer
	int n=0;
	int q=0;
	cin>>n>>q;
	vector<vector<int>> ranges;
	for(int i=0;i<n;i++){
		int lb=0;
		int ub=0;
		cin>>lb>>ub;
		vector<int> temp;
		temp.push_back(lb);
		temp.push_back(ub);
		ranges.push_back(temp);
	}
	vector<int> test;
	for(int i=0;i<q;i++){
		int te=0;
		cin>>te;
		test.push_back(te);
	}

	solve(t,ranges,test);

	return 0;
}
