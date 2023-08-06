#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
void inorder(TreeNode<int> *root,vector<int> &ans){
    if(root==NULL){
        return ;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<int> merge(vector<int> first,vector<int> second){
    int i=0;
    int j=0;
    vector<int> ans;
    
    while(i<first.size() && j<second.size()){
        if(first[i]<=second[j]){
            ans.push_back(first[i]);
            i++;
        }
        else{
            ans.push_back(second[j]);
            j++;
        }
    }
    while(i<first.size()){
        ans.push_back(first[i]);
        i++;
    }
    while(j<second.size()){
        ans.push_back(second[j]);
        j++;
    }
    return ans;
}
TreeNode<int>* construct(vector<int> ans,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=start+(end-start)/2;
    TreeNode<int> *root=new TreeNode<int>(ans[mid]);
    root->left=construct(ans,start,mid-1);
    root->right=construct(ans,mid+1,end);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> in1;
    inorder(root1,in1);
    vector<int> in2;
    inorder(root2,in2);

    vector<int> ino;
    if(in1[0]<=in2[0]){
        ino=merge(in1,in2);
    }
    else{
        ino=merge(in2,in1);
    }

    TreeNode<int> *res=construct(ino,0,ino.size()-1);
    return res;
    
}
