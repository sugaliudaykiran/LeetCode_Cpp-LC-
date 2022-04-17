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
    TreeNode *cur = NULL;
    TreeNode* increasingBST(TreeNode* root) {   //  TC -> O(n).. AS -> O(h)..
        if (root == NULL){
            return NULL;
        }
        
        TreeNode *res = new TreeNode(0);
        cur = res;
        inorder(root);
        return res -> right;
    }
    
    void inorder(TreeNode* node){
        if (node == NULL){
            return;
        }
        
        inorder(node -> left);
        node -> left = NULL;
        cur -> right = node;
        cur = node;
        inorder(node -> right);
    }
};

/*      Navie Solution :- Using vector to store the items and makes the right skewed tree.
            TC -> O(n).. AS -> O(n).. where n is no of nodes in the tree..
        
    vector <TreeNode *> res;
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL){
            return NULL;
        }
        inorder(root);
        
        for (int i=0; i<res.size()-1; i++){
            res[i] -> right = res[i+1];
            res[i] -> left = NULL;
        }
        res[res.size()-1] -> right = NULL;
        res[res.size()-1] -> left = NULL;
        
        return res[0];
    }
    void inorder(TreeNode *node){
        if (node == NULL){
            return;
        }
        inorder(node -> left);
        res.push_back(node);
        inorder(node -> right);
    }
*/