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
    int recurse(TreeNode* root, int max_val){
        if(root==nullptr){
            return 0;
        }
        if(root->val>=max_val){
            return 1 + recurse(root->left, root->val) + recurse(root->right, root->val);
        }
        else{
            return recurse(root->left, max_val) + recurse(root->right, max_val);
        }
    }
    int goodNodes(TreeNode* root) {
        return recurse(root, root->val);
    }
};
