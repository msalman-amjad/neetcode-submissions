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
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base case 1: An empty subRoot is technically a subtree of any tree
        if (!subRoot) return true;
        
        // Base case 2: If the main tree is empty but subRoot isn't, it can't be a subtree
        if (!root) return false;
        
        // If the trees match starting at the current node, we found our answer
        if (isSameTree(root, subRoot)) return true;
        
        // Otherwise, keep searching down the left and right branches of the main tree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);   


        
    }
};
