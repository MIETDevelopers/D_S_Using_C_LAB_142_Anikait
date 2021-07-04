//Author: Anikait Singh
//Creation date: 23 May,2021
//Purpose: Implement a Stack using Array and develop functions to perform push and pop operations.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int a[20], n, x,lim = -1, i;
int push();
int pop();
void view();
int main()
{
    int ch;
    printf("Enter the size of stack: ");
    scanf("%d",&n);
    printf("\n\n\t\t\t**MENU FOR STACK**\n\n");
    while(1){
        printf("\nEnter 1 to push element in stack.");
        printf("\nEnter 2 to pop element in stack.");
        printf("\nEnter 3 to view element in stack.");
        printf("\nEnter 4 to Exit.");
        printf("\n\nEnter the choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:push();
                        break;
            case 2:pop();
                        break;
            case 3:view();getch();
                        break;
            case 4:exit(0);
            default:printf("\n\n\t**Enter the right choice given in menu**\n\n ");
        }
    }
    return 0;
}

int push()
{
    if (lim == n - 1)
        printf("\nStack is overflowing\n");
    else
    {
        printf("\nEnter the elements: ");
        scanf("%d",&x);
        lim = lim + 1;
        a[lim] = x;
    }
    return 0;
}

int pop()
{
    if(lim == -1)
        printf("\nStack is underflowing\n");
    else
    {
        printf("\nElement %d has been popped out from stack\n",a[lim]);
        lim = lim - 1;
    }
    return 0;
}

void view()
{
    if (lim == -1){
        printf("\nEmpty!!!!!");
    }
    else{
        printf("\nElements of the  first stack:\n");
        for(i = lim; i>=0; --i){
            printf("%d\n",a[i]);
        }
    }
}
