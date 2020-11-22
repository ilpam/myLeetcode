
#include <cstdio>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 *  方法一：BFS， 思想是求出所有结点的路径和值，并保存在一个单独的queue中，然后用BFS遍历所有的结点，需要两个queue
 *  方法二：递归
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        queue<TreeNode *> qTreeNode;
        queue<int> qSum;
        TreeNode *currNode;
        int currSum;
        if (!root) return false;
        qTreeNode.push(root);
        qSum.push(root->val);

        while (qTreeNode.size()) {
            currNode = qTreeNode.front();
            currSum = qSum.front();
            qTreeNode.pop();
            qSum.pop();

            if (!currNode->left && !currNode->right) {
                //leaf node
                if (currSum == sum) return true;
            }


            if (currNode->left) {
                qTreeNode.push(currNode->left);
                qSum.push(currNode->left->val + currSum);
            }

            if (currNode->right) {
                qTreeNode.push(currNode->right);
                qSum.push(currNode->right->val + currSum);
            }

        }
        return false;

    }
};

/*下面是递归的解法*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;

        if (!root->left && !root->right) {
            if (root->val == sum) {
                return true;
            } else {
                return false;
            }
        } else {
            return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
        }
    }
};


/**
 * 
 * 本题本来想用前序遍历来解，不过当中存在很多问题，所以放弃了
 *  以下代码可以通过大部分用例，但是有时候会出问题
 * 
 *
cclass Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        TreeNode *curr = root;
        stack<TreeNode *> stk;
        int curSum = 0;
        //int saveVal = 0;
    
        while (true) {
            while (curr) {
                stk.push(curr);
                curSum += curr->val;
                curr = curr->left;
            }

            // only check on leaf node
            //curSum -= saveVal;
            //saveVal = 0;
            if (sum == curSum) 
                return true;

            if (!stk.size())
                break;
            curr = stk.top();
            stk.pop();
            if (curr->right) {
                curr = curr->right;
            } else {
                if (curr != root)
                    curSum -= curr->val;
                //saveVal = curr->val;
                curr = nullptr;
                
            }
        }
        return false;
    }
};;
*/

int main()
{
    TreeNode test(1);
    Solution s;
    s.hasPathSum(&test, 0);
}