#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LENGTH 100
#define NUM_STRINGS 10

int main( )
{
  // Array s - tutorial
  char arr[NUM_STRINGS][MAX_LENGTH] = {""};

  // arr2[0] = "string literal"; // Not permitted
  strcpy(arr[0], "hello world");
  printf("%s\n", arr[0]);
  printf("%s\n", strcpy(arr[0], "hello world"));

  exit(EXIT_SUCCESS);


  return 0;
}
