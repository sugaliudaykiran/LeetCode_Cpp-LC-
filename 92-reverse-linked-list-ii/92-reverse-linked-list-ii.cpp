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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
{
	auto *prev{head}, *h{head}, **start{&head};

	for(; prev = exchange(h, h->next), --m && --n; start = &prev->next); 
	for(; --n; prev = exchange(h, exchange(h->next, prev))); 

	(*start)->next = h, *start = prev;

	return head;
}
};