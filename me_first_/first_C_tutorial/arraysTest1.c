//Arrays - TEST
#include <stdio.h>
#include <stdlib.h>

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
  
void show_pointer(void *x) 
{
     show_bytes((byte_pointer) &x, sizeof(void *));
}
  


int main()
{
    int *SIZE        = 3; // malloc() - ით უნდა ვცადო 
    
    // TESTING malloc ||||||||||||||||||||||||||||||||||||||||||||||
    int array_length = 1;
    int *array       = (int*) malloc(array_length * sizeof(int));
    
    printf("array = %d\n",*array); //  *13241440 and 14043048
    printf("sizeof = %d\n",sizeof(*array));
    
    // from code > firstMalloc.c 
    char *str;
      // Initial memory allocation 
    str = (char *) malloc(21);
    strcpy(str, "abastumaniobservatory");
    printf("String = %s,  Address = %u\n", str, str);
      // Reallocating memory 
    str = (char *) realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s,  Address = %u\n", str, str);

    free(str);
    
    // pointers ||||||||||||||||||||||||||||||||||||||||||||||
    int  var1;
    char var2[10];

    printf("Address of var1 variable: %x\n", &var1);
    printf("Address of var2 variable: %x\n", &var2);
    
    int *var_pointer1; // pointer ის შექმნა  / pointer variable declaration /
    var_pointer1 = SIZE;
    // printf("Value of *var-pointer1 variable: %d\n", *var_pointer1);
    
    
    
    // >>>>>> 
    
    char ucnauri,vin,movlena;
    char gamortva  = "Q";    // <<<<< აქ რა ხდება?    
    // ეს მეცვლება სულ ))))  ესეთ ვორნინგს მიწერს: 
    //  warning: initialization of 'char' from 'char *' makes integer
    //  from pointer without a cast [-Wint-conversion]
    //  char gamortva  = "Q";     // <<<< =====  01;35m^~~
    
    // printf("MasivIntsize = %d\n",SIZE); // <<<
    
    int masiviIntebis[3] = {2,5,6}; // SIZE pointer ითაც ვერ ჩავსვი 
    
    printf("gamosvlistvis daweret -> J \n"); 
    
    while(1)
    {
        printf("while\n");
        
        printf("enter => 'ucnauri', 'vin' da 'movlena'");
        scanf("%c%c%c",&ucnauri,&vin,&movlena); 
    
        printf("ucnauria {%c} is rom {%c} vart da rogor damtavrdeba {%c} es?\n",ucnauri,vin,movlena);
        
        printf("gamortva ---> %c and sizeof(gamortva)--> %d\n",gamortva,sizeof(gamortva));
        printf("ucnauri ---> %c and sizeof(ucnauri)--> %d\n",ucnauri,sizeof(ucnauri));
        printf("vin ---> %c and sizeof(vin)-- > %d\n",vin,sizeof(vin));
        printf("movlena ---> %c and sizeof(movlena)--> %d\n",movlena,sizeof(movlena));
        
        if(ucnauri == gamortva || vin == gamortva || movlena == gamortva)
        {   
            printf("break - shi shemovedi\n");
            break;
            
        } else
        {
            printf("giorgi chkviania \n");
        }
    }
    
    printf("sizeof(masiviIntebis) = (bites)%d\n",sizeof(masiviIntebis));
    
    for (int i = 0; i < (sizeof(masiviIntebis)/sizeof(masiviIntebis[0])); i++) // sizeof() ბაიტების რაოდენობას აბრუნეს
    {
        printf("masiviIntebis %d\n",masiviIntebis[i]);
        printf("memory read : "), show_int(masiviIntebis[i]); // memory read // დასახვეწია 
    }
 
    return 0;    
}




