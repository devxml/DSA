class Solution {
public:
    int ans = -1;

    void inorder(TreeNode* node, int& k) {
        if (!node || k == 0) return;

        inorder(node->left, k);

        k--;
        if (k == 0) {
            ans = node->val;
            return;
        }

        inorder(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};