    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        //To find the middle of the linked list with the help of the slow pointer
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //Reverse the next half of the linked list
        slow->next = reverseList(slow->next);
        slow = slow->next;
        //Comparing the first half and next half for Pallindrome check
        while (slow != nullptr) {
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
    //Reverse Function. 
    ListNode* reverseList(ListNode* head) {
        ListNode *current,*prev,*next;
        current = head;
        prev = NULL;
        while(current !=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
