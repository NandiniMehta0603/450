//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
/* Link list node */
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void push(struct Node** head_ref, int new_data)
{
   
    struct Node* new_node = new Node(new_data);
    
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
} 

int countTriplets(struct Node* head, int x) ;

/* Driver program to test count function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n , x ,i , num;
        struct Node *head = NULL;
        cin>>n>>x;
        for(i=0;i<n;i++)
        {
            cin>>num;
            push(&head,num);
        }
 
    /* Check the count function */
    cout <<countTriplets(head, x)<< endl;
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

int countTriplets(struct Node* head, int x) 
{ 
    unordered_set<int> st;
    Node *temp=head;

    while(temp!=NULL){
        st.insert(temp->data);
        temp=temp->next;
    }
    
    Node *start=head;
    Node *next=NULL;
    int count=0;
    while(start!=NULL){
        next=start->next;
        while(next!=NULL){
            int left=x-start->data-next->data;
            if(st.find(left)!=st.end() && left>start->data && left>next->data){
                count++;
            }
            next=next->next;
        }
        start=start->next;
    }
    return count;
    
} 
