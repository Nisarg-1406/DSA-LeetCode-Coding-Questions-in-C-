    * Using 2 Approaches - Using Extra space, Not using Extra space.
    
    * Using Extra Space
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *temp,*temp1;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        while(temp!=NULL && temp1!=NULL){
            if(temp->val > temp1->val){
                temp1->next = temp->next;
                temp->next = temp1;
                free(temp1);
            }
            else if(temp->val < temp1->val){
                temp->next = temp1->next;
                temp1->next = temp;
                free(temp);
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
        return temp;
   }
   
   * Not Using Extra space - 
   ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val > l2->val) swap(l1,l2);
        ListNode* res = l1;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* temp = nullptr;
            while (l1 != nullptr && (l1->val <= l2->val)) {
                temp = l1;
                l1 = l1->next;
            }
            temp->next = l2;
            swap(l1,l2);
        }
        return res;
    }
