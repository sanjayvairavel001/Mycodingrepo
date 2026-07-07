#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function for backtracking
void backtrack(int* candidates, int candidatesSize, int target, int index, 
               int* currentCombination, int currentSize, 
               int*** results, int* resultCount, int** returnColumnSizes, int* maxResults) {
    
    // Base Case 1: If target is reached, save the current combination
    if (target == 0) {
        // If results array is full, double its capacity
        if (*resultCount >= *maxResults) {
            *maxResults *= 2;
            *results = (int**)realloc(*results, (*maxResults) * sizeof(int*));
            *returnColumnSizes = (int*)realloc(*returnColumnSizes, (*maxResults) * sizeof(int));
        }
        
        // Allocate space and copy the current combination
        (*results)[*resultCount] = (int*)malloc(currentSize * sizeof(int));
        memcpy((*results)[*resultCount], currentCombination, currentSize * sizeof(int));
        (*returnColumnSizes)[*resultCount] = currentSize;
        (*resultCount)++;
        return;
    }
    
    // Base Case 2: If target is exceeded or we ran out of elements
    if (target < 0 || index >= candidatesSize) {
        return;
    }
    
    // Option 1: Choose the current candidate (we don't increment index because we can reuse it)
    currentCombination[currentSize] = candidates[index];
    backtrack(candidates, candidatesSize, target - candidates[index], index, 
              currentCombination, currentSize + 1, 
              results, resultCount, returnColumnSizes, maxResults);
              
    // Option 2: Skip the current candidate and move to the next one
    backtrack(candidates, candidatesSize, target, index + 1, 
              currentCombination, currentSize, 
              results, resultCount, returnColumnSizes, maxResults);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *returnColumnSizes array must be malloced.
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    // Initial guess for maximum number of valid combinations (grows dynamically if needed)
    int maxResults = 150; 
    int** results = (int**)malloc(maxResults * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxResults * sizeof(int));
    
    // An array to keep track of the current path combination
    // Since constraints state target <= 40 and candidates[i] >= 2, max depth is 40 / 2 = 20
    int* currentCombination = (int*)malloc(40 * sizeof(int)); 
    
    int resultCount = 0;
    
    // Start backtracking from index 0
    backtrack(candidates, candidatesSize, target, 0, currentCombination, 0, &results, &resultCount, returnColumnSizes, &maxResults);
    
    // Clean up temporary path array
    free(currentCombination);
    
    // Set the total number of unique combinations found
    *returnSize = resultCount;
    return results;
}