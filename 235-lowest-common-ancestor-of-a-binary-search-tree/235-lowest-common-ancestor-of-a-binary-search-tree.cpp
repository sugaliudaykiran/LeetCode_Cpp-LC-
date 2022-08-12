/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
        {
            return NULL;
        }
        
        if (root -> val == p -> val || root -> val == q -> val )
        {
            return root;
        }
        
        TreeNode* LCA1 = lowestCommonAncestor(root -> left, p, q);
        TreeNode* LCA2 = lowestCommonAncestor(root -> right, p, q);
        if (LCA1 != NULL && LCA2 != NULL)
        {
            return root;
        }
        else if (LCA2 == NULL)
        {
            return LCA1;
        }
        else
        {
            return LCA2;
        }
    }
};