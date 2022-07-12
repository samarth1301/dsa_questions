//question link: https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        unordered_map<int,int> hmap;
        Node* temp = head;
        Node* t2=head;
        while(temp!=nullptr){
            hmap[temp->data]++;
            temp = temp->next;
        }
        
        while(hmap[0]>0){
            head->data = 0;
            head = head->next;
            hmap[0]--;
        }
        while(hmap[1]>0){
            head->data = 1;
            head = head->next;
            hmap[1]--;
        }
        while(hmap[2]>0){
            head->data=2;
            head = head->next;
            hmap[2]--;
        }
        return t2;
    }
};
