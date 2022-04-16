Great idea!
Before diving into the given solution, you first should know a basic property of BST: inorder traverse of BST will give an ascending sequence of all values.
By slightly modifying the inorder traverse such that we firstly travel right subtree and then left subtree, we can get the descending order of the BST.
That is, before encoutering the current node, we have exactly visited all the values that greater than it. So we just need to set a variable(cur_sum) to keep track the summation of the visited nodes.