class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // base case: empty list ya single node → wahi return karo
        if(head == NULL || head->next == NULL) return head;
        
        // recursively aage badhte jao jab tak last node na mile
        // last node hi naya head banega
        ListNode* newhead = reverseList(head->next);
        
        // wapas aate waqt rewiring karo:
        // head->next abhi bhi agle node pe point kar raha hai
        // us agle node ka next ab head ko point karo (direction reverse!)
        head->next->next = head;
        
        // head ka next tod do → nahi to cycle ban jaayegi
        head->next = NULL;
        
        // newhead hamesha last node hai → reversed list ka pehla node
        return newhead;
    }
};

/*
INTUITION:
Iterative → teen pointers (prev, curr, next) se ek ek node reverse karo
Recursive → last node tak jao, wapas aate waqt rewire karo

KEY LINES:
head->next->next = head  → agle node ka next ab current node pe
head->next = NULL        → current node ka link todo (cycle avoid)
return newhead           → last node hamesha return hota hai (naya head)

Pre-order  → pehle kaam phir recurse (N to 1)
Post-order → pehle recurse phir kaam (1 to N) ← YE WALA hai!
*/
