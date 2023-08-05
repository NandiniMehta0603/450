//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    int findIndex(string str,int start,int end){
        if(start>end){
            return -1;
        }
        stack<int> st;
        for(int i=start;i<=end;i++){
            if(str[i]=='('){
                st.push(str[i]);
            }
            else if(str[i]==')'){
                st.pop();
                if(st.empty()){
                    return i;
                }
            }
        }
        return -1;
    }
    Node *construct(string str,int start,int end){
        if(start>end){
            return NULL;
        }
        int val=0;
        while(start<=end && str[start]>='0' && str[start]<='9'){
            val=val*10;
            val=val+(str[start]-'0');
            start++;
        }
        Node *root=new Node(val);
        int index=-1;
        if(start<=end && str[start]=='('){
            index=findIndex(str,start,end);
        }
        if(index!=-1){
            root->left=construct(str,start+1,index-1);
            root->right=construct(str,index+2,end-1);
        }
        return root;
    }
    Node *treeFromString(string str){
        Node *root=construct(str,0,str.length()-1);
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
