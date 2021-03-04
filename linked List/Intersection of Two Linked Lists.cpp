    // 2 Methods - 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Method 1 
        int intersectVal,skipA,skipB;
        ListNode *temp1 = headA, *i = headA;
        ListNode *temp2 = headB, *j = headB;
        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val == intersectVal && temp2->val == intersectVal && i->val ==skipA && j-> val==skipB){
                return temp1;
            }
            else return NULL;
            i = i -> next;
            j = j -> next;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return temp1;
        
        
        // Method 2 - Important and Easy 
        //VERY IMPORTANT EXPLANATION - Refer this - https://leetcode.com/problems/intersection-of-two-linked-lists/discuss/49785/Java-solution-without-knowing-the-difference-in-len!
        //And the discussion in the first comment is very important
        if(headA==NULL || headB == NULL) return NULL;
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        while(temp1 != temp2){
            temp1 = temp1==NULL ? headB : temp1 -> next;
            temp2 = temp2==NULL ? headA : temp2 -> next;
        }
        return temp2;
    }
