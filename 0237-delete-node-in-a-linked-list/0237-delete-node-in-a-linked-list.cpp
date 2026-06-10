/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //TIME COMPLEXITY O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == nullptr || node->next == nullptr)
            return;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};