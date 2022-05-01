/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:                                                 //  
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL|| head -> next == NULL){
            return NULL;
        }
        
        ListNode *slow = head, *fast = head, *entry = head;
        
        while (fast -> next and fast -> next -> next){
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if (fast == slow){
                while(entry != slow){       //  There is cycle founds at Entry point..
                    entry = entry -> next;
                    slow = slow -> next;
                }
                return entry;
            }
        }
        return NULL;
    }
};