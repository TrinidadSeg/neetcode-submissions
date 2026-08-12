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
        ListNode* l1 = list1; ListNode* l2 = list2;
        ListNode* d1 = new ListNode();
        ListNode* d2 = d1;
        while (l1 && l2) {
            if (l1 -> val < l2 -> val) {
                d1 -> next = l1;
                l1 = l1 -> next;
            }
            else {
                d1 -> next = l2;
                l2 = l2->next;
            }
            d1 = d1 -> next;
        }
        if (l1) d1 -> next = l1;
        else if (l2) d1 -> next = l2;

        return d2 -> next;
        
    }
};
