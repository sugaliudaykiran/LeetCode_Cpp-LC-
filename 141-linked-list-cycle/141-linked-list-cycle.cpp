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
    bool hasCycle(ListNode *head) {     //  TC -> O(n).. AS -> O(1)..
        ListNode *slow = head, *fast = head;
        
        if (head == NULL || head -> next == NULL){
            return false;
        }
        while (fast -> next and fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow){
                return true;
            }
        }
        return false;
    }
};