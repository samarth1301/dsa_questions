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
    
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp!=NULL){
            ListNode* t = temp->next;
            temp->next = prev;
            prev = temp;
            temp = t;
        }
        return prev;
    }
    
    ListNode* cut(ListNode* head){
        if(head==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow->next =nullptr;
        return slow; 
    }
    
    void reorderList(ListNode* head) {
        ListNode* t = cut(head);
        t = reverse(t);
        // while(head!=NULL){
        //     cout<<head->val<<" ";
        //     head = head->next;
        //     }
        // cout<<endl;
        //  while(t!=NULL){
        //     cout<<t->val<<" ";
        //      t = t->next;
        //     }
        // cout<<endl;
        ListNode* temp = head;
        while(temp->next !=NULL && t->next !=NULL){
            ListNode* t2 = t->next;
            t->next = temp->next;
            temp->next = t;
             // cout<<temp->val<<" "<<t->val<<endl;
            temp = t->next;
            t = t2;
        }
        
    }
};
