//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node *head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node *curr=head;
        Node *prev=NULL;
        Node *next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node *add(Node *first,Node *second){
        Node *head=new Node(-1);
        Node *temp=head;
        int sum=0;
        int carry=0;
        
        while(first!=NULL && second!=NULL){
            sum=first->data+second->data+carry;
            carry=sum/10;
            sum=sum%10;
            temp->next=new Node(sum);
            temp=temp->next;
            first=first->next;
            second=second->next;
        }
        
        if (second != NULL) {
        temp->next = second;
        while (carry != 0) {
            if (second != NULL) {
                sum = second->data + carry;
                carry = sum / 10;
                second->data = sum % 10;
                temp = second;
                second = second->next;
            } else {
                temp->next = new Node(carry);
                temp = temp->next;
                carry = 0;
            }
        }
        
    }
    if (first != NULL) {
        temp->next = first;
        while (carry != 0) {
            if (first != NULL) {
                sum = first->data + carry;
                carry = sum / 10;
                first->data = sum % 10;
                temp = first;
                first = first->next;
            } else {
                temp->next = new Node(carry);
                temp = temp->next;
                carry = 0;
            }
        }
    }
    if(carry!=0){
            temp->next=new Node(carry);
            temp=temp->next;
            carry=0;
        }

        temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        
        Node *temp=add(first,second);
        
        temp=reverse(temp);
        return temp;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends
