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
    TreeNode *insertRoot(TreeNode *root,int value){
        if(root==NULL){
            TreeNode *temp=new TreeNode(value);
            return temp;
        }

        if(value<root->val){
            root->left=insertRoot(root->left,value);
        }
        else if(value>root->val){
            root->right=insertRoot(root->right,value);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            root=insertRoot(root,preorder[i]);
        }
        return root;
    }
};
