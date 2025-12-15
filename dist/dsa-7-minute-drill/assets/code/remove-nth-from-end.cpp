ListNode* rmv_nth_from_end(ListNode* head, int n) {
    int l = len(head);
    ListNode *temp = head;
    if(n == l) {
        head = head->next;
        delete temp;
        return head;
    }

    int skip = l - n - 1;
    while(skip--) {
        temp = temp->next;
    }

    ListNode *to_delete = temp->next;
    temp->next = temp->next->next;
    delete to_delete;
    return head;
}