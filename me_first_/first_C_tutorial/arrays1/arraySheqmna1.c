// arrays declaration and initialization

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var[3] = {3,6,9};
    int * myarray;
    myarray = &var;
    
    printf("&var = %d\n",&var);
    
    for(int i =0; i<(sizeof(var)/sizeof(var[0])); i++)
    {
        // address stored in pointer variable
        // access the value using the pointer
        printf("Address stored in myarray: %x\n", myarray);
        printf("Value of *myarray: %d\n", *myarray);
        printf("Sizeof of *myarray: %d\n", sizeof(*myarray));
    }

    
    return 0;
}













