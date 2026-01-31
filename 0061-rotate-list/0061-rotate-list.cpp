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

 //TIME COMPLEXITY O(n)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr || k == 0)
            return head;

        ListNode* temp = head;
        int len = 1;

        while(temp -> next != nullptr) {
            len++;
            temp = temp -> next;
        }

        k = k % len;
        if(k == 0) return head;

        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < k; i++) {
            fast = fast -> next;
        }

        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* newHead = slow -> next;
        slow -> next = nullptr;
        fast -> next = head;

        return newHead;
    }
};