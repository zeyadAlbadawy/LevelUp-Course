class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for (int i = 1; i <= k; ++i) {
            if (!temp){ 
                return head; // Less than k nodes remaining, leave them unchanged
            }
            temp = temp->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        int cnt = 1;
        while (cnt <= k && curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            cnt++;
        }

        if (curr) {
            head->next = reverseKGroup(curr, k);
        }

        return prev;
    }
};
