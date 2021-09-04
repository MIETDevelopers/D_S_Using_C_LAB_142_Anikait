//Author: Anikait Singh
//Creation date: 01 Aug,2021
//Purpose: A program to evaluate postfix, prefix and infix expressions using Stacks.
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define max_1 30
#define max_2 30

int lim1 = -1, lim2 = -1,lim = 0;
float stack_opnd[30];
char stack_optr[30];
char str[80];

int push_opnd(float);
int push_optr(char);
int view_opnd();
int view_optr();
float eval();
float pop_opnd();
int pop_optr();
int pre(char);

int main(){
    int num;
    char val;

    printf("Enter the infix expression : ");
    scanf("%[^\n]s",str);
    printf("Expression = %s\n",str);
    for(int i = 0; str[i] != '\0'; i++){
        val = str[i];
        if(isdigit(val)){
            num = val - '0';
            push_opnd((float)num);
        }
        else{
            push_optr(val);
        }

    }
    view_opnd();
    view_optr();
    printf("\nResult = %0.2f\n",eval());
}

int push_opnd(float num){
    if(lim1 == max_1 - 1){
        printf("\nStack is overflowing");
    }
    else{
        lim1 = lim1 + 1;
        stack_opnd[lim1] = num;

    }
    return 0;
}

int push_optr(char val){
    int num_1, num_2, result, pre_optr;
    char value;
    if(lim2 == max_2 -1){
        printf("\nStack is Overflowing");
    }
    else if(lim2 == -1){
        lim = pre(val);
        lim2 = lim2 + 1;
        stack_optr[lim2] = val;
    }
    else{
        pre_optr = pre(val);
        if(pre_optr>lim){
            lim2++;
            stack_optr[lim2] = val;
        }
        else{
            value = pop_optr();
            num_1 = pop_opnd();
            num_2 = pop_opnd();
            if(value == '+'){
                result = num_1 + num_2;
            }
            else if(value == '-'){
                result = num_1 - num_2;
            }
            else if (value == '*'){
                result = num_1 * num_2;
            }
            else if(value == '/'){
                result = num_2 / num_1;
            }
            else{

                printf("Error!!! Enter a valid Operator");
            }
            push_opnd(result);
            lim2++;
            stack_optr[lim2] = val; 
        }
    }
    return 0; 
}

int view_opnd(){
    int i;
    if(lim1 == -1){
        printf("No operand present in stack\n");
    }
    else{
        printf("Operand in stack are\n\n");
        for(int i = lim1; i >=0; --i){
            printf("%0.2f\t",stack_opnd[i]);
        }
    }
    return 0;
}

int view_optr(){
    int i;
    if(lim2 == -1){
        printf("No operator present in stack\n");

    }
    else{
        printf("\n\nOperators present in stack are: \n\n");
        for(int i = lim2; i>=0; --i){
            printf("%c\t",stack_optr[i]);
        }
    }
    return 0;
}

float eval(){
    float num_1, num_2, result;
    char value;
    if(lim1 == -1){
        printf("Operator stack is Empty");
        exit(0);
    }
    else{
        for(int i = lim2; lim2>=0; i++){
            value = pop_optr();
            num_1 = pop_opnd();
            num_2 = pop_opnd();
            if(value == '+'){
                result = num_1 + num_2;
            }
            else if(value == '-'){
                result = num_1 - num_2;
            }
            else if (value == '*'){
                result = num_1 * num_2;
            }
            else if(value == '/'){
                result = num_2 / num_1;
            }
            else{
                printf("Error!!! Enter a valid Operator\n");
            }
            push_opnd((float)result);
        }
    }
    return stack_opnd[0];
}

float pop_opnd(){
    float number;
    if(lim1 == -1){
        printf("No operand present in stack");
        exit(0);
    }
    else{
        number = stack_opnd[lim1--];
    }
    return ((float) number);
}

int pop_optr(){
    int value;
    if(lim2 == -1){
        printf("No Operator present in stack");
        exit(0);
    }
    else{
        value = stack_optr[lim2--];
    }
    return value;
}

int pre(char val){
    if(val == '+' || val=='-'){
        return 1;
    }
    else if(val == '*' || val=='/'){
        return 2;
    }
    return 0;
}
