Idea:
The easiest thing to do here is to create separate linked lists for the front and back portions of list we want to return. In order to accomplish that, we should first create some dummy heads (fdum, bdum), then create pointers for the current nodes each of the front, back, and main lists (front, back, curr).
​
Then we can simply iterate through the main list and stitch together each node to either front or back, depending on the node's value.
​
Once we reach the end, we just need to stitch together the two sub-lists, making sure to cap off the end of back, and then return our new list, minus the dummy head.
​
​
​
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode() : val(0), next(nullptr) {}
*     ListNode(int x) : val(x), next(nullptr) {}
*     ListNode(int x, ListNode *next) : val(x), next(next) {}
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