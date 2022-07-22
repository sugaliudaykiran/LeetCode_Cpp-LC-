class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *fdum = new ListNode(0), *bdum = new ListNode(0);
        
        ListNode *front = fdum, *back = bdum, *cur = head;
        
        while (cur != NULL)     //  TC -> O(n).. SC -> O(1)
        {
            if (cur -> val < x)
            {
                front -> next = cur;
                front = cur;
            }
            else 
            {
                back -> next = cur;
                back = cur;
            }
            cur = cur -> next;
        }
        front -> next = bdum -> next;
        back -> next = nullptr;
        return fdum -> next;
    }
};


/*
        Idea:
    The easiest thing to do here is to create separate linked lists for the front and back portions of list we want to return. In order to accomplish that, we should first create some dummy heads (fdum, bdum), then create pointers for the current nodes each of the front, back, and main lists (front, back, curr).

Then we can simply iterate through the main list and stitch together each node to either front or back, depending on the node's value.

Once we reach the end, we just need to stitch together the two sub-lists, making sure to cap off the end of back, and then return our new list, minus the dummy head.

*/

