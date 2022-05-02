/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head;              //      TC -> O(n)..    SC -> O(1)..
        Node *front = head;
         // First round: make copy of each node,
          // and link them together side-by-side in a single list.
        while (iter != NULL)
        {
            front = iter -> next;
            
            Node* copy = new Node(iter -> val);
            iter -> next = copy;
            copy -> next = front;
  
            iter = front;
        }
        // Second round: assign random pointers for the copy nodes.
        iter = head;
        while (iter != NULL)
        {
            if (iter-> random != NULL)
            {
                iter-> next -> random = iter-> random -> next;
            }
            iter = iter -> next -> next;
        }
        // Third round: restore the original list, and extract the copy list.
        iter = head;
        Node* PseudoHead = new Node(0);
        Node* copy = PseudoHead;
        
        while (iter != NULL)
        {
            front = iter -> next -> next;
            copy -> next = iter -> next;
            iter -> next = front;
            copy = copy -> next;
            iter = iter -> next;
        }
        return PseudoHead -> next;
    }
};


/*
        Navie Solution :- 
            1) using Hashmap as <Node, Node> which is one original node and another one is Deep copy node of it's..
            2) First we create the Deep copy nodes by traversing..
            3) Next we make the next and random of Deep copy nodes by using hashmap of it's original node's next and random..
            4) return head of Deep copy node using hashmap of original List's head..
            4) TC -> O(n) + O(n)    SC -> O(n)..
            
*/ 