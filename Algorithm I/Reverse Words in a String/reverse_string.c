#include <stdio.h>

void reverse_word(char *p1, char *p2) {
  while (p1 < p2) {
    char temp = *p1;
    *p1++ = *p2;
    *p2-- = temp;
  }
  return;
}

char *reverse_string(char *s) {
  if (*s == '\0') {
    return s;
  }
  char *p1 = s;
  char *p2 = s;
  char *p3 = s;

  while (*p3 != '\0') {
    if (*p3 == ' ') {
      p2 = p3 - 1;
      reverse_word(p1, p2);
      p1 = p3 + 1;
    }
    p3++;
  }

  if (*p3 == '\0') {
    p2 = p3 - 1;
    reverse_word(p1, p2);
  }
  return s;
}

int main() {
  char case1[28] = "Let's take LeetCode contest";
  char case2[9] = "God Ding";

  printf("%s -", case1);
  reverse_string(case1);
  printf(" %s\n", case1);
  printf("%s -", case2);
  reverse_string(case2);
  printf(" %s\n", case2);

  return 0;
}