#include <cstdio>
#include <vector>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 迭代法最终版本
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> route;
        vector<int> result;
        TreeNode *curr = root, *prev = nullptr;
        if (root == nullptr)
            return result;

        while (true) {
            while (curr != nullptr) {
                route.push(curr);
                curr = curr->left;
            }
            if (!route.size()) break;
            curr = route.top();
            route.pop();
            if (curr->right == nullptr || curr->right == prev) {   //两种情况，开始返回时最后一个结点，以及返回过程中的其他结点
                result.push_back(curr->val);
                prev = curr;
                curr = nullptr;
            } else {
                route.push(curr);       //为了回溯必须重新压栈
                curr = curr->right;
            }
        }
        return result;
    }
};


//leetcode
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }

        stack<TreeNode *> stk;
        TreeNode *prev = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (root->right == nullptr || root->right == prev) {
                res.emplace_back(root->val);
                prev = root;
                root = nullptr;
            } else {
                stk.emplace(root);
                root = root->right;
            }
        }
        return res;
    }
};

//第二次我自己做的
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> result;
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        while (stk.size() || curr) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            if (curr->right && prev != curr->right) {   //因为从右子树返回到curr的时候，如果不加prev != curr->right，那么又会再次进入右结点，造成死循环
                curr = curr->right;
            } else {
                prev = curr;
                result.push_back(curr->val);
                curr = nullptr;    //记得，从右子树返回的时候，一定要将curr清空（强迫下一次再次从stack pop），否则会死循环
                stk.pop();
            }
        }
        return result;
    }
};