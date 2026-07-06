#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) return false;
            
            if ((c == ')' && stack[top] != '(') ||
                (c == '}' && stack[top] != '{') ||
                (c == ']' && stack[top] != '[')) {
                return false;
            }
            top--;
        }
    }
    
    return top == -1;
}