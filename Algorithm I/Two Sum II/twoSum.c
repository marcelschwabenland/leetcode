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

int search(int* nums, int numsSize, int target, int blocked){
  int left = 0;
  int right = numsSize - 1;
  int mid = (left + right)/2;

  while (left <= right) {
    mid = (left + right)/2;
    int temp = nums[mid];
    if (nums[mid] == target && mid != blocked) {
      return mid;
    } else if (nums[mid] > target) {
      right = mid - 1;
    } else if (nums[mid] <= target) {
      left = mid + 1;
    }
  }  
  
  return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
  *returnSize = 2;
  int *res = malloc(sizeof(int) * 2);
  if(res == NULL) {
    return NULL;
  }

  res[0] = 0;
  res[1] = -1;

  for(int i = 0; i < numbersSize && res[1] == -1 && res[0] != res[1]; i++) {
    res[0] = i;
    res[1] = search(numbers, numbersSize, target - numbers[i], i);
  }

  res[0]++;
  res[1]++;

  return res;
}

int main() {
  int case1[4] = {2,7,11,15};
  int case2[3] = {2,3,4};
  int case3[5] = {-1,-1,-1,1,1};

  int returnSize;
  int *res;

  res = twoSum(case1, 4, 9, &returnSize);
  printArray(res, returnSize);
  free(res);

  res = twoSum(case2, 3, 6, &returnSize);
  printArray(res, returnSize);
  free(res);

  res = twoSum(case3, 5, 2, &returnSize);
  printArray(res, returnSize);
  free(res);

  return 0;
}