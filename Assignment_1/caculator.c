#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
int isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int calculator(char * expression)
{
    int number[100],numindex = 0;
    char operators[100];
    int opindex =0 , i =0;
    while(expression[i] != '\0')
    {
        if(isdigit(expression[i]))
        {
            int num = 0;
            while(isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            number[numindex++] = num;

        }
        else if (isOperator(expression[i])){
            operators[opindex++] = expression[i];
            i++;
        }
        else if (isspace(expression[i]))
        {
            i++;
        }
        else{
            printf("Error : invalid expression");
            return -1;
        }
    }
    for (i=0;i<opindex;i++)
    {
        if (operators[i] == '*' || operators[i] == '/'){
            if(operators[i] == '/' && number[i+1] == 0)
            {
                printf("Error : Division by zero");
                return -1;
            }
            int result =(operators[i] == '*') ? (number[i] * number[i+1]) : (number[i] / number[i+1]);
            number[i]=result;
            for(int j=i+1; j<numindex -1 ; j++)
            {
                number[j] = number[j+1];

            }
            for(int j = i ; j< opindex -1 ; j++)
            {
                operators[j] = operators[j+1];
            }
            numindex--;
            opindex--;
            i--;
        }
    }
    int result = number[0];
    for(i =0 ; i<opindex;i++){
        if(operators[i] == '+'){
            result += number[i+1];
        }
        else if (operators[i]== '-')
        {
            result -= number[i+1];
        }
    }
    return result;

}
int main(){
    char expression[100];
    printf("enter the equation");
    fgets(expression  , 100 , stdin);
    int result = calculator(expression);
    if(result != -1)
    {
        printf("%d" , result);
    }
}