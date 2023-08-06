/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }

        if(key<root->val){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else if(key>root->val){
            root->right=deleteNode(root->right,key);
            return root;
        }

        if(root->left==NULL){
            TreeNode *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            TreeNode *temp=root->left;
            delete root;
            return temp;
        }
        else{
            TreeNode *succParent=root;
            TreeNode *succ=root->right;
            while(succ->left){
                succParent=succ;
                succ=succ->left;
            }

            if(succParent==root){
                root->right=succ->right;
            }
            else{
                succParent->left=succ->right;
            }
            root->val=succ->val;
            delete succ;
            return root;
        }
    }
};
