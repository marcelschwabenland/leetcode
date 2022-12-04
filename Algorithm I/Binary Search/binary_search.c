#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target){
  int left = 0;
  int right = numsSize - 1;
  int pivot = (left + right)/2;

  while (left <= right) {
    pivot = (left + right)/2;
    if (nums[pivot] == target) {
      printf("%d", pivot);
      return pivot;
    } else if (nums[pivot] > target) {
      right = pivot - 1;
    } else if (nums[pivot] < target) {
      left = pivot + 1;
    }
  }  
  
  printf("%d", pivot);
  return -1;
}

int main(int argc, char const *argv[]) {
  int nums[6] = {-1,0,3,5,9,12};

  search(nums, 6, 9);
  search(nums, 6, 2);
  return 0;
}
