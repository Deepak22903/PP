    int l_len(ListNode* head){
      if (!head) {
        return 0;
      }
      int count = 0;
      while (head->next != nullptr) {
        count++;
        head= head->next; 
      }
      return count;
    
  }

    ListNode* reverseList(ListNode* head) {
      for (int i = l_len(head) -1; i >= 0; i--) {
      ListNode* curr = head;
      ListNode* prev = nullptr;
        for (jnt j = 0; j < i; j++) {

        prev = curr;
        curr = curr->next;
        int temp = curr->val;
        curr-> val = prev->val;
        prev->val = temp; 
        }      
      }


    }
