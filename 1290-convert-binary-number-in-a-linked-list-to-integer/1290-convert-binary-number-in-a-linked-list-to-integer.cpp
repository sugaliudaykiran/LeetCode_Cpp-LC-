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
        ListNode *temp = head;
        
        int res = temp -> val;      //  Initially, store the head's val.. 
        while (temp -> next != NULL)  //  Keep iterating .. and check temp's next node is 'NOT NULL'..
        {
            res = res * 2 + temp -> next -> val;   //   It not then, doing [res * 2 + X]
            temp = temp -> next; // keep moving to next node..
        }
        return res;
    }
};