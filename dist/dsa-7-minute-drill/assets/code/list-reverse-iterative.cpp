ListNode* i_reverse(ListNode* head) {
    ListNode *prev = nullptr, *curr = head;
    while(curr) {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}