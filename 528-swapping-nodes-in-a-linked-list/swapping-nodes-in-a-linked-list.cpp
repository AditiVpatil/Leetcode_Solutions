class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        int n = 0;

        
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

      
        ListNode* f = head;
        for (int i = 1; i < k; i++) {
            f = f->next;
        }

        
        ListNode* s = head;
        for (int i = 1; i < n - k + 1; i++) {
            s = s->next;
        }

        
        swap(f->val, s->val);

        return head;
    }
};
