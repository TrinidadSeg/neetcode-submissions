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
        ListNode* c1 = list1; ListNode* c2 = list2;
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        while (c1 && c2) {
            ListNode* temp = nullptr;
            if (c1 -> val < c2 -> val) {
                dummy -> next = c1;
                c1 = c1 -> next;
                dummy = dummy -> next;
            }
            else {
                dummy -> next = c2;
                c2 = c2 -> next;
                dummy = dummy -> next;
            }
        }
        while (c1) {
            dummy -> next = c1;
            c1 = c1 -> next;
            dummy = dummy -> next;
        }
        while (c2) {
            dummy -> next = c2;
            c2 = c2 -> next;
            dummy = dummy -> next;
        }
        return ans -> next;
    }
};
