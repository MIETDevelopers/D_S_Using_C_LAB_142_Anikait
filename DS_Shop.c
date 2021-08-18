//Author: Anikait Singh
//Creation date: 17 Aug,2021
//Purpose: Implement a data structure in C to represent the shops in Raghunath Bazaar. Perform operations on the data structure for finding out the shop with cheapest rate of walnut.

#include<stdio.h>
#include<stdlib.h>

struct shop{
	char shop_name[20];
	int wal_rate;
	int alm_rate;
	struct shop *add;
}*head;

typedef struct shop shop;

int insert_end();
int view();
int view_wal();
int delete();

int main(){
	int ch;
	printf("\n\n\t\t\t***MENU TO ENTER THE RECORD***\n\n");
	while(1){
		printf("\n\nEnter 1 to enter shop and items rate.");
		printf("\nEnter 2 to view shop and rates.");
		printf("\nEnter 3 to view which shop is selling cheapest walnut.");
		printf("\nEnter 4 to delete shop.");
		printf("\nEnter 5 to exit.");
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1 : insert_end();
					break;
			case 2 : view();
					break;
			case 3 : view_wal();
					break;
			case 4 : delete();
					break;				
			case 5 : exit(0);		
			default: printf("\n\n\t**WARNING!!! Enter the right choice given in menu to insert**\n\n");				
		}
	}
}

int insert_end(){
	shop *p,*rep;
	p = (struct shop *)malloc(sizeof(struct shop));

	if(p == NULL){
		printf("\n\nFree some space in RAM\n\n");
	}
	else{
		printf("\n\nEnter the shop name: ");
		scanf("%s",&p -> shop_name);

		printf("\n\nEnter the rate of walnut: ₹");
		scanf("%d",&p -> wal_rate);

		printf("\n\nEnter the rate of almond: ₹");
		scanf("%d",&p -> alm_rate);

		if(head == NULL || head -> wal_rate >= p->wal_rate){
	 		p -> add = head;
	 		head = p;
	 	}
	 	else{
	 		for (rep = head; rep -> add != NULL && rep->add->wal_rate < p -> wal_rate; rep = rep -> add){
	 		}
	 		p->add = rep ->add;
	 		rep -> add = p;
	 	}
	 	printf("\nShop name %s has WALNUT at the cost of ₹%d and ALMOND at the cost of ₹%d.\n",p->shop_name, p->wal_rate, p->alm_rate);
	}
	return 0;	
}

int view(){
	int i = 0;
	shop *p;
	if(p == NULL){
		printf("\n\nALL THE SHOPES ARE CLOSED FOR THE MOMENT PLEASE TRY AGAIN!!!\n\n");
	}
	else{
		printf("Menu of the shops with there respective rates.");
		printf("\n\tS.No\t\t\tShop Name\t\t\t\tWALNUT RATE\t\t\t\tALMOND RATE\t\n");
		for(p = head ;p != NULL; p = p->add){	
			printf("\t %d \t\t\t%s \t\t\t\t  ₹%d/-   \t\t\t\t   ₹%d/-\t\n",i++,p->shop_name, p->wal_rate, p->alm_rate);
		}
	}
	return 0;
}

int view_wal(){
	shop *p;
	if(p == NULL){
		printf("\n\nALL THE SHOPES ARE CLOSED FOR THE MOMENT PLEASE TRY AGAIN!!!\n\n");
	}
	else{
		p = head;	
			printf("\n\nShop name %s has the lowest price walnut at the rate = ₹%d/-",p->shop_name, p->wal_rate);
	}
	return 0;
}

int delete(){
    view();
    int i,loc;
    shop *rep,*pre;
    if(head==NULL)
    {
        printf("\nThe List is Empty! :/");
        return 0;
    }
    else{
        printf("\nEnter the serial number of record to be deleted: ");
        scanf("%d",&loc);
            if(loc==0)
            {
                pre=head;
                head=head->add;
                printf("\nRecord deleted!");
                    free(pre);
            }
            else
            {
                pre=head;
                for(i=0;i<loc;i++) 
                { 
                    rep=pre; 
                    pre=pre->add;
                    if(pre==NULL)
                    {
                        printf("\nNode not found :/");
                        return 0;
                    }
                }
                rep -> add = pre -> add;
                printf("\nRecord deleted!");
                    free(pre);
            }
    }
    return 0;
}
