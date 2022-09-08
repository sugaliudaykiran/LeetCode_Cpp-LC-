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
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> res;
        
        stack<TreeNode*> st;
        // st.push(root);
        
        if (root == NULL)
        {
            return res;
        }
        TreeNode* cur = root;
        
        while (st.empty() == false || cur != NULL)
        {
            while (cur != NULL)
            {
                st.push(cur);
                cur = cur -> left;
            }
            
            cur = st.top();
            st.pop();
            res.push_back(cur -> val);
            cur = cur -> right;

        }
        return res;
    }
};