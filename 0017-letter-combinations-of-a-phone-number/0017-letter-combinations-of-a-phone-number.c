
const char* phoneMap[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void backtrack(const char* digits, int index, char* current, int len, char** result, int* returnSize) {
    if (index == len) {
        result[*returnSize] = (char*)malloc((len + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    int digit = digits[index] - '0';
    const char* letters = phoneMap[digit];
    for (int i = 0; letters[i] != '\0'; i++) {
        current[index] = letters[i];
        backtrack(digits, index + 1, current, len, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;
    int len = strlen(digits);
    if (len == 0) {
        return NULL;
    }

    int maxCombinations = 1;
    for (int i = 0; i < len; i++) {
        int digit = digits[i] - '0';
        if (digit == 7 || digit == 9) {
            maxCombinations *= 4;
        } else {
            maxCombinations *= 3;
        }
    }

    char** result = (char**)malloc(maxCombinations * sizeof(char*));
    char* current = (char*)malloc((len + 1) * sizeof(char));
    current[len] = '\0';

    backtrack(digits, 0, current, len, result, returnSize);

    free(current);
    return result;
}