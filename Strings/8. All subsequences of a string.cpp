#include <bits/stdc++.h> 
void solve(string str,string output,vector<string> &ans,int index){
    //base case
    if(index>=str.size()){
        if(output.length()>0)
            ans.push_back(output);
        return ;
    }

    //exclude
    solve(str,output,ans,index+1);
    
    output.push_back(str[index]);
    solve(str,output,ans,index+1);
}

vector<string> subsequences(string str){
	
	vector<string> ans;
    int index=0;
    string output="";
    solve(str,output,ans,index);
    return ans;
	
}
