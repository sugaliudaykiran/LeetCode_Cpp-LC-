int getDecimalValue(ListNode* head) {
ListNode *temp = head;          //  TC -> O(n).. SC -> O(1)..
int res = temp -> val;      //  Initially, store the head's val..
while (temp -> next != NULL)  //  Keep iterating .. and check temp's next node is 'NOT NULL'..
{
res = res * 2 + temp -> next -> val;   //   If not then, doing [res * 2 + X]
temp = temp -> next; // keep moving to next node..
}
return res;
}