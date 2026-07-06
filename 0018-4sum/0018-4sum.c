
int compare(const void* a, const void* b) {
    long long va = *(const int*)a;
    long long vb = *(const int*)b;
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (numsSize < 4) {
        *returnColumnSizes = NULL;
        return NULL;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 16;
    int** result = (int**)malloc(capacity * sizeof(int*));
    *returnColumnSizes = (int*)malloc(capacity * sizeof(int));

    for (int i = 0; i < numsSize - 3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        // Optimization: Smallest possible sum from here exceeds target
        if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
        // Optimization: Largest possible sum with this nums[i] is less than target
        if ((long long)nums[i] + nums[numsSize - 3] + nums[numsSize - 2] + nums[numsSize - 1] < target) continue;

        for (int j = i + 1; j < numsSize - 2; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;
            
            // Optimization checks for the second loop
            if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
            if ((long long)nums[i] + nums[j] + nums[numsSize - 2] + nums[numsSize - 1] < target) continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target) {
                    if (*returnSize >= capacity) {
                        capacity *= 2;
                        result = (int**)realloc(result, capacity * sizeof(int*));
                        *returnColumnSizes = (int*)realloc(*returnColumnSizes, capacity * sizeof(int));
                    }

                    result[*returnSize] = (int*)malloc(4 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }

    return result;
}