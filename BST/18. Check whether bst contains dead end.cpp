//{ Driver Code Starts
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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void inorder(Node *root,unordered_map<int,int> &mp){
    if(root==NULL){
        return ;
    }
    inorder(root->left,mp);
    mp[root->data]++;
    inorder(root->right,mp);
}
bool solve(Node *root,unordered_map<int,int> mp){
    if(root==NULL){
        return false;
    }
    if(root->right==NULL && root->left==NULL){
        int d=root->data;
        int left_val=d-1;
        int right_val=d+1;
        
        if(left_val==0 && mp.find(right_val)!=mp.end() || mp.find(left_val)!=mp.end() && mp.find(right_val)!=mp.end()){
            // cout<<d<<" ";
            return true;
        }
        else{
            return false;
        }
    }
    bool left_ans=solve(root->left,mp);
    bool right_ans=solve(root->right,mp);
    
    return (left_ans || right_ans);
}
bool isDeadEnd(Node *root)
{
    unordered_map<int,int> mp;
    inorder(root,mp);
    return solve(root,mp);
}
