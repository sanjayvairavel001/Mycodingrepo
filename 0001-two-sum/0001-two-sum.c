#include <stdlib.h>

// Structure for our hash map elements
typedef struct {
    int key;
    int value;
} HashElement;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Per the constraints, we need to return 2 indices
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Allocate a hash table. Using a size roughly 2-3x larger than numsSize
    // helps minimize collisions and keeps lookups close to O(1).
    int mapSize = numsSize * 2;
    HashElement* hashTable = (HashElement*)calloc(mapSize, sizeof(HashElement));
    
    // We need a helper array to check if a bucket is occupied because 0 is a valid index.
    int* isOccupied = (int*)calloc(mapSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        // Compute hash index (handling negative keys correctly)
        int hashIndex = abs(complement) % mapSize;
        
        // Linear probing to search for the complement
        while (isOccupied[hashIndex]) {
            if (hashTable[hashIndex].key == complement) {
                // Found the pair! Fill the result and clean up memory
                result[0] = hashTable[hashIndex].value;
                result[1] = i;
                
                free(hashTable);
                free(isOccupied);
                return result;
            }
            hashIndex = (hashIndex + 1) % mapSize;
        }
        
        // If complement not found, insert the current number into the hash table
        int insertIndex = abs(nums[i]) % mapSize;
        while (isOccupied[insertIndex]) {
            insertIndex = (insertIndex + 1) % mapSize;
        }
        hashTable[insertIndex].key = nums[i];
        hashTable[insertIndex].value = i;
        isOccupied[insertIndex] = 1;
    }

    // Clean up if no solution is found (though constraints guarantee exactly one solution)
    free(hashTable);
    free(isOccupied);
    return NULL;
}