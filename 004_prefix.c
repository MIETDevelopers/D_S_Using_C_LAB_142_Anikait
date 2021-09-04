#include<stdio.h>  
#include<conio.h>  
#include<string.h>   
	
int James[20]; 
int top=-1; 
int A,B,i; 

void push(int value)
{
	top=top+1;
	James[top]=value;
	
}
	
int pop(){
	
	return(James[top--]);
	
	}
	
	int ope(char c)
	
	{
	
			if(c=='+'||c=='-'||c=='*'||c=='/')
	
				return 1;
		
	else
	
	return 0;
	
	}
	
	void main()
	
	{
	int exp1;
	int exp2;
	int res;
		char prefix[10];
	
	printf("Enter the prefix Expression: ");
	
	scanf("%s",prefix);
	
	A=strlen(prefix);
	
	for(i=A-1;i>=0;i--)
	
	{
	
		switch(ope(prefix[i]))
	
	{
	
	case 0:
		
			B=prefix[i];
			
				push(B);
		
						break;
	
	
	
	case 1: 	exp1=pop();
	
					 exp2=pop();
		
		switch(prefix[i])
	
	{
	
			case '+': res=exp1+ exp2;
	
						break;
	
		case '-': res=exp1- exp2;
	
						break;
	
	case '*': res=exp1* exp2;
	
					break;
	
	case '/': res=exp1/ exp2;
	
					break;
	
	}
	
	push(res);
	
	}
	
	}
	
	printf("Result is %d",James[top]);
	
		
	}
