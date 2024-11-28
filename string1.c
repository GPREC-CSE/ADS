#include<stdio.h>
#include<string.h>

void main() {
    int m, n, i, j;
    char t[100], p[100];
    
    // Read the text and pattern
    printf("Enter text String: ");
    scanf("%[^\n]%*c", t);  // Reading text string
    printf("Enter String to search: ");
    scanf("%[^\n]%*c", p);  // Reading pattern string
    
    n = strlen(t);  // Length of the text
    m = strlen(p);  // Length of the pattern
    
    printf("The length of Text string is %d\n", n);
    printf("The length of the Searching String is %d\n", m);

    // Searching for the pattern in the text
    for(i = 0; i <= n - m; i++) {  // i can go up to n - m
        j = 0;
        while(j < m && p[j] == t[i + j]) {
            j++;
            if(j == m) {  // Found the pattern
                printf("String found at position %d\n", i + 1);
                getchar();  // Pause before exiting
                return;
            }
        }
    }

    // If pattern is not found
    printf("String not found\n");
    getchar();  // Pause before exiting
}