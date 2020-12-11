class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        //if (!root->left && !root->right) return 1;
        queue<TreeNode *> q;
        TreeNode *curr;
        int minDep = 0;
        int currSize, nextSize;
        q.push(root);
        currSize = 1;
        while (q.size()) {
            minDep++;
            for (int i = 0; i < currSize; ++i) {
                curr = q.front();
                q.pop();
                
                if (curr->left) {
                    q.push(curr->left);
                    nextSize++;
                }
                if (curr->right) {
                    q.push(curr->right);
                    nextSize++;
                }
                if (!curr->left && !curr->right) {
                    return minDep;
                }
            }
            currSize = nextSize;
            nextSize = 0;

        }
        return minDep;
    }
};


//下面是深搜
class Solution {
public:
    int result = INT_MAX;
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        helper(root, 1);
        return result;
    }

    void helper(TreeNode *curr, int depth) {
        if (!curr) return;
        if (!curr->left && !curr->right) {
            result = min(depth, result); 
            return;
        }
        
        helper(curr->left, depth + 1);
        helper(curr->right, depth + 1);
    }
};