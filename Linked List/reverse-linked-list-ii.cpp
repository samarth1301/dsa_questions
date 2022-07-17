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
   
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        if(head==nullptr || left==right) return head;
        for(int i=1;i<left;i++){
            prev = curr;
            curr = curr->next;
        }
        ListNode* pl = prev;
        ListNode* l = curr;
        for(int i=left;i<=right;i++){
            auto temp2 = curr->next;
            curr->next=prev;
            prev= curr;
            curr = temp2;
        }
       
        l->next = curr;
         if(pl!=NULL){
            pl->next = prev;
            return head;
        }
        return prev;
    }
};
