class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *curr = root;
        stack<TreeNode*> stk;
        int tmp = 0;
        bool flag = false;
        while (true) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;  
            }
            if (!stk.size())
                break;
            curr = stk.top();
            stk.pop();
            
            if (flag) {
                if (tmp >= curr->val) {
                    return false;
                } else {
                    tmp = curr->val;
                }
            } else {
                tmp = curr->val;
                flag = true;
            }

            curr = curr->right;

        }
        return true;
    }
};

//leetcode 1
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = (long long)INT_MIN - 1;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root -> val <= inorder) {
                return false;
            }
            inorder = root -> val;
            root = root -> right;
        }
        return true;
    }
};

//leetcode 2
class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
