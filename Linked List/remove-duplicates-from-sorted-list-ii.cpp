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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        
        
        while(curr!=NULL){
            if(curr->next && curr->next->val == curr->val){
                while(curr->next && curr->next->val == curr->val){
                    curr = curr->next;
                }
                curr = curr->next;
                if(!prev && curr==NULL){
                    return NULL;
                }
                if(!prev){
                    head = curr;
                    continue;
                }
                if(prev){
                    prev->next = curr;
                }
            }
            else{
                prev=curr;
                curr = curr->next;
            }
            
        }
        return head;
    }
};
