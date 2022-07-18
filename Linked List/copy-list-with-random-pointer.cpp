/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * temp = head;
        if(head==NULL) return head;
        while(temp!=NULL){
            Node* t = new Node(temp->val);
            t->next= temp->next;
            temp->next= t;
            temp = temp->next->next;
        }
        Node* original = head;
        Node* clone = head->next;
        while(original!=NULL && clone!=NULL){
            // cout<<temp->val<<endl;
            clone->random = original->random !=NULL ? original->random->next : NULL;
            original = original->next->next;
            if(clone->next!=NULL)
                clone = clone->next->next;
        }
        original = head;
        clone = head->next;
        temp = head->next;
        while(original!=NULL && clone!=NULL){
            original->next = original->next->next;
            if(clone->next!=NULL)
                clone->next = clone->next->next;
            original = original->next;
            clone= clone->next;
        }
        return temp;
    }
};
