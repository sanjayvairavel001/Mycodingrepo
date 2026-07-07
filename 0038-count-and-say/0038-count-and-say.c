#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    if (n <= 0) return "";

    // The maximum length of the string at n = 30 is within a few thousand characters.
    // Allocating a safe upper bound buffer size.
    int max_len = 10000; 
    char* current = (char*)malloc(max_len * sizeof(char));
    char* next_str = (char*)malloc(max_len * sizeof(char));
    
    // Base case: n = 1
    strcpy(current, "1");

    // Generate the sequence iteratively from 2 to n
    for (int i = 2; i <= n; ++i) {
        int len = strlen(current);
        int j = 0;
        int k = 0; // Index for next_str

        while (j < len) {
            char ch = current[j];
            int count = 0;

            // Count consecutive identical characters
            while (j < len && current[j] == ch) {
                count++;
                j++;
            }

            // Append count and character to next_str
            k += sprintf(&next_str[k], "%d%c", count, ch);
        }
        
        // Copy the newly built sequence to current for the next iteration
        strcpy(current, next_str);
    }

    free(next_str);
    return current;
}