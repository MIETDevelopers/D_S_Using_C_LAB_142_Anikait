//Author: Anikait Singh
//Creation date: 03 Aug,2021
//Purpose: Implement a Doubly Linked List and develop functions to perform insertion, deletion and linear search operations.

#include<stdio.h>
#include<stdlib.h>

struct link{
	int val;
	struct link *add;
	struct link *pre;
}*head;

typedef struct link link;

int insert_end();
int view();
int delete_end();
int search();

int main(){
	int ch;
	printf("\n\n\t\t\t**MENU FOR DOUBLE LINKED LIST**\n\n");
	while(1){
		printf("\n\nEnter 1 to INSERT element.");
		printf("\nEnter 2 to view elements.");
		printf("\nEnter 3 to DELETE elements.");
		printf("\nEnter 4 to search elements.");
		printf("\nEnter 5 to exit.");
		printf("\n\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1  :insert_end();
					break;
			case 2  :view();//getch();
					break;
			case 3  :delete_end();
					break;
			case 4	:search();
					break;				
			case 5  :exit(0);
			default :printf("\n\n\t**WARNING!!! Enter the right choice given in menu**\n\n");						
		}
	}
	return 0;
}

int insert_end(){
	link *rep;
	link *p = (struct link *)malloc(sizeof(struct link));

	if(p == NULL){
		printf("\n\nFree some space in RAM\n\n");
	}
	else{
		printf("\n\nEnter the elements: ");
		scanf("%d",&p->val);
		if(head == NULL){
			p -> pre = NULL;
			p -> add = NULL;
			head = p;
		}
		else{  
       		for (rep = head; rep -> add != NULL; rep = rep -> add){
	 		}
	 		rep -> add = p;
	 		p -> pre = rep;  
          	p -> add = NULL;  
	 		printf("\n%d Succesfully inserted at end\n",p->val);  
   		}  
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

int delete_end(){
 	link *p;
	if(head == NULL){
		printf("\n\nFirst enter the element to delete.\n\n");
	}

	else if(head -> add == NULL){
		head = NULL;
		free(head);
		printf("\nNode Deleted.\n");
	}
	else{
		for(p = head; p->add != NULL; p = p->add){
		}
		p -> pre -> add = NULL;
		free(p);
		printf("\nLast entered node Deleted from end.\n");
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
