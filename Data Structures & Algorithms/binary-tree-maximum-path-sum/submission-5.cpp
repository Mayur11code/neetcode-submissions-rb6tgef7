class Solution {
    // max_val is passed by reference (&), so every recursive call modifies the same local variable
    int maxSum(TreeNode* root, int& max_val) {
        if (root == nullptr) {
            return 0;
        }

        // We use max(0, ...) to inherently ignore negative branches (they contribute 0)
        int lmax = max(0, maxSum(root->left, max_val));
        int rmax = max(0, maxSum(root->right, max_val));

        // Update the reference variable with the highest standalone path
        if (lmax + rmax + root->val > max_val) {
            max_val = lmax + rmax + root->val;
        }

        // Return the highest single branch to the parent
        return max(lmax, rmax) + root->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        int max_val = -99999999; // Local scope. Thread-safe.
        maxSum(root, max_val);
        return max_val;
    }
};