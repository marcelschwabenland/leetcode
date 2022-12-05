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

void selectionsort(int *array, int size) {
  for(int i = 0; i < size; i++) {
    int smallest = array[i];
    int pos;
    for(int j = i; j < size; j++) {
      if(smallest > array[j]) {
        smallest = array[j];
        pos = j;
      }      
    }
    
    if(array[i] > smallest) {
      array[pos] = array[i];
      array[i] = smallest;
    }
    
    printArray(array, size);
  }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
  *returnSize = numsSize;
  int *numbers = malloc(sizeof(int) * numsSize);

  int *a, *b;
  
  for(int i = 0; i < numsSize; i++) {
    numbers[i] = nums[i] * nums[i];
  }

  selectionsort(numbers, numsSize);

  return numbers;
}

int main(int argc, char const *argv[]){
  int nums[5] = {-4,-1,0,3,10};
  int *output = malloc(sizeof(int[5]));
  int returnSize = 5;

  printf("unsorted array: ");
  printArray(nums, 5);
  output = sortedSquares(nums, 5, &returnSize);
  printf("numsSize: %d\n");
  printf("returnSize: %d\n");
  printf("sorted array: ");
  printArray(output, returnSize);

  free(output);

  return 0;
}
