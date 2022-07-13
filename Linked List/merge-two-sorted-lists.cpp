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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //iterative
//         if(list1==NULL && list2==NULL) return NULL;
//         ListNode* result = new ListNode();
//         auto res=result;
//         while(list1!=NULL && list2!=NULL ){
//             ListNode* temp = new ListNode();
//             if(list1->val<=list2->val){
//                 result->val=list1->val; 
//                list1=list1->next;
//             }
//             else{
//                 result->val=list2->val;
//                 list2=list2->next;
//             }
//              result->next=temp;
//                 result=temp;
//         }
//         while(list1!=NULL){
//             ListNode* temp= new ListNode();
//             result->val=list1->val;
//             list1=list1->next;
//             if(list1==NULL) break;
//             result->next=temp;
//                 result=temp;
//         }
        
//          while(list2!=NULL){
//             ListNode* temp= new ListNode();
//             result->val=list2->val;
//             list2=list2->next;
//             if(list2==NULL) break;
//             result->next=temp;
//                 result=temp;
//         }
//         return res;
        
        //or recursive
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        if(list1->val<=list2->val){
            list1->next= mergeTwoLists( list1->next,  list2);
            return list1;
        }
        else{
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }
    }
};
