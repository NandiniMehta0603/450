//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // bool check(vector<vector<char>>grid,int i,int j,string word){
    //     int row=grid.size();
    //     int col=grid[0].size();
    //     //check in right--> curr row and next col
    //     if(j<col){
    //         int m=j; 
    //         int n=0;
    //         bool flag=true;
    //         while(m<col && n<word.length()){
    //             if(grid[i][m]!=word[n]){
    //                 flag=false;
    //                 break;
    //             }
    //             else{
    //                 m++;
    //                 n++;
    //             }
    //         }
    //         if(flag==true && n==word.length()){
    //             return true;
    //         }
    //     }
    //     //check in left--> curr row and prev col
    //     if(j>0){
    //         int m=j;
    //         int n=0;
    //         bool flag=true;
    //         while(m>=0 && n<word.length()){
    //             if(grid[i][m]!=word[n]){
    //                 flag=false;
    //                 break;
    //             }else{
    //                 m--;
    //                 n++;
    //             }
    //         }
    //         if(flag==true && n==word.length()){
    //             return true;
    //         }
    //     }
        
        
    //     return false;
    // }
    int x[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
    int y[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };
    
    bool check(vector<vector<char>>grid,int row,int col,string word){
        int R=grid.size();
        int C=grid[0].size();
        
        //base case
        if(grid[row][col]!=word[0]){
            return false;
        }
        
        int len=word.length();
        for(int dir=0;dir<8;dir++){
            int k,rd=row+x[dir],cd=col+y[dir];
            for(k=1;k<len;k++){
                if(rd>=R || rd<0 || cd>=C || cd<0){
                    break;
                }
                if(grid[rd][cd]!=word[k])
                    break;
                    
                rd+=x[dir], cd+=y[dir];
            }
            if(k==len)
                return true;
        }
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    //traverse each row first
	    //if the first character matches, check the rest direction
	    //if all characters matches, store the first index
	    
	    int row=grid.size();
	    int col=grid[0].size();
	    
	    char first=word[0];
	    vector<vector<int>> output;
	    for(int i=0;i<row;i++){
	        for(int j=0;j<col;j++){
	            if(grid[i][j]==first && check(grid,i,j,word)){
                    vector<int> res;
                    res.push_back(i);
                    res.push_back(j);
                    output.push_back(res);
	            }
	        }
	    }
	    return output;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
