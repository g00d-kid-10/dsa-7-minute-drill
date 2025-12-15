int len(ListNode* head) {
    int ans = 0;
    while(head) {
        ans++;
        head = head->next;
    }
    return ans;
}