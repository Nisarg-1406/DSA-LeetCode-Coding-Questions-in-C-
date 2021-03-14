    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0; 
        ListNode* tmp = head;
        while (tmp){ // To calculate the total number of nodes
            n += 1;
            tmp = tmp->next;
        }
        int ind_1 = k, ind_2 = n - k + 1;
        if (ind_1 == ind_2) return head;
        
        n = 0; 
        tmp = head;
        int val_1 = 0, val_2 = 0;
        while (tmp){
            n += 1;
            if (n == ind_1) val_1 = tmp->val;
            if (n == ind_2) val_2 = tmp->val;
            tmp = tmp->next;
        }
        n = 0; 
        tmp = head;
        while (tmp){
            n += 1;
            if (n == ind_1) tmp->val = val_2;
            if (n == ind_2) tmp->val = val_1;
            tmp = tmp->next;
        }
        return head;    
    }
