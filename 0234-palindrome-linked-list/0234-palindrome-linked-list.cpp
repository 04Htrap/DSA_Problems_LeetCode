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

    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        ListNode* newHead = reverseList(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = nullptr;

        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* secondHalf = reverseList(slow);

        ListNode* first = head;
        ListNode* second = secondHalf;

        bool Palin = true;
        while (second != nullptr){
            if(first -> val != second -> val){
                Palin = false;
                return Palin;
                break;
            }
            first = first -> next;
            second = second -> next;
        }
        return Palin;
    }
};