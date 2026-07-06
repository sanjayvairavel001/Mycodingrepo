#include <stdio.h>

int trap(int* height, int heightSize) {
    if (heightSize <= 2) {
        return 0; // Cannot trap water with fewer than 3 bars
    }

    int left = 0;
    int right = heightSize - 1;
    
    int left_max = 0;
    int right_max = 0;
    
    int total_water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            // Update left_max if current height is greater
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                // Water trapped is the boundary height minus the bar height
                total_water += left_max - height[left];
            }
            left++;
        } else {
            // Update right_max if current height is greater
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                // Water trapped is the boundary height minus the bar height
                total_water += right_max - height[right];
            }
            right--;
        }
    }

    return total_water;
}