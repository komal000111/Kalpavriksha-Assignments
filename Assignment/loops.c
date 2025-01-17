//loops

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int mainn();
int transpose();
int main()
{
     mainn();
     transpose();
     
}
int mainn()//a program to evaluate the equation y=x^n where x is not negative
{
    int count , n;
    float x, y;
    printf("enter the value of x & n = \n");
    scanf("%d %f" , &n , &x);
    y=1.0;
    count = 1;
    while(count <= n)
    {
        y = y*x;
        count++;
    }
    printf("\nx= %f; n= %d ; x to power n = %f\n",x, n, y);
    return 0;
}
int transpose()  //transpose of the matrix
{
int rows = 2, cols = 2;
    int mat[2][2], trans[2][2];
    int i, j;

    // Input matrix elements
    printf("\nEnter elements of a 2x2 matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Print the original matrix
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // Compute transpose
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }

    // Print the transpose matrix
    printf("\nTranspose of Matrix:\n");
    for (i = 0; i < cols; i++) {
        for (j = 0; j < rows; j++) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }
}
