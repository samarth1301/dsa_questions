//quesiton link : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/submissions/


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
    int getDecimalValue(ListNode* head) {
        // int count=0;
        // ListNode* temp = head;
        // while(head!=nullptr){
        //     count++;
        //     head = head->next;
        // }
        // int res = 0;
        // head=temp;
        // while(head!=nullptr){
        //     if(head->val==1){
        //         res+=pow(2,--count);
        //     }
        //     else{
        //         count--;
        //     }
        //     head= head->next;
        //     // cout<<res<<endl;
        // }
        // return res;
        
        //OR
        
        int res=0;
        // while(head!=NULL){
        //     res= (res*2) +head->val;
        //     head= head->next;
        // }
        
        //OR
        
        while(head!=NULL){
            res = (res<<1) | head->val;
            head= head->next;
        }
        
        return res;
        
        
    }
};
