// chapter 1

#include <stdio.h>

int main()
{
    printf("######################\n");
    printf("pirveli da mesame\n");

    printf("hello,\t");    // \t for tab
    printf("wo\crld \bT"); // \b for r backspace
    printf("\n");

    printf("######################\n");
    printf("char size: %lu bytes\n", sizeof(char));
    printf("int size: %lu bytes\n", sizeof(int));
    printf("short size: %lu bytes\n", sizeof(short));
    printf("long size: %lu bytes\n", sizeof(long));
    printf("float size: %lu bytes\n", sizeof(float));
    printf("double size: %lu bytes\n", sizeof(double));
    printf("long double size: %lu bytes\n", sizeof(long double));

    printf("######################\n");
    printf("unsigned long size: %lu\n", sizeof(unsigned long));
    // რატომ ვიღებ ლონგის სიგრძეს 4-ს? 4bytes for 32 bit OS?


    printf("######################\n");
    unsigned char j = 255;
    j = j + 10;
    printf("%u \n", j); // 9 // გადაივსო


    printf("######################\n");
    // const int AGE = 19;
    #define AGE 29

    printf("AGE is %lu\n",AGE);

    // AGE = 30;

    printf("AGE is %lu\n",AGE);


    printf("######################\n");
    int a = 2;
    int b;
    b = a++; /* b is 2, a is 3 */
    b = ++a; /* b is 4, a is 4 */


    printf("######################\n");
    // The ternary operator
    int k = 0;
    int g = 2;
    int c = 3;
    k ? printf("g = %d\n",g) : printf("c = %d\n",c);


    printf("######################\n");
    int m = 7;
    switch (m)
    {
        case 0:
          /* do something */
          printf("case 0\n");
          break;
        case 1:
          /* do something else */
          printf("case 1\n");
          break;
        case 2:
          /* do something else */
          printf("case 2\n");
          break;
        default:
          /* handle all the other cases */
          // ვსო მივხდი
          printf("aq ra moxda ver mivxdi. kitxva \n");
          printf("ვსო მივხდი \n");
          break;
    }


    printf("######################\n");
    /*
    While loops are great, but there might be times when
    you need to do one particular thing: you want to
    always execute a block, and then maybe repeat it
    This is done using the do while keyword, in a way
    that's very similar to a while loop, but slightly
    different:
    */
    int i = 0;
    do
    {
        /* do something */
        printf("i = %d\n",i);

        i++;
    } while (i < 10);

    printf("######################\n");
    float cxra = 9;
    float xuti = 5;
    float ganayofi;

    ganayofi = xuti / cxra;
    printf("ganayofi %f\n",ganayofi);

    printf("######################\n");
    int ati = 5;
    int ori = 9;
    int ganayofi2;

    ganayofi2 = ati / ori;
    printf("ganayofi2 int 5 / int 9 ze aris %d\n",ganayofi2);

    return 0;
}
