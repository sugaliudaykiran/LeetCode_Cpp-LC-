/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {   //  In case of given node is pointing to tail..
        if (node -> next == NULL){      //  TC -> O(1)..    AS -> O(1)..
            node = NULL;
        }
        node -> val = node -> next -> val;      //  Here we need to change cur node val to next node val.. and node's next to node's next's next..
        node -> next = node -> next -> next;
    }
};