//test
#include <stdio.h>

void myPrintHelloMake(void) {
  printf("Hello makefiles!\n");
}

int main() {
  // call a function in another file
  myPrintHelloMake();

  return(0);
}
