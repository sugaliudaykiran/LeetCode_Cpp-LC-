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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> res;
        queue <TreeNode *> qList;

        if (root == nullptr)
        {
            return res;
        }
        
        qList.push(root);
        
        while (!qList.empty())
        {
            int size = qList.size();
            vector <int> temp; 
            
            for (int i=0; i<size; i++)
            {
                TreeNode *cur = qList.front();
                qList.pop();
                temp.push_back(cur -> val);
                
                if (cur -> left != NULL)
                {
                    qList.push(cur -> left);
                }
                if (cur -> right != NULL)
                {
                    qList.push(cur -> right);
                }
            }
            res.push_back(temp);
        }
    return res;
    }
};