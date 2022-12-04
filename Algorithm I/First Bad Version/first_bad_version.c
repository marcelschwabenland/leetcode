#include <stdio.h>
#include <stdbool.h>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    unsigned int left = 1;
    unsigned int right = n;
    unsigned int mid = (left + right)/2;
    
    while (left <= n) {
        mid = (left + right)/2;
        
        if (isBadVersion(mid) == true && isBadVersion(mid - 1) == false) {
            return mid;
        } 
        
        if (isBadVersion(mid) == true){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return 1;
}

int main(int argc, char const *argv[]) {

  return 0;
}