//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};




// } Driver Code Ends
class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    pair<bool,pair<int,int>> solve(Node *root){
        //base case
        if(root==NULL){
            return make_pair(true,make_pair(INT_MAX,INT_MIN));
        }
        if(root!=NULL && root->left==NULL && root->right==NULL){
            return make_pair(true,make_pair(root->data,root->data));
        }
        
        pair<bool,pair<int,int>> left_part=solve(root->left);
        pair<bool,pair<int,int>> right_part=solve(root->right);
        
        bool cond1=(root->data>left_part.second.second)?true:false;
        bool cond2=(root->data<right_part.second.first)?true:false;
        int mini=min(root->data,min(left_part.second.first,right_part.second.first));
        int maxi=max(root->data,max(left_part.second.second,right_part.second.second));
        pair<bool,pair<int,int>> ans=make_pair(true,make_pair(mini,maxi));
        if(left_part.first && right_part.first && cond1 && cond2){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        return ans;
    }
    bool isBST(Node* root) 
    {
        pair<bool,pair<int,int>> ans=solve(root);
        return ans.first;
    }
};




//{ Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
    string s; 
    getline(cin, s);
    Node* root = buildTree(s);
    Solution ob;
    if(ob.isBST(root)) 
        cout<<"1\n";
        
    else
        cout<<"0\n";
   }
   return 0;
}


// } Driver Code Ends
