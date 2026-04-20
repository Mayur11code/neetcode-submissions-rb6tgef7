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
    bool check(TreeNode* node, int min = INT_MIN, int max = INT_MAX){
        if(node==nullptr){
            return true;
        }
        int rval = node->val;
        if(min<rval && rval<max){
            return (check(node->left, min, rval ) && check(node->right, rval, max));
        }
        else{
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        return check(root);
    }
};
