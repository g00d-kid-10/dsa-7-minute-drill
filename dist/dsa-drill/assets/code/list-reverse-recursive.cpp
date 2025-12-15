ListNode* r_reverse(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *new_head = r_reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}