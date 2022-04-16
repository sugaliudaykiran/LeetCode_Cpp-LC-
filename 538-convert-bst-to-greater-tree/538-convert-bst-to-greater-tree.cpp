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
    int sum = 0;
    
    TreeNode* convertBST(TreeNode* root) {
        if (root) {
            convertBST(root->right);
            root->val += sum;       //  Reverse of In-order Traversal which is (right, root, left).. and update the sum with the val..
            sum = root->val;
            
            convertBST(root->left);
        }
        return root;
    };
};
/*

Great idea!
Before diving into the given solution, you first should know a basic property of BST: inorder traverse of BST will give an ascending sequence of all values.
By slightly modifying the inorder traverse such that we firstly travel right subtree and then left subtree, we can get the descending order of the BST.
That is, before encoutering the current node, we have exactly visited all the values that greater than it. So we just need to set a variable(cur_sum) to keep track the summation of the visited nodes.

*/ 