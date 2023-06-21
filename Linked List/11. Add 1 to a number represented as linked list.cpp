//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *reverse(Node *head){
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
    Node *addSum(Node *head){
        bool carry=false;
        Node *prev=NULL;
        Node *temp=head;
        temp->data=temp->data+1;
        if(temp->data==10){
            temp->data=0;
            carry=true;
            prev=temp;
            temp=temp->next;
            
            while(carry==true && temp!=NULL){
                int sum=temp->data+1;
                if(sum<10){
                    carry = false;
                    temp->data=sum;
                    return head;
                }
                else{
                    temp->data=0;
                    prev=temp;
                    temp=temp->next;
                }
            }
            if(carry==true){
                // temp=new Node(1);
                prev->next=new Node(1);
                carry=false;
            }
        }
        return head;
    }
    Node* addOne(Node *head) 
    {
        if(head==NULL){
            head->data=1;
            head->next=NULL;
            return head;
        }
        
        head=reverse(head);
        
        head=addSum(head);
        
        head=reverse(head);
        
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends
