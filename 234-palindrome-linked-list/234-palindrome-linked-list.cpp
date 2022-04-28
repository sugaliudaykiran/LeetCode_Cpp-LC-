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
private:
    ListNode* byReverse(ListNode* head){
        ListNode* prev = NULL, *nex = NULL;
        while (head != NULL){
            nex = head -> next;
            head -> next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head -> next == NULL)
            return true;
        
        ListNode *slow = head, *fast = head;
        while (fast -> next != NULL and fast -> next -> next != NULL)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        slow -> next = byReverse(slow -> next);
        slow = slow -> next;
        
        while(slow != NULL)
        {
            if (head -> val != slow -> val)
                return false;
            head = head -> next;
            slow = slow -> next;
        }
        return true;
    }
};


/*
    Navie Solution :- 
        1) By using Vector(or) array and storing the node val and checking it's palindrome or not..
        3) TC -> O(n) + O(n)  and  SC -> O(n)..
    Efficient Solution :-
        1) Find the Middle and reversing right half, and take dummy from the head and starting with middle next node onwards.. when both val are same move ahead..
        2) When the right half completely and reachs to NULL..
        3) We can say that right half is reverse of left half..
        4) TC -> O(n/2) + O(n/2) + O(n/2)       and SC -> O(1)..
        5) In case, If we need the original right half to it's previous.. by doing reverse of right half..
*/ 