#include<iostream>
using namespace std;

class Node
{
	public:
		char data;
		Node* next;
		Node* pre;
	Node(int data)
	{
		this->data=data;
		pre=NULL;
		next=NULL;
	}
};

void insertAtHead(Node* &head, int data)
{
	Node* n = new Node(data);
	if(head==NULL)
	{
		head=n;
		return;
	}
	n->next=head;
	head->pre=n;
	head=n;
	return;
}
void insertAtTail(Node* &head, int data)
{
	if(head==NULL)
	{
		insertAtHead(head,data);
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	Node* n=new Node(data);
	temp->next=n;
	n->pre=temp;
	return;
}
void display(Node* head)
{
	while(head!=NULL)
	{
		cout << head->data << " ";
		head=head->next;
	}
}

void rotateByN(Node* &head, int pos)
{
	if(pos==0){
      return ;}
  Node *tail=head;
  while(tail->next!=NULL){
    tail=tail->next;
  }
  
  int count=1;
  
  while(count<=pos){
    Node *temp=head;
  head=head->next;
  temp->next=NULL;
  head->pre=NULL;
    tail->next=temp;
    temp->pre=tail;
    tail=temp;
    tail->next=NULL;
    count++;
  }
}
int main()
{
	Node* head=NULL;
	insertAtTail(head,'a');
	insertAtTail(head,'b');
	insertAtTail(head,'c');
	insertAtTail(head,'d');
	insertAtTail(head,'e');

	int n=5;
	cout << "Given linked list \n";
	display(head);
	rotateByN(head,n);
	cout << "\nRotated Linked list \n";
	display(head);
	cout << "\n\n";

	return 0;
}
