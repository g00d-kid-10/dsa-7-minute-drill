    ListNode* copy_list(ListNode* head) {
        ListNode *dummy = new ListNode();
        ListNode *temp = dummy;
        while(head) {
            temp->next = new ListNode(head->val);
            temp = temp->next;
            head = head->next;
        }
        return dummy->next;
    }