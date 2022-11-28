#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *prev, *next;
};
struct node* start = NULL;

void create(){
	start = NULL;
	struct node *temp, *newnode;
	
	newnode = (struct node*) malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->info);

	newnode->prev = NULL;
	newnode->next = NULL;
	if(start == NULL){
		start = temp = newnode;
	} else {
		temp->next=newnode;
		newnode->prev=temp;
		temp = newnode;
	}
}

void traverse()
{
	if (start == NULL) {
		printf("\nList is empty\n");
		return;
	}
	
	struct node* temp;
	temp = start;
	
	printf("List elements are: ");
	while (temp != NULL) {
		printf(" %d ", temp->info);
		temp = temp->next;
	}
}

void insertAtFront()
{
	int data;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->prev = NULL;


	temp->next = start;
	start = temp;
}

void insertAtEnd()
{
	int data;
	struct node *temp, *trav;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = NULL;
	trav = start;

	if (start == NULL) {

		start = temp;
	}

	else {
		while (trav->next != NULL)
			trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
	}
}

void insertAtPosition()
{
	int data, pos, i = 1;
	struct node *temp, *newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;

	printf("\nEnter position : ");
	scanf("%d", &pos);
	
	if (start == NULL) {
		start = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}


	else if (pos == 1) {
	insertAtFront();
	}

	else {
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnode->info = data;
	temp = start;
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
		temp->next->prev = newnode;
	}
}

void deleteFirst(){
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->next;
		if (start != NULL)
			start->prev = NULL;
		free(temp);
	}
}

void deleteEnd()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	if (start->next == NULL)
		start = NULL;
	else {
		temp->prev->next = NULL;
		free(temp);
	}
}

void deletePosition()
{
	int pos, i = 1;
	struct node *temp, *position;
	temp = start;


	if (start == NULL)
		printf("\nList is empty\n");


	else {

		printf("\nEnter position : ");
		scanf("%d", &pos);

		if (pos == 1) {
			deleteFirst(); 
			if (start != NULL) {
				start->prev = NULL;
			}
			free(position);
			return;
		}

		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}

		position = temp->next;
		if (position->next != NULL)
			position->next->prev = temp;
		temp->next = position->next;
		free(position);
	}
}

int main()
{
	int choice;
	while (1) {
		printf("\n");
		printf("1 create node \n");
		printf("2 For insertion at starting\n");
		printf("3 For insertion at end\n");
		printf("4 For insertion at any position\n");
		printf("5 For deletion of first element\n");
		printf("6 For deletion of last element\n");
		printf("7 For deletion of element at any position\n");
		printf("8 Display elements of doubly linked list\n");
		printf("9 To exit\n");
		printf("Enter Choice : ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			create();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			insertAtPosition();
			break;
		case 5:
			deleteFirst();
			break;
		case 6:
			deleteEnd();
			break;
		case 7:
			deletePosition();
			break;
		case 8:
			traverse();
			break;
		case 9:
			exit(1);
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			continue;
		}
	}
	return 0;
}

