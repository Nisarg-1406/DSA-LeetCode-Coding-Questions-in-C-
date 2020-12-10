    //Doing 4 steps - 
    // 1) Calculating the length of the linked list
    // 2) Making the last node to point it to the head of the linked list.
    // 3) Doing k = k % len when k > len as we would be traversing unneccessary. 
    // 4) Making k = len - k, i.e to make the (len - k)th node pointing to null and then to make the next of (len - k)th node pointing to the head of the linked list.
    
    ListNode* rotateRight(ListNode* head, int k) {
        // edge cases 
        if (!head || !head->next || k == 0) return head;
        
        // compute the length
        ListNode *cur = head;
        int len = 1;
        while (cur->next){ 
            cur = cur->next;
            len = len + 1;
        }
        
        // go till that node
        cur->next = head;
        k = k % len; 
        k = len - k;
        while (k--) cur = cur->next;
        
        // make the node head and break connection 
        head = cur->next;
        cur->next = NULL;
        return head; 
    }
