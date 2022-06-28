/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 question link - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/submissions/
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return NULL;
        }
        
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = slow->next;
        return head;
    }
};
