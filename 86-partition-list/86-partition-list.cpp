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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head -> next == NULL)
        {
            return head;
        }
        
        ListNode *h1 = new ListNode(0);
        ListNode *h2 = new ListNode(0);
        
        ListNode *temp = head, *p1 = NULL, *p2 = NULL;
        
        while (temp != NULL)
        {
            if (temp -> val < x)
            {
                if (p1 == NULL)
                {
                    h1 -> next = temp;
                    p1 = temp;
                }
                else 
                {
                    p1 -> next = temp;
                    p1 = p1 -> next;
                }
            }
            
            else
            {
                if (p2 == NULL)
                {
                    h2 -> next = temp;
                    p2 = temp;
                }
                else 
                {
                    p2 -> next = temp;
                    p2 = p2 -> next;
                }
            }
            temp = temp -> next;
        }
        if (h1 -> next == NULL && h2 -> next)
        {
            p2 -> next =  NULL;
            return h2 -> next;
        }
        else if (h2 -> next == NULL && h1 -> next)
        {
            p1 -> next =  NULL;
            return h1 -> next;
        }
        else if (h2 -> next && h1 -> next)
        {
            p1 -> next = NULL;
            p2 -> next = NULL;
            p1 -> next = h2 -> next;
            return h1 -> next;
        }
        return head;
    }
};