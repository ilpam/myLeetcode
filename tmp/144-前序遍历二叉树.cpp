//前序遍历二叉树

//递归
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root != nullptr)
            traverse(root, result);
        return result;
    }
private:
    void traverse(TreeNode *root, vector<int> &result) {
        result.push_back(root->val);
        if (root->left) {
            traverse(root->left, result);
        }
        if (root->right) {
            traverse(root->right, result);
        }
    }
};


// 迭代法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> route;
        vector<int> result;
        TreeNode *curr = root;

        while (true) {
            while (curr != nullptr) {
                route.push(curr);
                result.push_back(curr->vstkal);
                curr = curr->left;
            }
            if (!route.size()) break;
            curr = route.top();
            curr = curr->right;
            route.pop();
        }
        return result;
    }
}; 

//leetcode 版本
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode*> stk;
        TreeNode* node = root;
        while (!stk.empty() || node != nullptr) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return res;
    }
};

// DJH PPT版本迭代1，但不适合推广到中序和后序
template <typename T, typename VST>
void travPre_I1(BinNode<T> *root, VST &visit)
{
    stack<BinNode<T>*> s;
    if (root) s.push(root);
    while (!s.empty()) {
        root = s.pop();
        visit(root->data);
        if (root->right) s.push(root->right);  //必须先push右结点
        if (root->left) s.push(root->left);
    }
}

// DJH迭代2，与leetcode不同的是，push的时候是压入当前结点的右节点

vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode *> stk;
    vector<int> result;
    TreeNode *curr = root;

    while (true) {
        while (curr) {
            stk.push(curr->right);
            result.push_back(curr->val);
            curr = curr->left;
        }
        if (!stk.size()) break;
        curr = stk.top();
        stk.pop();
    }
    return result;
}


