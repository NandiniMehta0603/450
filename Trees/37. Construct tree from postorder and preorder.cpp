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
    TreeNode* solve(vector<int> pre,vector<int> post,int &preIndex,int start,int end){
        if(start>end || preIndex>=pre.size()){
            return NULL;
        }
        TreeNode* root=new TreeNode(pre[preIndex]);
        preIndex++;
        if(start==end){
            return root;
        }
        int i=0;
        for(i=end;i>=start;i--){
            if(pre[preIndex]==post[i]){
                break;
            }
        }
        root->left=solve(pre,post,preIndex,start,i);
        root->right=solve(pre,post,preIndex,i+1,end-1);
        return root;
        

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex=0;
        int start=0;
        int end=preorder.size()-1;
        return solve(preorder,postorder,preIndex,start,end);
    }
};
