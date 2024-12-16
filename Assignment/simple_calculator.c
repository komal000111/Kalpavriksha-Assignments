#include<stdio.h>
 int sum(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int divide(int num1, int num2);
int main()

{
    int num1 , num2;
printf("Enter the first number: ");
    scanf("%d" , &num1);
    printf("Enter the second number: ");
    scanf("%d" , &num2);
   
    printf("1 .for addition + \n");
    printf("2 .for subtraction - \n");
    printf("3 .for multiplication * \n");
    printf("4 .for division / \n");
    printf("enter your choice \n");
    char character;
     while (getchar() != '\n');  
    
    character = getchar();
    switch (character)
    {
    case '+':
        printf("Result: %d\n", sum(num1, num2));


        break;
    case '-':
        printf("Result: %d\n", sub(num1, num2));
        

        break;
    case '*':
        printf("Result: %d\n", mul(num1, num2));
        

        break;
    case '/':
       printf("Result: %d\n", divide(num1, num2));
        

        break;
    default:
        break;
    }

return 0;


}
int sum(int num1 , int num2)
{
    return num1+num2;

}
int sub(int num1 , int num2 )
{
    return num1 - num2;
}
int mul(int num1 , int num2)
{
    return num1*num2;
}
int divide(int num1 , int num2)
{
    return num1/num2;
}