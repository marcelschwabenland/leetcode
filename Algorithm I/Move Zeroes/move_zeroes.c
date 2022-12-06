#include <stdio.h>

void printArray(int *nums, int numsSize) {
  printf("[ ");
  for(size_t i = 0; i < numsSize; i++){
    if(i + 1 == numsSize) {
      printf("%d ", nums[i]);
    } else {
      printf("%d, ", nums[i]);
    }    
  }
  printf("]\n");
}

void moveZeroes(int* nums, int numsSize){
  for(int i = 0; i < numsSize; i++) {
    // find first zero
    if(nums[i] == 0) {
      for(int j = i; j < numsSize; j++) {
        // find first non-zero
        if(nums[j] != 0) {
          // swap
          int swap = nums[j];
          nums[j] = nums[i];
          nums[i] = swap;
          i++; // increament i
        }
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int nums[5] = {0,1,0,3,12};
  printArray(nums, 5);
  moveZeroes(nums, 5);
  printArray(nums, 5);
  return 0;
}
