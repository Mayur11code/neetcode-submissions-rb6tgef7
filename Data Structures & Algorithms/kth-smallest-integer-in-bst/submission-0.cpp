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
    int smallest;
    int sm(TreeNode* root,int k){

        if(root == nullptr || k==0){
            return 0;
        }
        int l = sm(root->left, k);

        k+=l;
        if(k==1){
            smallest = root->val;
        }

        return -1 +  l + sm(root->right,--k);
        
    
    }
    int kthSmallest(TreeNode* root, int k) {
         
       sm(root,k);
        return smallest;
    }
};
