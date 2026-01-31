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
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* curr = node;

        while(curr != nullptr) {
            ListNode* temp = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;

    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast->next-> next;
        }

        ListNode* head1 = head; //First Half
        ListNode* head2 = reverseList(slow); //Second Half

        while(head2 != nullptr) {
            if(head1 -> val != head2 -> val) {
                return false;
                break;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        return true;
    }
};