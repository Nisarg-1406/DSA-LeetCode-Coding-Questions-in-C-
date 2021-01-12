    3 Approaches
    
    Approach 1 - 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = 0;
            if (l1 != nullptr) {
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum = sum + l2->val;
                l2 = l2->next;
            }
            sum = sum + carry;
            carry = (sum / 10);
            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp -> next;
        }
        return dummy->next;
    }
    
    Approach 2 - 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum,carry=0,rem,div;
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while(l1 != NULL || l2 != NULL){
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            div = sum / 10;
            if(div != 0){
                rem = sum % 10;
                carry = 1;
                //tail -> val = rem;
                tail->next = new ListNode(rem);
            }
            else if(div == 0){
                carry = 0;
                //tail -> val = sum;
                tail->next = new ListNode(sum);
            }
            tail = tail -> next;
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return dummy.next;
    }
    
    Approach 3 - 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        return preHead.next;
    }
    
    
    
