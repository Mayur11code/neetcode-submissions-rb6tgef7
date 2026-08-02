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
    TreeNode* build(TreeNode* root, int prestart,int preend,int instart,int inend, vector<int>& preorder, vector<int>& inorder){

        if(prestart >= preorder.size()|| prestart > preend || instart>inend){
            return nullptr;
        }

        root->val = preorder[prestart];
        auto it = std::find(inorder.begin() + instart, inorder.begin() + inend, preorder[prestart]);
        int index = std::distance(inorder.begin(), it);


        int lht = index-instart;

        int prelht = prestart + lht;
        
        TreeNode* lnode = new TreeNode();
        TreeNode* rnode = new TreeNode();

        TreeNode* lef =  build(lnode, prestart+1, prelht, instart, index-1, preorder,inorder);
        TreeNode* righ = build(rnode, prelht+1, preend, index+1, inend, preorder,inorder);

        if(lef!=nullptr){
            root->left = lef;
        }
        if(righ!=nullptr){
            root->right = righ;
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

      TreeNode* root = new TreeNode();

      TreeNode* rootnew = build(root,0,preorder.size()-1,0, inorder.size()-1, preorder, inorder);
      return rootnew;

    }
};
