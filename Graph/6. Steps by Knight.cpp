//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class cell{
    public:
    int x;
    int y;
    int dis;
    
    cell(int x,int y,int dis){
        this->x=x;
        this->y=y;
        this->dis=dis;
    }
};
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int arr1[8]={1,1,-1,-1,-2,-2,2,2};
    int arr2[8]={2,-2,2,-2,-1,1,-1,1};
    bool isOk(int x,int y,int N){
        // int first=op.first;
        // int second=op.second;
        
        if(x<=N && x>0 && y<=N && y>0 ){
            return true;
        }
        else{
            return false;
        }
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	   // unordered_map<pair<int,int>,pair<int,int>> mp;
	   // pair<int,int> start=make_pair(KnightPos[0],KnightPos[1]);
	   // pair<int,int> target=make_pair(TargetPos[0],TargetPos[1]);
	   // unordered_map<pair<int,int>,bool> visited;
	    
	    queue<cell> q;
	    q.push(cell(KnightPos[0],KnightPos[1],0));
	   // visited[start]=true;
	   bool visited[N+1][N+1];
	   for(int i=1;i<=N;i++){
	       for(int j=1;j<=N;j++){
	           visited[i][j]=false;
	       }
	   }
	   visited[KnightPos[0]][KnightPos[1],0]=true;
	   
	    while(!q.empty()){
	        cell temp=q.front();
	        q.pop();
	        if(temp.x==TargetPos[0] && temp.y==TargetPos[1]){
	            return temp.dis;
	            break;
	        }
	        for(int i=0;i<8;i++){
	           // pair<int,int> op=make_pair(temp.first+arr1[i],temp.second+arr2[i]);
	            int x=temp.x+arr1[i];
	            int y=temp.y+arr2[i];
	            if(isOk(x,y,N) && visited[x][y]==false){
	                q.push(cell(x,y,1+temp.dis));
	                visited[x][y]=true;
	               // mp[op]=temp;
	            }
	           // if(op==target){
	           //     break;
	           // }
	        }
	    }
	    
	   // if(mp.find(target)!=mp.end()){
	   //     int count=1;
	   //     pair<int,int> parent=mp[target];
	   //     while(parent!=start){
	   //         parent=mp[parent];
	   //         count++;
	   //     }
	   //     return count;
	   // }
	   // else{
	   //     return -1;
	   // }
	   return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
