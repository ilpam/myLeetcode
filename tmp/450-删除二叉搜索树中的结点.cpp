class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return delete_node(root, key);
    }
    
private:
    TreeNode* delete_node(TreeNode *curr, int key) {
        if (!curr) return curr;

        if (key < curr->val) {
            curr->left = delete_node(curr->left, key);
        } else if (key > curr->val) {
            curr->right = delete_node(curr->right, key);
        } else {
            if (!curr->left && !curr->right) {
                return nullptr;
            }
            if (curr->right) {
                curr->val = succ(curr)->val;
                curr->right = delete_node(curr->right, curr->val);
            } else {
                //assert(curr->left)
                curr->val = prev(curr)->val;
                curr->left = delete_node(curr->left, curr->val);
            }
        }  
        return curr;    
    }

    // assert(root->right)
    TreeNode *succ(TreeNode *root) {
        TreeNode *curr = root->right;
        while (curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    // assert(root->left)
    TreeNode *prev(TreeNode *root) {
        TreeNode *curr = root->left;
        while (curr->right) {
            curr = curr->right;
        }
        return curr;
    }

};


//另一种分类
TreeNode* deleteNode(TreeNode* root, int key) {
	if (!root) return nullptr;   // key not found in bst

	if (key < root->val) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->val) {
		root->right = deleteNode(root->right, key);
	}
	else {
		// case 1:  if the root itself is a leaf node
		if (!root->left && !root->right) {
			return nullptr;
		}

		// case 2:  if the root only has right child
		if (!root->left && root->right) {
			return root->right;
		}

		// case 3:  if the root only has left child
		if (root->left && !root->right) {
			return root->left;
		}

		// case 4:  if the root has both left and right child
		if (root->left && root->right) {
			//  find the successor from right subtree:
			//  1. the successor must be the samllest element in subtree
			//  2. the successor could be either the right or left child of its ancestor
			auto ancestor = root;
			auto successor = root->right;
			while (successor->left) {
				ancestor = successor;
				successor = successor->left;
			}
			root->val = successor->val;
			if (successor == ancestor->right) {
				ancestor->right = deleteNode(successor, successor->val);
			}
			else {
				ancestor->left = deleteNode(successor, successor->val);
			}
		}
	}
	return root;
}