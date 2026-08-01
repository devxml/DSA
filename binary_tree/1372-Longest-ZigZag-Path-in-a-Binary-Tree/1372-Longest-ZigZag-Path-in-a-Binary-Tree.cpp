/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* node, int len, int dir) {
        if (!node) return;

        ans = max(ans, len);

        if (dir == 0) {
            dfs(node->right, len + 1, 1);
            dfs(node->left, 1, 0);
        } else{
            dfs(node->left, len + 1, 0);
            dfs(node->right, 1, 1);
        }
    }

    int longestZigZag(TreeNode* root) {
        dfs(root->left, 1, 0);
        dfs(root->right, 1, 1);
        return ans;
    }
};