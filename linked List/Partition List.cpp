    ListNode* partition(ListNode* head, int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* dummy = new ListNode(0);
        ListNode* dummy1 = new ListNode(0);
        dummy->next = head;
        dummy1->next = head;
        ListNode* cur = dummy;
        ListNode* pre = dummy1;
        while(head){
            if(head->val < x){
                cur->next = head;
                cur = cur->next;
            }
            else{
                pre->next = head;
                pre = pre->next;
            }
            head = head->next;
        }
        pre->next = NULL;
        cur->next = dummy1->next;
        return dummy->next;
    }
