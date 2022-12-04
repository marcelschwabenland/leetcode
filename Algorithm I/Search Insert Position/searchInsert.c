#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target){
  int left = 0;
  int right = numsSize - 1;
  int mid = (left + right)/2;

  while (left <= right) {
    mid = (left + right)/2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      right = mid - 1;
    } else if (nums[mid] < target) {
      left = mid + 1;
    }
  }  
  
  return left;
}

int main(int argc, char const *argv[]) {
  int nums[4] = {1,3,5,6};

  printf("position: %d\n", search(nums, 4, 5));
  printf("position: %d\n", search(nums, 4, 0));
  printf("position: %d\n", search(nums, 4, 2));
  printf("position: %d\n", search(nums, 4, 4));
  printf("position: %d\n", search(nums, 4, 7));
  printf("position: %d\n", search(nums, 4, 8));

  return 0;
}
