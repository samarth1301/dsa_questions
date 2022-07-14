/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_set<ListNode*> hset;
        // while(headA!=NULL){
        //     hset.insert(headA);
        //     headA= headA->next;
        // }
        // while(headB!=NULL){
        //     if(hset.find(headB)!=hset.end()) return headB;
        //     headB=headB->next;
        // }
        // return NULL;
//         or
        ListNode* a = headA;
        ListNode* b = headB;
        while(a!=b){
            a = a==NULL ? headB : a->next;
            b = b==NULL ? headA : b->next;
        }
        return a;
    }
};
