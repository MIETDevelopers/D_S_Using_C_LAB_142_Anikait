//Author: Anikait Singh
//Creation date: 22 June,2021
//Purpose: Implement a Queue using Array and develop functions to perform enqueue and dequeue operations.
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int *a;
int n, x, rear = -1,front = -1;
int push();
int pop();
void view();
int main()
{
    int ch;
    printf("Enter the size of queue: ");
    scanf("%d",&n);
    a = (int*)malloc(n * sizeof(int));
    printf("\n\n\t\t\t**MENU FOR Queue**\n\n");
    while(1){
        printf("\nEnter 1 to enqueue element in stack.");
        printf("\nEnter 2 to dequeue element in stack.");
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
    if (rear == n -1)
        printf("\nQueue is overflowing\n");
    else
    {
        if(front == - 1)
            front = 0;
        printf("\nEnter the elements: ");
        scanf("%d",&x);
        rear = rear + 1;
        a[rear] = x;
    }
    return 0;
}

int pop()
{
    if(front == -1 || front > rear)
        printf("\nQueue is underflowing\n");
    else
    {
        printf("\nElement %d has been popped out from queue\n",a[front]);
        front = front + 1;
    }
    return 0;
}

void view()
{
    int i;
    if (front == -1){
        printf("\nEmpty!!!!!");
    }
    else{
        printf("\nElements of the queue:\n");
        for(i = front; i <= rear; ++i){
            printf("%d\n",a[i]);
        }
    }
}
