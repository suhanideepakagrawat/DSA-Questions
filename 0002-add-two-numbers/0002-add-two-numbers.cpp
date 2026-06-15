/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // A dummy head node helps simplify the code for creating the new list
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        
        // Loop runs until BOTH lists are fully traversed AND there is no carry left
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate total sum for the current digit position
            int sum = val1 + val2 + carry;
            
            // Calculate new carry and the actual value to store in the node
            carry = sum / 10;
            int digit = sum % 10;
            
            // Create the new node and advance our result list pointer
            curr->next = new ListNode(digit);
            curr = curr->next;
            
            // Advance the input list pointers if they haven't reached the end yet
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        // The actual head of our result list is the node right after dummy head
        ListNode* result = dummyHead->next;
        delete dummyHead; // Free the placeholder node's memory
        return result;
    }
};