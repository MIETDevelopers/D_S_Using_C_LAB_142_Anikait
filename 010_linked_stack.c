//Author: Anikait Singh
//Creation date: 06 Aug,2021
//Purpose: Implement a Stack using Linked List and develop functions to perform push and pop operations.
#include<stdio.h>
#include<stdlib.h>

struct link{
	int val;
	struct link *add;
}*head;

typedef struct link link;

int push();
int view();
int pop();
int search();

int main(){
	int ch;
	printf("\n\n\t\t\t**MENU FOR DYNAMIC LINKED LIST IMPLEMENT A STACK**\n\n");
	while(1){
		printf("\n\nEnter 1 to push element.");
		printf("\nEnter 2 to view elements.");
		printf("\nEnter 3 to pop elements.");
		printf("\nEnter 4 to search elements.");
		printf("\nEnter 5 to exit.");
		printf("\n\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1  :push();
					break;
			case 2  :view();//getch();
					break;
			case 3  :pop();
					break;
			case 4	:search();
					break;				
			case 5  :exit(0);
			default :printf("\n\n\t**WARNING!!! Enter the right choice given in menu**\n\n");						
		}
	}
	return 0;
}

int push(){
	
	link *p = (struct link *)malloc(sizeof(struct link));

	if(p == NULL){
		printf("\n\nStack is overflowing\n\n");
	}
	else{
		printf("\n\nEnter the elements: ");
		scanf("%d",&p->val);
		p -> add = head;
		head = p;
	}
	return 0;	
}

int view(){
	link *rep;
	if(head == NULL){
		printf("\n\nEnter element to print\n\n");
	}
	else{
		printf("\n\nElements are :\n");
		for(rep = head ;rep != NULL; rep = rep->add){
			printf("\n%d",rep->val);
		}
	}
	return 0;
}

int pop(){

	link *rep = head;

	if(head == NULL){
		printf("\n\nStack is underflowing so first enter the element to delete.\n\n");
	}

	else{
		head = head -> add;
		free(rep);
		printf("\nLast entered node Deleted.\n");
	}
}

int search(){
	int num, i, j;
	link *rep = head;
	if(rep == NULL){
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
