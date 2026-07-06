/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;
    
    // Move fast pointer so that there is a gap of n nodes between fast and slow
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move fast to the end, maintaining the gap
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // Skip the nth node from the end
    struct ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    free(toDelete);
    
    return dummy.next;
}