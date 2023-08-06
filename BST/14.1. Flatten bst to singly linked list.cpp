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
void solve(TreeNode<int>* root,TreeNode<int> *&head){
    if(root==NULL){
        return ;
    }
    
    solve(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=NULL;
    }
    head=root;
    solve(root->left,head);
}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int> *head=NULL;
    solve(root,head);
    return head;
}
