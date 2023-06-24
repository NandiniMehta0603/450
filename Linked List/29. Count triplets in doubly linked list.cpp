// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>

using namespace std;

// structure of node of doubly linked list
struct Node {
	int data;
	struct Node* next, *prev;
};

// function to count pairs whose sum equal to given 'value'
int countPairs(struct Node* first, struct Node* second, int value)
{
	int count = 0;

	// The loop terminates when either of two pointers
	// become NULL, or they cross each other (second->next
	// == first), or they become same (first == second)
	while (first != NULL && second != NULL &&
		first != second && second->next != first) {

		// pair found
		if ((first->data + second->data) == value) {

			// increment count
			count++;

			// move first in forward direction
			first = first->next;

			// move second in backward direction
			second = second->prev;
		}

		// if sum is greater than 'value'
		// move second in backward direction
		else if ((first->data + second->data) > value)
			second = second->prev;

		// else move first in forward direction
		else
			first = first->next;
	}

	// required count of pairs
	return count;
}

// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
int countTriplets(struct Node* head, int x)
{
  
	int count=0;
  Node *start=head;
  while(start->next->next!=NULL){
    int left=x-start->data;
    Node *temp1=start->next;
    Node *temp2=start->next;
    while(temp2->next!=NULL){
      temp2=temp2->next;
    }
    while(temp2!=temp1 && temp1!=NULL && temp2!=NULL){
      if(temp2->data+temp1->data==left){
        count++;
        //temp2=temp2->prev;
        temp1=temp1->next;
      }
      else if(temp2->data+temp1->data>left){
        temp2=temp2->prev;
      }
      else{
        temp1=temp1->next;
      }
    }
    start=start->next;
  }
  return count;
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node** head, int data)
{
	// allocate node
	struct Node* temp = new Node();

	// put in the data
	temp->data = data;
	temp->next = temp->prev = NULL;

	if ((*head) == NULL)
		(*head) = temp;
	else {
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program to test above
int main()
{
	// start with an empty doubly linked list
	struct Node* head = NULL;

	// insert values in sorted order
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);

	int x = 15;

	cout << "Count = "
		<< countTriplets(head, x);
	return 0;
}
