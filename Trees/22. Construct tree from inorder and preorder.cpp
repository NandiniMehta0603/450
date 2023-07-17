//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int find(int in[],int ele,int inorderStart,int inorderEnd){
        for(int i=inorderStart;i<=inorderEnd;i++){
            if(in[i]==ele){
                return i;
            }
        }
    }
    Node *solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n){
        //base case
        if(inorderEnd<inorderStart || index>=n){
            return NULL;
        }
        // if(inorderEnd==inorderStart){
        //     ans->data=in[inorderStart];
        //     ans->left=NULL;
        //     ans->right=NULL;
        //     return ans;
        // }
        
        int ele=pre[index++];
        Node *ans=new Node(ele);
        int index1=find(in,ele,inorderStart,inorderEnd);
        
        ans->left=solve(in,pre,index,inorderStart,index1-1,n);
        ans->right=solve(in,pre,index,index1+1,inorderEnd,n);
        
        return ans;
        
    }

    Node* buildTree(int in[],int pre[], int n)
    {   
        int index=0;
        Node *root=solve(in,pre,index,0,n-1,n);
        // root=postOrder(root);
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
