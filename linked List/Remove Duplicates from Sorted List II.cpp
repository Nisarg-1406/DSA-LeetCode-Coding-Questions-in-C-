    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        int duplicate = 0;
        while(cur->next && cur->next->next){
            if(cur->next->val == cur->next->next->val){
                duplicate = cur->next->val;
                while(cur->next && cur->next->val == duplicate){
                    cur->next = cur->next->next;
                }
            }
            else cur = cur->next;
        }
        return dummy->next;
    }
