#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int longestValidParentheses(char* s) {
    int n = strlen(s);
    if (n == 0) return 0;

    // Stack to store indices. Max size needed is n + 1 (for the initial -1)
    int* stack = (int*)malloc((n + 1) * sizeof(int));
    int top = -1;

    // Base indicator for valid substring length calculation
    stack[++top] = -1; 
    int maxLen = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            // Push index of opening parenthesis
            stack[++top] = i; 
        } else {
            // Pop the last matching '(' index or boundary
            top--; 
            
            if (top == -1) {
                // If stack is empty, push current index as the new base boundary
                stack[++top] = i; 
            } else {
                // Stack is not empty, calculate length of the current valid substring
                int currentLen = i - stack[top];
                maxLen = MAX(maxLen, currentLen);
            }
        }
    }

    free(stack);
    return maxLen;
}