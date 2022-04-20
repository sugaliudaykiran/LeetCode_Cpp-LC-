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
class BSTIterator {
    private:
        stack <TreeNode*> st;       //  Using stack which is LIFO.. 
    
    public:
    BSTIterator(TreeNode* root) {       //  TC -> O(1).. on average..  AS -> O(H).. Atmost at every node..
        pushAll(root);      //  Push left extreme node if there exists.. By Follwing Inorder -> Left, root, right..     
    }
    
    int next() {        //  return top of the stack, if they exits right node then push the node upto left extreme nodes..
        TreeNode* topnode = st.top();
        st.pop();
        pushAll(topnode -> right);
        return topnode -> val;
    }
    
    bool hasNext() {    //  If stack is empty then return true.. else false..
        return !st.empty();
    }
    
    //  Push all for pushing left extreme nodes from the node called..
    private:
        void pushAll(TreeNode* node){
            for (; node != NULL; st.push(node), node = node -> left);
        }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */