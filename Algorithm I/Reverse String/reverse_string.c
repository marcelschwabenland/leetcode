#include <stdio.h>

void reverse_string(char *s, int sSize) {
  char *p1 = s;
  char *p2 = s + sSize - 1;

  while (p1 < p2) {
    char temp = *p1;
    *p1++ = *p2;
    *p2-- = temp;
  }
  return;
}

int main() {
  char case1[5] = "Hello";
  char case2[6] = "Hannah";

  printf("%s -", case1);
  reverse_string(case1, 5);
  printf(" %s\n", case1);
  printf("%s -", case2);
  reverse_string(case2, 6);
  printf(" %s\n", case2);

  return 0;
}