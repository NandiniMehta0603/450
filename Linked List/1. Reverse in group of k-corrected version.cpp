/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    if(head==NULL){
        return NULL;
    }
    int count=0;
    Node *curr=head;
    Node *next=NULL;
    Node *prev=NULL;
    
    while(curr!=NULL && count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }

    if(count<k){
        curr=prev;
        prev=NULL;
        next=NULL;
       while(count!=0){
           next=curr->next;
           curr->next=prev;
           prev=curr;
           curr=next;
           count--;
       } 
    }
    if(curr!=NULL){
        head->next=kReverse(curr,k);
    }
    return prev;
}
