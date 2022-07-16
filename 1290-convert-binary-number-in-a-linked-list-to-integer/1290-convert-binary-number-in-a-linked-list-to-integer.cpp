/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *temp = head;      //  TC -> O(n).. SC -> O(1)..
        
        int res = temp -> val;  //  initialize, for head node's val..
        
        while (temp -> next != NULL)
        {
            res = res << 1 | temp -> next -> val;   //  do "left shift" and do "OR operation by the next node's val"..
            temp = temp -> next;    //  move next node..
        }
        return res;
    }
};