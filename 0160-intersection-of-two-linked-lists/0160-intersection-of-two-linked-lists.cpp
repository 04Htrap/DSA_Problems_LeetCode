/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //TIME COMPLEXITY O(max(m,n))
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;

        int len1 = 0;
        int len2 = 0;

        while(p1 != nullptr || p2 != nullptr) {
            if(p1 != nullptr) {
                len1++;
                p1 = p1 -> next;
            }
            if(p2 != nullptr) {
                len2++;
                p2 = p2 -> next;
            }
        }

        int diff = len1 - len2;
        p1 = headA;
        p2 = headB;

        if(diff < 0) {
            for(int i = diff; i < 0; i++) {
                p2 = p2 -> next;
            }
        }
        else {
            for(int i = diff; i > 0; i--) {
                p1 = p1 -> next;
            }
        }

        while(p1 != nullptr && p2 != nullptr) {
            if(p1 == p2) return p1;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }

        return p1;
    }
};