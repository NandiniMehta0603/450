//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node *mergeSortedList(Node *head1,Node *head2){
        Node *newHead=NULL;
        Node *tail=NULL;
        
        if(head1->data<=head2->data){
            newHead=head1;
            head1=head1->next;
        }
        else{
            newHead=head2;
            head2=head2->next;
        }
        tail=newHead;
        while(head1!=NULL && head2!=NULL){
            if(head1->data<=head2->data){
                tail->next=head1;
                tail=head1;
                head1=head1->next;
            }
            else{
                tail->next=head2;
                tail=head2;
                head2=head2->next;
            }
        }
        if(head1!=NULL){
            tail->next=head1;
        }
        if(head2!=NULL){
            tail->next=head2;
        }
        return newHead;
    }
    Node *middle(Node *head){
        Node *fast=head->next;
        Node *slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node *mid=new Node(-1);
        mid=middle(head);
        Node *head2=mid->next;
        mid->next=NULL;
        Node *newHead=mergeSortedList(mergeSort(head),mergeSort(head2));
        return newHead;
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends
