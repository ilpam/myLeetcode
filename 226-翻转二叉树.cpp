

//递归
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        if (!root->left && !root->right) {
            return root;
        } else {
            //if (root->left)
                invertTree(root->left);
            //if (root->right)
                invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }
};