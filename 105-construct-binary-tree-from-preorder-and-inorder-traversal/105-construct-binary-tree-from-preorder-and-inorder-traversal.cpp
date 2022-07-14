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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIndex = 0;
        
        return helper(preorder, inorder, rootIndex, 0, inorder.size()-1);
    }
    
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &rootIndex, int left, int right)
    {
        if (left > right)
        {
            return NULL;
        }
        
        int pivot = left;
        while (inorder[pivot] != preorder[rootIndex])
        {
            pivot++;
        }
        
        rootIndex++;
        
        TreeNode *rootNode = new TreeNode(inorder[pivot]);
        
        rootNode -> left = helper(preorder, inorder, rootIndex, left, pivot-1);
        rootNode -> right = helper(preorder, inorder, rootIndex, pivot+1, right);

        return rootNode;
    }
};