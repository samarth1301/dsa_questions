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
        ListNode * nxt = head->next;
        head->next= NULL;
        while(nxt!=NULL){
            ListNode* temp = nxt->next;
            nxt->next = head;
            head = nxt;
            nxt = temp;
        }
        return head;
    }
    bool isPalindrome(ListNode* head) {
        int c =0 ;
        auto temp = head;
        while(temp!=NULL){
            temp= temp->next; 
            c++;
        }
        if(c==1) return head;
        int mid = c%2==0 ? c/2 : c/2+1; 
        temp = head;
        int c2=0;
        while(temp!=NULL && c2<mid){
          c2++;
            temp=temp->next;
        }
        temp = reverse(temp);
        int c3 =0;
        while(head!=NULL &&  temp !=NULL && c3<c/2){
            if(head->val!=temp->val)
                return false;
            head=head->next;
            c3++;
            temp=temp->next;
        }
        return true;
        
        
    }
};
