#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
  int *array = malloc(sizeof(int) * 5);

  for(int i = 0; i < 5; i++) {
    array[i] = i + 1;
  }

  for(int i = 0; i < 5; i++) {
    printf("%p\n", array);
    array++;
  }
  
  free(array);
  return 0;
}
