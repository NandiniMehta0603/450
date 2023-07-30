//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    class Node{
        public:
        int data;
        int row;
        int col;
        Node(int d,int r,int c){
            this->data=d;
            this->row=r;
            this->col=c;
        }
    };
    class operation{
        public:
        bool operator()(Node *a,Node *b){
            return a->data>b->data;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node*,vector<Node*>,operation> pq;
        for(int i=0;i<K;i++){
            Node *temp=new Node(arr[i][0],i,0);
            pq.push(temp);
        }
        vector<int> ans;
        while(pq.size()>0){
            Node *temp=pq.top();
            pq.pop();
            int d=temp->data;
            int r=temp->row;
            int c=temp->col;
            ans.push_back(d);
            if(c+1<arr[r].size()){
                Node *temp2=new Node(arr[r][c+1],r,c+1);
                pq.push(temp2);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends
