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
    ListNode* helper(ListNode* prev,ListNode* curr, ListNode* nxt){
        curr->next = prev;
        if(nxt==NULL) return curr;
        return helper(curr,nxt,nxt->next);
    }
    ListNode* reverseList(ListNode* head) {
        //ITERATIVE
        if(head==NULL) return NULL;
//         auto nxt = head->next;
//         head->next = NULL;
     
//         while(nxt!=NULL){
//             auto temp= nxt->next;
//             nxt->next = head;
//             head = nxt;
//             nxt = temp;
//         }
//         return head;
        // OR RECURSIVE
        return helper(nullptr,head,head->next);
    }
};
