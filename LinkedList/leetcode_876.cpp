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
    ListNode* middleNode(ListNode* head) {
        ListNode* tortoise = head; //slow pointer
        ListNode* hare = head;  //fast pointer
        while(hare != NULL && hare->next != NULL){
            /* 🟢 One-line logic:

            👉 fast->next check = crash prevention
            👉 fast check = loop termination
            */
            tortoise = tortoise -> next;
            hare = hare -> next -> next;
        }
        return tortoise;
    }
};
/* BRUTE 
Step 1: Traverse → find length (len)
Step 2: mid = len / 2
Step 3: Traverse again till mid
Step 4: return that node
*/
