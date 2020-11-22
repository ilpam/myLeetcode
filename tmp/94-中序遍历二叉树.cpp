//my
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> route;
        TreeNode *curr = root;
        vector<int> result;

        while (true) {
            while (curr) {
                route.push(curr);
                curr = curr->left;
            }
            if (!route.size()) {
                break;
            }
            curr = route.top();
            result.push_back(curr->val);
            curr = curr->right;
            route.pop();
        }
        return result;
    }
};

//leetcode 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};


// DJH 迭代法1 与我的方法类似
// DJH 迭代法2
