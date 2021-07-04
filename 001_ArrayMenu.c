//Author: Anikait Singh
//Creation date: 20 May,2021
//Purpose: To create Menu for an array to insert, view, search, re-enter and delete array.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[20],n;
void insert();
int view();
int search();
int del();
int enter();
int main()
{
    int ch;
    int i;
    printf("Enter the size in an array: ");
    scanf("%d",&n);
    printf("\nEnter %d elements in an array:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(1){
    	printf("\nEnter 1 to insert element in array.");
    	printf("\nEnter 2 to view element in array.");
    	printf("\nEnter 3 to search element in array.");
    	printf("\nEnter 4 to Delete element in array.");
        printf("\nEnter 5 to re-enter element in array.");
    	printf("\nEnter 6 to Exit.");
    	printf("\n\nEnter the choice: ");
    	scanf("%d",&ch);
    	switch(ch){
        	case 1:insert(a);getch();
            	        break;
        	case 2:view(a);getch();
            	        break;
        	case 3:search(a);getch();
        				break;
       		case 4:del(a);getch();
            	        break;
            case 5:enter(a);getch();
                        break;
        	case 6:exit(0);
    	}
	}
	return 0;
}

void insert()
{
    int l,x,i;
    printf("\nEnter location to insert an element: ");
    scanf("%d",&l);
    printf("\nEnter element to be inserted: ");
    scanf("%d",&x);
    n=n+1;
    for(i=n-1;i>=l;i--){
        a[i]=a[i-1];
    }

    a[i]=x;
    printf("\nArray After insertion is: \n");
    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    a[i]='\0';
}

int view()
{
    int j;
    for(j=0;a[j]!=NULL;j++)
    {
        printf("\nElement at index %d of array: %d", j, a[j]);
    }
    return 0;
}

int search()
{
	int i, j;
	printf("Enter element to search: "); 
    scanf("%d",&j);
     
    for(i=0;i<n;++i)
        if(a[i]==j)
            break;
     
if(i<n){
        printf("Element %d found at index %d", j, i);
    }     
    else{
        printf("Element not found"); 
    }
    return 0;
}

int del()
{
    int c,k,posi;
    for(k=0;a[k]!=NULL;k++)
    {
    }
    printf("\nEnter the position to delete element: ");
    scanf("%d",&posi);
    if(posi<=k)
    {
        for(c=posi-1;c<k-1;c++)
        {
            a[c]=a[c+1];
        }
        printf("\nArray after Deletion");
        for(c=0;c<k-1;c++)
        {
            printf("\n%d",a[c]);
        }
    }
    a[c]='\0';
    return 0;
}

int enter()
{
    int i;
    printf("Enter the size in an array: ");
    scanf("%d",&n);
    printf("\nEnter %d elements in an array:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    a[i]='\0';
    return 0;
}    
