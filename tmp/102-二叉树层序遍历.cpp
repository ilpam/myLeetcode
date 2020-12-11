
/**
 * 
 * 分为递归解法和迭代解法，两种解法又根据输出格式分两种
 * 还有BFS等其他方法
 * 
 * 
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 迭代法，分层次，加入一个dummy node来区分层次
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        queue<int> valQ;
        TreeNode *curr = root, *dummy = new TreeNode();
        vector<vector<int>> result;
        vector<int> tmpResult;

        if(root == nullptr) return result;

        q.push(curr);
        q.push(dummy);

        valQ.push(curr->val);
        valQ.push(99);

        while (true) {
            if (q.size()) {
                curr = getAndPop(q);
                valQ.pop();
            } else {
                break;
            }

            if (curr == dummy) {
                if (q.size())     // if queue is cleared, not allow to add dummy，否则这里会造成死循环
                    q.push(dummy);
                valQ.push(99);
                result.push_back(tmpResult);
                tmpResult.clear();
            } else {
                tmpResult.push_back(curr->val);
                if (curr->left != nullptr) {
                    q.push(curr->left);
                    valQ.push(curr->left->val);
                }
                    
                if (curr->right != nullptr) {
                    q.push(curr->right);
                    valQ.push(curr->right->val);
                }
    
            }
        }
        return result;
    }

private:
    TreeNode* getAndPop(queue<TreeNode *> &q) {
        TreeNode *ret = q.front();
        q.pop();
        return ret;
    }
};

//第二种做法，记下每一次需要从队列中pop出多少个
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> node_queue;
        vector<vector<int>> result;
        vector<int> tmp_result;
        if (!root) return result;
        node_queue.push(root);
        TreeNode *curr;
        int curr_size = 1, next_size = 0;
        while (node_queue.size()) {
            while (curr_size) {
                curr = node_queue.front();
                node_queue.pop();
                tmp_result.push_back(curr->val);

                if (curr->left) {
                    node_queue.push(curr->left);
                    next_size++;
                }
                if (curr->right) {
                    node_queue.push(curr->right);
                    next_size++;
                }
                curr_size--;
            }
            curr_size = next_size;
            next_size = 0;
            result.push_back(tmp_result);
            tmp_result.clear();
        }
        return result;

    }
};

// 借助dummy node
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> node_queue;
        vector<vector<int>> result;
        vector<int> tmp_result;
        if (!root) return result;

        TreeNode *curr;
        TreeNode *dummy = new TreeNode(0);
        node_queue.push(root);
        node_queue.push(dummy);

        while (node_queue.size()) {
            curr = node_queue.front();
            node_queue.pop();
            if (curr == dummy) {
                if (node_queue.size())     //记得，只有在有东西的情况下才能push dummy，否则死循环
                    node_queue.push(dummy);
                result.push_back(tmp_result);
                tmp_result.clear();
            } else {
                tmp_result.push_back(curr->val);

                if (curr->left) {
                    node_queue.push(curr->left);
                }
                if (curr->right) {
                    node_queue.push(curr->right);
                }
            }
        }
        return result;
    }
};

// dfs方法
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        return result;
    }

    void helper(TreeNode *root, int level) {
        if (!root) return;
        if (result.size() < level+1) {
            // level not created
            result.push_back(vector<int>());

        } 
        result[level].push_back(root->val);
        helper(root->left, level + 1);
        helper(root->right, level + 1);
    }
private:
    vector<vector<int>> result;
};