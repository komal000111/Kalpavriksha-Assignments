#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LENGTH 50


int is_vowel(char ch) {
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
    int rows, cols;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH];
    char longest_name[MAX_NAME_LENGTH] = "";
    int vowel_count = 0;

    
    do {
        printf("Enter the number of rows (1-10): ");
        scanf("%d", &rows);
    } while (rows < 1 || rows > MAX_ROWS);

    do {
        printf("Enter the number of columns (1-101): ");
        scanf("%d", &cols);
    } while (cols < 1 || cols > MAX_COLS);

    
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Name[%d][%d]: ", i + 1, j + 1);
            scanf("%s", names[i][j]);

            
            if (is_vowel(names[i][j][0])) {
                vowel_count++;
            }

            
            if (strlen(names[i][j]) > strlen(longest_name)) {
                strcpy(longest_name, names[i][j]);
            }
        }
    }

    printf("\nNames in matrix format:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%-15s ", names[i][j]);
        }
        printf("\n");
    }

    
    printf("vowel : %d\n", vowel_count);

    
    printf("longest name :  %s\n", longest_name);

    return 0;
}   