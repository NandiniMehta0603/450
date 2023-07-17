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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* currNode=root;
        vector<int> nodes;

        while(currNode!=NULL){
            if(currNode->left){
                TreeNode *pred=currNode->left;
                while(pred->right && pred->right!=currNode){
                    pred=pred->right;
                }
                if(pred->right==NULL){
                    pred->right=currNode;
                    currNode=currNode->left;
                }
                else{
                    pred->right=NULL;
                    nodes.push_back(currNode->val);
                    currNode=currNode->right;
                }
            }
            else{
                nodes.push_back(currNode->val);
                currNode=currNode->right;
            }
        }
        return nodes;
    }
};
