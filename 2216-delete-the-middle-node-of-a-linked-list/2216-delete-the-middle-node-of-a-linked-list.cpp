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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return nullptr;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        
        int cnt = 0;
        while(fast != nullptr && fast -> next != nullptr){
            fast = fast->next->next;
            cnt++;
        }

        for(int i = 1; i < cnt; i++){
            slow = slow -> next;
        }

        ListNode* delNode = slow -> next;
        slow -> next = slow ->next->next;
        delete delNode;
        return head;
    }
};