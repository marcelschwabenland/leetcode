#include <stdio.h>
#include <stdlib.h>

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

void rotate(int* nums, int numsSize, int k){
  int *copy = malloc(sizeof(int) * numsSize);

  if(copy == NULL || k == 0 || k == numsSize || numsSize == 1) {
    return;
  }

  for(int i = 0; i < numsSize; i++) {
    copy[i] = nums[i];
  }

  for(int i = 0; i < numsSize; i++) {
    nums[(i + k) % numsSize] = copy[i];
    printArray(nums, numsSize);
  }

  free(copy);
}

int main(int argc, char const *argv[]){
  int nums[7] = {1,2,3,4,5,6,7};

  printf("unsorted array: ");
  printArray(nums, 7);
  rotate(nums, 7, 3);
  printf("numsSize: %d\n");
  printf("returnSize: %d\n");
  printf("rotated array: ");
  printArray(nums, 7);

  return 0;
}
