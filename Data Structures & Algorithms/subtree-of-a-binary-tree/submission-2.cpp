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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if((q == nullptr && p == nullptr) || ( p != nullptr && q!=nullptr)){
            
        if(p == nullptr || q == nullptr){return true;}

        else if (q->val == p->val){
        bool l = isSameTree(p->left,q->left);
        if(!l){return false;} 
        bool r = isSameTree(p->right,q->right);
        if(!r){ return false;}
        return true;
        }

        }
        
        return false;
        
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root == nullptr && subRoot == nullptr){
            return true;
        }

        if(root && subRoot){

            return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            
        }

        return false;
        

    }
};
