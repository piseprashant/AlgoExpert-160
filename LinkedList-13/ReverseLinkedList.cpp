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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;
            
        while (curr)
        {
            // remember inside while loop 1st and last line is to iterate over linked list
            next = curr->next;
            
            // main logic start and ist assign curr->next to nullptr of 1st head to be tail and next as prev elements
            curr->next = prev; // basically this holds prev next pointer
            
            // now as prev is assigned to cuurent next, update prev
            prev = curr; // Keep on assigning prev as curr node iter as we iterate over it
            
            // main logic end
            
            // remember inside while loop 1st and last line is to iterate over linked list
            curr = next;
        }
        return prev;
    }
};
