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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur  = head;
        int counter = 0;
        while (cur) {
            counter++;
            cur = cur->next;
        }
        ListNode dummy(0, head);
        cur = &dummy;
        for (int i = 0; i < counter - n; i++) {
            cur = cur -> next;
        }
        cur -> next = cur -> next -> next;
        return dummy.next;
    }
};
