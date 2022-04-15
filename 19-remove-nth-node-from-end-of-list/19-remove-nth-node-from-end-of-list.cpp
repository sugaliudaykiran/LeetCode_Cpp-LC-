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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode();       //  TC -> O(n)..    AS -> O(1)..
        start -> next = head;
        
        ListNode *slow = start, *fast = start;
        for (int i=1; i<=n; ++i){
            fast = fast -> next;
        }
        
        while (fast -> next != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
        
        slow -> next = slow -> next -> next;
        
        return start -> next;
    }
};


/*
        Navie Solution :-   TC -> O(2n).. AS -> O(1)..
            1) By using cnt of list and make change on (cnt - n) th node..
            2) change is cur -> next = cur -> next -> next;
    
*/ 