//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

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
//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    pair<int,int> solve(Node *root){
        //
        if(root==NULL){
            return make_pair(0,0);
        }
        if(root!=NULL && root->left==NULL && root->right==NULL){
            return make_pair(1,root->data);
        }
        pair<int,int> left_ans=solve(root->left);
        pair<int,int> right_ans=solve(root->right);
        pair<int,int> ans=make_pair(0,0);
        if(left_ans.first>right_ans.first){
            ans.first=left_ans.first+1;
            ans.second=left_ans.second+root->data;
        }
        else if(left_ans.first==right_ans.first){
            ans.first=left_ans.first+1;
            ans.second=max(left_ans.second,right_ans.second)+root->data;
        }
        else{
            ans.first=right_ans.first+1;
            ans.second=right_ans.second+root->data;
        }
        return ans;
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        if(root==NULL){
            return 0;
        }
        pair<int,int> ans=solve(root);
        return ans.second;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int res = obj.sumOfLongRootToLeafPath(root);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends
