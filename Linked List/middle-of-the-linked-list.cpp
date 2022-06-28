// question link - https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
//         int size=0;
//         // if(head!=nullptr){
//         //     size++;
//         // }
//         ListNode* temp = head;
//         while(temp->next!=nullptr){
//             size++;
//             temp=temp->next;
//         }
//         cout<<size<<endl;
//         if(size==0){
//             return head;
//         }
//         int target;
//         if(size%2!=0){
//             target=(size/2)+1;
//         }
//         else{
//             target=(size/2);
//         }
        
//         temp=head;
//         int c=0;
//          while(temp->next!=nullptr && c<target){
//             c++;
//             temp=temp->next;
//         }
//         return temp;
        if(head==nullptr || head->next ==nullptr){
            return head;
        }
        // ListNode* slow = head;
        // ListNode* fast = head->next;
        // while(fast!=nullptr){
        //     slow = slow->next;
        //     if(fast->next==nullptr){
        //         return slow;
        //     }
        //     fast = fast->next->next;
        // }
        // return slow;
        
        
        // or
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
