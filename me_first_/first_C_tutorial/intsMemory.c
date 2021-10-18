//int's
#include <stdlib.h>
#include <stdio.h>

int main()
{
   unsigned int a = 1;
   int b = 1;
   unsigned long c = 1;
   long long d = 1;
   printf("%u", a);
   printf("%d", b);
   printf("%lu", c);
   printf("%lld\n", d);
   
   printf("size of int : %d\n",sizeof(int));
   printf("size of signed int : %d\n",sizeof(signed int));
   printf("size of unsigned long : %d\n",sizeof(unsigned long));
   return 0;
}









