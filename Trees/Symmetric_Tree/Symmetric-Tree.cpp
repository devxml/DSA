class Solution {
public:

    bool mirror(TreeNode* left, TreeNode* right) {

        // both null -> symmetric
        if(left == NULL && right == NULL)
            return true;

        // one null, one not -> not symmetric
        if(left == NULL || right == NULL)
            return false;

        // values must match
        if(left->val != right->val)
            return false;

        // check mirror structure
        return mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return true;

        return mirror(root->left, root->right);
    }
};