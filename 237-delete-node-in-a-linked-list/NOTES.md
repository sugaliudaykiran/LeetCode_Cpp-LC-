//  Here we need to change cur node val to next node val.. and node's next to node's next's next..
​
//  TC -> O(1)..    AS -> O(1)..
​
​
​
C++
​
void deleteNode(ListNode* node) {
*node = *node->next;
}
But better properly delete the next node:
​
void deleteNode(ListNode* node) {
auto next = node->next;
*node = *next;
delete next;
}