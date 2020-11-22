
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


// 不分层次很简单