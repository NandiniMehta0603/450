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



// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    void convertDLL(Node *root,Node *&head){
        if(root==NULL){
            return ;
        }
        convertDLL(root->right,head);
        root->right=head;
        if(head!=NULL){
            head->left=root;
        }
        head=root;
        convertDLL(root->left,head);
    }
    Node* mergeDLL(Node *root1,Node *root2){
        Node *head=NULL;
        Node *tail=NULL;
        
        while(root1 && root2){
            if(root1->data<=root2->data){
                if(!head){
                    head=root1;
                }
                else{
                    tail->right=root1;
                    root1->left=tail;
                }
                tail=root1;
                root1=root1->right;
            }
            else{
                if(!head){
                    head=root2;
                }
                else{
                    tail->right=root2;
                    root2->left=tail;
                }
                tail=root2;
                root2=root2->right;
            }
        }
        while(root1!=NULL){
            tail->right=root1;
            root1->left=tail;
            tail=root1;
            root1=root1->right;
        }
        while(root2!=NULL){
            tail->right=root2;
            root2->left=tail;
            tail=root2;
            root2=root2->right;
        }
        return head;
    }
    Node *constructTree(Node *&head,int n){
        if(n<=0 || !head){
            return NULL;
        }
        Node *left=constructTree(head,n/2);
        Node *root=head;
        root->left=left;
        head=head->right;
        root->right=constructTree(head,n-n/2-1);
        return root;
    }
    int count(Node *root){
        int cnt=0;
        Node *fast=root;
        while(fast!=NULL){
            cnt++;
            fast=fast->right;
        }
        return cnt;
    }
    vector<int> solve(Node *root){
        Node *temp=root;
        vector<int> ans;
        while(temp!=NULL){
            ans.push_back(temp->data);
            temp=temp->right;
        }
        return ans;
    }
    vector<int> merge(Node *root1, Node *root2)
    {
       Node *head=NULL;
       convertDLL(root1,head);
       root1=head;
       head=NULL;
       convertDLL(root2,head);
       root2=head;
       
       Node *root=mergeDLL(root1,root2);
       return solve(root);
    //   int m=count(root);
    //   return constructTree(root,m);
    }
};

//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends
