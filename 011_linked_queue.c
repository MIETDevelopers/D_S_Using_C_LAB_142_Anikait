//Author: Anikait Singh
//Creation date: 08 Aug,2021
//Purpose: Implement a Queue using Linked List and develop functions to perform enqueue and dequeue operations.

#include<stdio.h>
#include<stdlib.h>

struct link{
	int val;
	struct link *add;
}*front = NULL, *rear = NULL;

typedef struct link link;

int enqueue();
int view();
int dequeue();
int search();

int main(){
	int ch;
	printf("\n\n\t\t\t**MENU FOR DYNAMIC LINKED LIST IMPLEMENT A QUEUE**\n\n");
	while(1){
		printf("\n\nEnter 1 to enqueue element.");
		printf("\nEnter 2 to view elements.");
		printf("\nEnter 3 to dequeue elements.");
		printf("\nEnter 4 to search elements.");
		printf("\nEnter 5 to exit.");
		printf("\n\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1  :enqueue();
					break;
			case 2  :view();
					break;
			case 3  :dequeue();
					break;
			case 4	:search();
					break;				
			case 5  :exit(0);
			default :printf("\n\n\t**WARNING!!! Enter the right choice given in menu**\n\n");						
		}
	}
	return 0;
}

int enqueue(){
	
	link *p;
	p = (struct link *)malloc(sizeof(struct link));

	if(p == NULL){
		printf("\n\nQueue is overflowing\n\n");
	}
	else{
		printf("\n\nEnter the elements: ");
		scanf("%d",&p ->val);
		p -> add = NULL;

		if(front == NULL){
			front = rear = p;
			printf("\n\nFirst element inserted successfully\n");
		}
		else{
			rear -> add = p;
			rear = p;
		}
		 
	}
	printf("\nElement inserted in Queue\n\n");
	return 0;	
		
}

int view(){
	link *rep;
	if(front == NULL){
		printf("\n\nEnter element to print queue is empty\n\n");
	}
	else{
		printf("\n\nElements are :\n");
		for(rep = front ;rep != NULL; rep = rep->add){
			printf("\n%d",rep->val);
		}
	}
	return 0;
}

int dequeue(){
	link *rep = front;
	if(front == NULL){
		printf("\n\nQueue is underflowing so first enter the element to delete.\n\n");
	}

	else{
		front = front -> add;
		free(rep);
		printf("\nLast entered element  Deleted.\n");
	}
}

int search(){
	int num, i, j;
	link *rep = front;

	if(front == NULL){
		printf("\n\nEnter element to print\n\n");
	}
	else{
		printf("\n\nEnter element to search: \n");
		scanf("%d",&num);

		for(i = 0; rep != NULL; i++){
			if(rep -> val == num){
				printf("\n\nElement %d is at %d position\n\n", num, i+1);
				j = 0;
				break;
			}
			else{
				j = 1;
			}
			rep = rep -> add;
		}
		if(j==1){
			printf("\n\nElement not found\n\n");
		}
	}
}
