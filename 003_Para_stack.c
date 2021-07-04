//Author: Anikait Singh
//Creation date: 4 JUNE,2021
//Purpose: Perfect paranthesis using stack.
#include<stdio.h>   //Pre processor directive to include standard input and output function header file.    
#include<string.h>
#include<stdlib.h>
char *a, ch[50];
int lim = -1,i;
int push();
void pop();
int main(){ //Start of the main body.
    int n, d, cho;

    printf("Enter the size of stack: ");
    scanf("%d",&n);
    a = (char*)malloc(n * sizeof(char));

     printf("\n\n\t\t\t**MENU FOR ENTRING STATEMENT**\n\n");
    while(1){
        printf("\nPress 1 to enter statement");
        printf("\nEnter 2 to Exit.");
        printf("\n\nEnter the choice: ");
        scanf("%d",&cho);
        switch(cho){
            case 1:printf("Enter the statement \n\n");
            scanf("%s",ch);
            printf("\n\nEntered statement :-  %s is ",ch);
            for (i = 0; ch[i] != '\0';i++){
                if (ch[i] == '('){
                    push();
                }
                else if (ch[i] == ')'){
                    pop();
                }
            }
            if (lim == -1)
                printf("valid\n\n");
            else
                printf("not valid\n\n");
            break;
            case 2:exit(0);
            default:printf("\n\n\t**Enter the right choice given in menu**\n\n ");
        }
    }
    return 0;   //Return statment.
}   //End

int push(){
        a[lim] = *ch;
        lim = lim + 1;
    return 0;
}

void pop()
{
    if(lim == -1) 
        printf("not ");
    else
    {
        lim = lim - 1;
    }
}
