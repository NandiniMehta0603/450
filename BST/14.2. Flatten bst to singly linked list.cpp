#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int> *root,vector<int> &in){
    if(root==NULL){
        return ;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> in;
    inorder(root,in);
    TreeNode<int> *curr=new TreeNode<int>(in[0]);
    curr->left=NULL;
    TreeNode<int> *temp=curr;
    for(int i=1;i<in.size();i++){
        TreeNode<int> *temp2=new TreeNode<int>(in[i]);
        temp->right=temp2;
        temp=temp2;
        temp->left=NULL;
    }
    return curr;
}
