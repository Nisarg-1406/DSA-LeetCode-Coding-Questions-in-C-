    bool hasCycle(ListNode *head) {
        // 1st Approach
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) return true;
        }
        return false;
        
        // 2nd Approach
        ListNode *temp = head;
        while (head != NULL) { 
            if (head->next == NULL) return false; 
            if (head->next == temp) return true; 
            ListNode* nex = head->next; 
            head->next = temp;
            head = nex;
        }
        return false;
    }
    
