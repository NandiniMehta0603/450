/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
                int data;
                Node *next;
                Node(int data)
                {
                        this->data = data;
                        this->next = NULL;
                }
        };

*****************************************************************/

Node* deleteNode(Node* head, int key) 
{
    //key on the start
    if(head==NULL){
        return NULL;
    }
    if(head->data==key && head->next!=head){
            Node *temp=head;
            while(temp->next!=head){
                    temp=temp->next;
            }
            temp->next=head->next;
            head=head->next;
            return head;
    }
    else if(head->data==key && head->next==head){
            return NULL;
    }

    //key on the tail
    Node *temp=head;
    Node *prev=NULL;
    while(temp->data!=key && temp->next!=head){
            prev=temp;
            temp=temp->next;
    }
    if(temp->data==key){
            if(temp->next==head){
                    prev->next=head;
                    temp->next=NULL;
            }
            else{
                    prev->next=temp->next;
                    temp->next=NULL;
            }
    }
        return head;
}
