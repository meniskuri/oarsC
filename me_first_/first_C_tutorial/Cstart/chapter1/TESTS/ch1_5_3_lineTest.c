/*
- TESTInG chapter 1.5.3 Line counting
- count lines in input
*/

#include <stdio.h>

main()
{
  int c, nl;
  nl = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == "\n"){
      ++nl;
    }
  }

  printf("%d\n", nl);
}
