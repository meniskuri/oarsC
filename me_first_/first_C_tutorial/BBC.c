#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------------------------
typedef unsigned char *byte_pointer;

/*show bytes takes byte pointer as an argument
  and prints memory contents from byte_pointer
  to byte_pointer + len */

void show_bytes(byte_pointer start, int len)
{
     int i;
     for (i = 0; i < len; i++)
           printf(" %.2x", start[i]);
     printf("\n");
}

void show_int(int x)
{
     show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(double x) 
{
     show_bytes((byte_pointer) &x, sizeof(double));
}

//----------------------------------------------------------------------------------

int main(void){
    //----------------------------------------------------------------------------------
    float a,b;
    int   n;

    printf("sheviyvanot klaviaturidan rame brzaneba: \n");
    scanf("%d%f",&n,&a);
    b = n + a;
    printf("n aris%d\na aris %f\nn+a = %f\n",n,a,b);
    
    int k     = 1;
    void *gio = &k;
    
    show_int(n);
    show_float(b);
    
    printf("aq ra xdeba? %d\n",*(int*)gio);
    printf("int is zoma %d\n",sizeof(int));
    printf("                          \n");

    return 0;
}
