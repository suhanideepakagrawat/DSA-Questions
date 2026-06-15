class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge Case: If the list has only 1 node (or is empty)
        if (head == nullptr || head->next == nullptr) {
            // REMOVED: delete head; -> Let LeetCode handle the deallocation
            return nullptr;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Disconnect the middle node
        prev->next = slow->next;
        
        // Note: It's typically safe to delete 'slow' here because it's removed 
        // from the sequence, but if AddressSanitizer still complains, 
        // you can omit this 'delete' as well for LeetCode purposes.
        delete slow; 
        
        return head;
    }
};