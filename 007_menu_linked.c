//Author: Anikait Singh
//Creation date: 01 Aug,2021
//Purpose: Implement a Singly Linked List and develop functions to perform insertion, deletion and linear search operations.
#include<stdio.h>
#include<stdlib.h>

struct link{
	int val;
	struct link *add;
}*head;

typedef struct link link;

int insert_begin();
int insert_end();
int insert_spec();
int view();
int delete_begin();
int delete_end();
int delete_spec();
int search();

int main(){
	int ch;
	printf("\n\n\t\t\t**MENU FOR DYNAMIC LINKED LIST**\n\n");
	while(1){
		printf("\n\nEnter 1 to insert element.");
		printf("\nEnter 2 to view elements.");
		printf("\nEnter 3 to delete elements.");
		printf("\nEnter 4 to search elements.");
		printf("\nEnter 5 to exit.");
		printf("\n\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1  :	printf("\n\n\t\t\tSUB MENU FOR INSERTION\n\nEnter 1 to insert at beginning.\nEnter 2 to insert at end.\nEnter 3 to insert at specific position.\n\n");
						printf("\nEnter the choice: ");
						scanf("%d",&ch);
						switch(ch){
							case 1 :	insert_begin();
							 			break;
							case 2 :	insert_end();
										break;
							case 3 :	insert_spec();
										break;			
							default:	printf("\n\n\t**WARNING!!! Enter the right choice given in menu to insert**\n\n");		 	
						}
						break;
			case 2  :	view();//getch();
						break;
			case 3  :	printf("\n\n\t\t\tSUB MENU FOR DELETION\n\nEnter 1 to delete at beginning.\nEnter 2 to delete at end.\nEnter 3 to delete at specific position.\n\n");
						printf("\nEnter the choice: ");
						scanf("%d",&ch);
						switch(ch){
							case 1 :	delete_begin();
							 			break;
							case 2 :	delete_end();
										break;
							case 3 :	delete_spec();
										break;			
							default:	printf("\n\n\t**WARNING!!! Enter the right choice given in menu to delete**\n\n");
						}
						break;
			case 4	:	search();
						break;				
			case 5  :	exit(0);
			default :	printf("\n\n\t**WARNING!!! Enter the right choice given in menu**\n\n");						
		}
	}
	return 0;
}

int insert_end(){
	link *p,*rep;
	p = (struct link *)malloc(sizeof(struct link));

	if(p == NULL){
		printf("\n\nFree some space in RAM\n\n");
	}
	else{
		printf("\n\nEnter the elements: ");
		scanf("%d",&p -> val);

	 	p -> add = NULL;

	 	if(head == NULL){
	 		head = p;
	 	}
	 	else{
	 		for (rep = head; rep -> add != NULL; rep = rep -> add){
	 		}
	 		rep -> add = p;
	 		printf("\n%d Succesfully inserted at end\n",p->val);
	 	}
	}
	return 0;	
}

int insert_spec(){  
    int i,post;   
    link *p, *rep;  
    p = (struct link *) malloc (sizeof(struct link));  
    if(p == NULL){  
        printf("\n\nFree some space in RAM\n\n");  
    }  
    else{  
        printf("\nEnter the element: ");  
        scanf("%d",&p->val);  
        
        printf("\n\nEnter the position you want to insert element: ");  
        scanf("\n%d",&post);  
       	if(post == 1)
       	{
       		p->add=rep;
    		head=p;
    	}

        rep=head;  
        for(i=1;i<post-1;i++){  
            rep = rep->add;  
            if(rep == NULL){
            	printf("\n\nEnter valid position to enter the element\n\n");
            	return 0;    
            }  
        }  
        p ->add = rep ->add;   
        rep ->add = p;   
        printf("\n%d inserted successfully at %d position from up to down",p->val,post);  
    }
    return 0;  
}  

int view(){
	link *p;
	if(p == NULL){
		printf("\n\nEnter element to print\n\n");
	}
	else{
		printf("\n\nElements are :\n");
		for(p = head ;p != NULL; p = p->add){
			printf("\n%d",p->val);
		}
	}
	return 0;
}

int delete_end(){
 	link *p, *rep;
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
			rep = p;
		}
		rep -> add = NULL;
		free(p);
		printf("\nLast entered node Deleted from end.\n");
	}
}

int search(){
	link *p;
	int num, i, j;
	p = head;
	if(p == NULL){
		printf("\n\nEnter element to print\n\n");
	}
	else{
		printf("\n\nEnter element to search: \n");
		scanf("%d",&num);

		for(i = 0; p != NULL; i++){
			if(p -> val == num){
				printf("\n\nElement %d is at %d position from up to down\n\n", num, i+1);
				j = 0;
				break;
			}
			else{
				j = 1;
			}
			p = p -> add;
		}
		if(j==1){
			printf("\n\nElement not found\n\n");
		}
	}
}

int insert_begin()
{  
    link *p;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    p = (struct link *) malloc (sizeof(struct link *));  
    if(p == NULL){  
        printf("\n\nFree some space in RAM\n\n");  
    }  
    else{  
        printf("\nEnter the element :");    
        scanf("%d",&p->val);    
        p->add = head;
        head = p;  
        printf("\n%d Succesfully inserted at beginning\n",p->val);
    }  
    return 0;      
}  

int delete_begin(){
	link *p;
	if(head == NULL){
		printf("\n\nFirst enter the element to delete.\n\n");
	}

	else{
		p = head;
		head = head -> add;
		free(p);
		printf("\nDeleted last entered node from beginning.\n");
	}
	return 0;
}

int delete_spec()  
{  
    link *p,*rep;  
    int i, post;    
     printf("\n\nEnter the position you want to delete element: ");  
    scanf("%d",&post);  
    p=head;  
    for(i=0;i<post;i++)  
    {  
        rep = p;       
        p = p->add;  
              
        if(p == NULL)  
        {  
            printf("\nEnter valid position to delete.\n");  
            return 0;  
        }  
    }  
    rep ->add = p ->add;  
    free(p);  
    printf("\n %d position node Deleted\n\n",post);
    return 0;  
}  
