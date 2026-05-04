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
    int m=0;

    int dia(TreeNode* root){
         if(root == nullptr){
            return 0;
        }

        int l = dia(root->left);
        int r = dia(root->right);

        if(l+r+1 > m){
            m = l+r;
        }

        return max(l+1,r+1);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
       int longest = dia(root);
       if(longest > m){
        return longest-1;
       }
       return m;

    }
};
