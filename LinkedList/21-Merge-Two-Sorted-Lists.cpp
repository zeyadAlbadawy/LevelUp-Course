/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode *ptr = NULL;
        if(list1->val <= list2->val) {
            ptr = list1;
            ptr->next = mergeTwoLists(list1->next, list2);
        } else if (list2->val < list1->val) {
            ptr = list2;
            ptr->next = mergeTwoLists(list1, list2->next);
        }
        return ptr;
    }
};
