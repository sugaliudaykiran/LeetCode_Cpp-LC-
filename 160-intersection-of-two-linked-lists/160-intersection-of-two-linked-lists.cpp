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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //  Efficient Solution :- TC -> O(2M).. AS -> O(1).. But simple code..
        ListNode* d1 = headA;
        ListNode* d2 = headB;
        
        if (d1 == NULL and d2 == NULL){
            return NULL;
        }
        while (d1 != d2){
            d1 = (d1 == NULL)? headB: d1 = d1 -> next;
            d2 = (d2 == NULL)? headA: d2 = d2 -> next;
        }
        return d1;
    }
};


/*
        In this we need to find the intersection node, not the intesection value..
        
    Navie Solution :- 
        1) Comparing "each linked list" with each node of another linked list..
        2) TC -> O(N * M)..  where length of l1 is N and l2 is M..
    Improve Navie Solution :-
        1) BY using Hashing and storing the node. (not the node values..)
        2) In this we insert node into hash table of l1 and do compare the l2..
        3) At particular point they meet at point were the node is already existing in the hash table.. return that node..
        4) TC -> O(M + N).. AS -> O(N)..
    Better solution :- 
        1) By iterating both l1 and l2, finding length and difference and making to move the longer linked list pointer ahead the difference and now moving the both pointer simulations and when they reaches the intersection node then return thr node..
        2) Assuming length of l1 is N and l2 is M..
            TC -> O(M + N) + O(M - N) + O(N)  => O(2M).. AS -> O(1)..
*/