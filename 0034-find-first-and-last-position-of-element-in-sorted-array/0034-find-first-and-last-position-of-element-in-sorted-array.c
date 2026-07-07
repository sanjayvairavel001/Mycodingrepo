/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int findBound(int* nums, int numsSize, int target, int isFirst) {
    int left = 0, right = numsSize - 1;
    int bound = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            bound = mid;
            if (isFirst) {
                right = mid - 1; // Look left for first occurrence
            } else {
                left = mid + 1;  // Look right for last occurrence
            }
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return bound;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    result[0] = findBound(nums, numsSize, target, 1);
    result[1] = findBound(nums, numsSize, target, 0);
    
    return result;
}