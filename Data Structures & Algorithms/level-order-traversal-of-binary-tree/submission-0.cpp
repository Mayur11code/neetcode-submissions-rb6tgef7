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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> final;
        if(root!=nullptr){
        q.push(root);
        }

        while(!q.empty()){
            int q_size = q.size();
            vector<int> v;
            for(int i = 0; i < q_size; i++){
                TreeNode* top = q.front();
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
                v.push_back(top->val);
                q.pop();

            }
            final.push_back(v);
        }

        return final;
    }
};
