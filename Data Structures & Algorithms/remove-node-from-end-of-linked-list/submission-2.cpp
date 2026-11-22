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
        int sz = 0;
        ListNode* dummy = head;
        while (dummy) {
            sz++;
            dummy = dummy -> next;
        }
        int place = sz - n;
        if (place == 0) return head->next;
        dummy = head;
        ListNode* prev = NULL;
        while (place--) {
            prev = dummy;
            dummy = dummy -> next;
        }
        prev -> next = dummy -> next;
        cout<<sz<<endl;
        return head;
        
    }
};
