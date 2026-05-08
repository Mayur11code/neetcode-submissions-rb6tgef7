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
    int max= -99999999;

    int maxSum(TreeNode* root){
        
        if(root == nullptr){
            return 0;
        }

        int lmax = maxSum(root->left);
        int rmax = maxSum(root->right);

        if(lmax + (root->val) + rmax > max){
            max = lmax + rmax + (root->val);
        }
        int maxsub = rmax>lmax ? rmax : lmax;
        
        if(maxsub + root->val > 0){
            return maxsub + root->val;
        }
        return 0;

    }
    

    int maxPathSum(TreeNode* root) {
        int main = maxSum(root);
        if (main >0 && main > max){
            return main;
        }
        return max;
    }

};
