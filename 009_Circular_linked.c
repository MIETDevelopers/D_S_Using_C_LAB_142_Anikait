//Author: Anikait Singh
//Creation date: 05 Aug,2021
//Purpose: Implement a Circular Linked List and develop functions to perform insertion, deletion and linear search operations.

#include<stdio.h>
#include<stdlib.h>

struct link{
	int val;
	struct link *add;
}*head;

typedef struct link link;

int insert_end();
int view();
int delete_end();
int search();

int main(){
	int ch;
	printf("\n\n\t\t\t**MENU FOR CIRCULAR LINKED LIST**\n\n");
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
			head = p;
			p -> add = head;
		}
		else{
			rep = head;  
            while(rep -> add != head)  
            {  
                rep = rep -> add;  
            }   
	 		rep -> add = p;  
          	p -> add = head;    
   		}
   		printf("\n%d Succesfully inserted at end\n",p->val);  
	}
	return 0;	
}

int view(){
	link *rep;
	rep = head;
	if(head == NULL){
		printf("\n\nEnter element to print\n\n");
	}
	else{
		printf("\n\nElements are :\n");
		while(rep -> add != head)  
        {  
          
            printf("%d\n", rep -> val);	//for last entered node.  
            rep = rep -> add;  
        }  
        printf("%d\n", rep -> val); //for printing remaing node.  
	}
	return 0;
}

int delete_end(){
 	link *p,*rep;
	if(head == NULL){
		printf("\n\nFirst enter the element to delete.\n\n");
	}

	else if(head -> add == head){
		head = NULL;
		free(head);
		printf("\nNode Deleted.\n");
	}
	else{
		for(p = head; p->add != head; p = p->add){
			rep = p;
		}
		rep -> add = p -> add;
		free(p);
		printf("\nLast entered node Deleted from end.\n");
	}
}

int search(){
	int num, i = 0, j = 1;
	link *rep = head;
	if(rep == NULL){
		printf("\n\nEnter element to print\n\n");
	}
	else{
		printf("\n\nEnter element to search: \n");
		scanf("%d",&num);

		if(head -> val == num){  
        printf("item found at location %d",i+1);  
        j=0;  
        }  
        else{
        	while (rep -> add != head){
        		if(rep -> val == num){
        			printf("\n\nElement %d is at %d position\n\n", num, i+1);
        			j=0;  
                	break;  
            	}   
            	else{
            		j = 1;  
           		}  
            	i++;  
            	rep = rep -> add;  
        	}  
        }  
        if(j != 0)  
        {  
            printf("\n\nElement not found\n\n");  
        }  
    }
    return 0;     
}
