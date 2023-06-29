/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include<iostream>
#include<bits/stdc++.h>
// #include<vectors>
using namespace std;

int find_count(vector<int> powers, int target){
    
    int start=0;
    int end=powers.size()-1;
    int mid=(start+end)/2;
    if(target>=powers[end]){
        return end;
    }
    if(target<powers[start]){
        return 0;
    }
    int ans=0;

    while(start<=end){
        if(powers[mid]>target){
            end=mid-1;
        }
        else{
            
            // ans=powers[mid];
            ans=mid;
            // cout<<ans<<" ";
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    // cout<<endl;
    return ans;
}
void solve(int q,vector<int> powers, int round,vector<int> bishu_powers){
    sort(powers.begin(),powers.end());
    for(int i=0;i<round;i++){
        int bishu_power=bishu_powers[i];
        int count=find_count(powers,bishu_power);
        int no_of_soldiers=count+1;
        int cum_pow=0;
        for(int i=0;i<=count;i++){
            cum_pow+=powers[i];
        }
        cout<<no_of_soldiers<<" "<<cum_pow<<endl;
    }
}

int main(){
    //no of soldiers
    int q=0;
    cin>>q;

    //their powers
    vector<int> powers;
    for(int i=0;i<q;i++){
        int pow=0;
        cin>>pow;
        powers.push_back(pow);
    }

    //no of rounds 
    int round=0;
    cin>>round;

    //bishu powers
    vector<int> bishu_powers;
    for(int i=0;i<round;i++){
        int pow=0;
        cin>>pow;
        bishu_powers.push_back(pow);
    }

    solve(q,powers,round,bishu_powers);
    return 0;
}
