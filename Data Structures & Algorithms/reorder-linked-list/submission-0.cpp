class Solution {
public:
    void reorderList(ListNode* head) {

        if (!head || !head->next) return;

        // find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* cur = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while (cur) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second) {

            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};