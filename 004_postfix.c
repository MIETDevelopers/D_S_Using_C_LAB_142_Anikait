#include<stdio.h>

int stack[20];  
int top = -1;  
int n1,n2,n3,num; 
void push(int x)
	{       
	    top=top+1;
	    stack[top]=x;
	}
	
int pop()
{
    return stack[top--]; 
}

	int main()
	{
	    char exp[20];
	    char *e;
	    printf("Welcome to Postfix Operations");
		printf("  Only enter in this e.g: abc+-*/  ")	;
	    printf("Enter the expression in the postfix :: ");
	    scanf("%s",exp);
	    e = exp;
	    while(*e)        
	    {
	        if(isdigit(*e))
	        {
	            num = *e -'0'; 
	            push(num);
	        }
	        else
	        {
	            n1 = pop();
	            n2 = pop();
	            switch(*e)
	            {
	            case '+':
	            {
	                n3 = n1 + n2;
	                break;
	            }
	            case '-':
	            {
	                n3 = n2 - n1;
	                break;
	            }
	            case '*':
	            {
	                n3 = n1 * n2;
	                break;
	            }
	            case '/':
	            {
	                n3 = n2 / n1;
	                break;
	            }
	            }
	            push(n3);
	        }
	        e++; // Post Increment  because it increments e's value by 1 after the operation is over.
	    }
	    printf("\nThe result of expression %s  =  %d\n\n",exp,pop());
	    return 0;
	
}
